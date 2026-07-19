from dataclasses import dataclass
import matplotlib.pyplot as plt
import math
import numpy as np
from scipy.interpolate import CubicSpline
from scipy import interpolate
from copy import deepcopy
from scipy.optimize import minimize

CONTROLLER_SAMPLETIME_S = 0.02
MIN_SPEED = 0.001

@dataclass
class VehicleBicycleModelParams:
    cf_Nprad: float = 0.0
    cr_Nprad: float = 0.0
    mass_kg: float = 0.0
    lf_m: float = 0.0
    lr_m: float = 0.0
    izz_kgm2: float = 0.0

class MpcController:
    
    def __init__(self, params: VehicleBicycleModelParams, horizon: int = 10, speed_mps: float = 1.0, sample_time_hz: float = 50):
        self.sample_time_hz = sample_time_hz
        self.sample_time_s = (1 / self.sample_time_hz)
        self.timestep = 0
        self.params = params
        self.speed_mps = speed_mps
        self.horizon = horizon
        self.A, self.B = self.get_a_b(speed_mps)
        self.curr_state = np.array([[0.0], [0.0]])
        self.curr_pose = np.array([[0.0], [0.0], [0.0]])
        self.last_timestep = 0
        self.path = np.array([[], []])
        self.curvatures = np.array([])
        self.reset()
        
    def reset(self):
        self.timestep = 0
        self.curr_state = np.array([[0.0], [0.0]])
        self.curr_pose = np.array([[0.0], [0.0], [0.0]])
        self.last_delta = 0.0
        
    def set_path(self, path, headings, curvatures):
        self.path = path
        self.headings = headings
        self.curvatures = curvatures
        self.last_timestep = len(self.curvatures)
        self.reset()
        
    def get_a_b(self, vx_mps):
    
        if vx_mps >= 0: vx_mps = max(vx_mps, MIN_SPEED)
        else: vx_mps = min(vx_mps, -1*MIN_SPEED)
        abs_vx = abs(vx_mps)
        cf_Nprad = self.params.cf_Nprad
        cr_Nprad = self.params.cr_Nprad
        mass_kg = self.params.mass_kg
        lf_m = self.params.lf_m
        lr_m = self.params.lr_m
        izz_kgm2 = self.params.izz_kgm2
        
        A = np.array([
            [ -(cf_Nprad + cr_Nprad) / (mass_kg * abs_vx), (cr_Nprad*lr_m - cf_Nprad*lf_m)/(mass_kg * abs_vx) - vx_mps ],
            [ (lr_m*cr_Nprad - lf_m*cf_Nprad) / (izz_kgm2*abs_vx), -(lf_m * lf_m * cf_Nprad + lr_m * lr_m * cr_Nprad)/(izz_kgm2*abs_vx) ]
        ])
        B = np.array([
            [(cf_Nprad*vx_mps)/(mass_kg*abs_vx)],
            [(cf_Nprad*lf_m*vx_mps)/(izz_kgm2*abs_vx)]
        ])
    
        return A, B
    
    def step_simulation(self, state, pose, delta):
        state_dot = self.A @ state + self.B * delta
        state += state_dot * self.sample_time_s
        
        # get vx, vy, yaw rate, and update ego pose
        vx = self.speed_mps
        vy = state[0]
        yaw_rate = state[1]
        yaw = pose[2]
        
        vx_prime = vx*np.cos(yaw) - vy*np.sin(yaw)
        vy_prime = vx*np.sin(yaw) + vy*np.cos(yaw)
        
        pose_dot = np.array([vx_prime, vy_prime, yaw_rate])
        
        # print('mpc pose dot', pose_dot)
        # print('=======')
        # print('mpc pose', pose)
        
        pose += pose_dot * self.sample_time_s
        
        return state, pose
    
    def simulate_over_horizon(self, deltas):
        
        # using forward euler, may need to make this rk4 later
        simulated_state = self.curr_state.copy()
        simulated_pose = self.curr_pose.copy()
        
        N = len(deltas)
        
        xs = np.zeros(N)
        ys = np.zeros(N)
        thetas = np.zeros(N)
        omegas = np.zeros(N)
        
        for i in range(N):
            simulated_state, simulated_pose = self.step_simulation(simulated_state, simulated_pose, deltas[i])
            
            # save intermediates for cost function
            xs[i] = simulated_pose[0]
            ys[i] = simulated_pose[1]
            thetas[i] = simulated_pose[2]
            omegas[i] = simulated_state[1]
            
        return xs, ys, thetas, omegas
        
    def cost_function(self, desired_x, desired_y, desired_theta, desired_curvs, actual_x, actual_y, actual_theta, actual_omegas, deltas):
        
        def normalize_angles(angles):
            return (angles + np.pi) % (2 * np.pi) - np.pi

        # horizon length
        H = len(deltas)
        
        # MSE vehicle path term
        w_path = 5.0
        max_mse_path = 0.1 #m
        mse_path = (np.sum(np.square(desired_x - actual_x) + np.square(desired_y - actual_y))) / H
        
        # MSE heading term
        w_heading = 0.7
        max_mse_heading = 0.174 #rad
        desired_theta = normalize_angles(desired_theta)
        actual_theta = normalize_angles(actual_theta)
        mse_heading = np.sum(np.square(desired_theta - actual_theta)) / H
        
        # MSE yaw rate
        w_yawrate = 0.1
        max_mse_yawrate = 0.174 # rad/s
        dersired_omegas = desired_curvs * self.speed_mps
        mse_yawrate = np.sum(np.square(dersired_omegas - actual_omegas)) / H
        
        # MSE effort term
        w_effort = 0.000005
        max_mse_effort = 0.174 #rad
        mse_effort = np.sum(np.square(deltas - self.delta_ff)) / H
        
        # MSE of delta derivative term
        w_delta_dot = 0.00005
        max_mse_delta_dot = 0.174 #rad/s
        deltas_dot = np.diff(deltas, prepend=self.last_delta) / self.sample_time_s
        mse_delta_dot = np.sum(np.square(deltas_dot)) / H
        
        # normalize costs
        norm_mse_path = mse_path / max_mse_path
        norm_mse_heading = mse_heading / max_mse_heading
        norm_mse_yawrate = mse_yawrate / max_mse_yawrate
        norm_mse_effort = mse_effort / max_mse_effort
        norm_mse_delta_dot = mse_delta_dot / max_mse_delta_dot
        
        # total cost
        print(f"""MSE path: {norm_mse_path:.5f}, \
              | MSE heading: {norm_mse_heading:.5f} \
              | MSE yawrate: {norm_mse_yawrate:.5f} \
              | MSE effort: {norm_mse_effort:.5f} \
              | MSE delta dot: {norm_mse_delta_dot:.5f}""")
        total_cost = w_path * norm_mse_path + w_heading * norm_mse_heading + w_yawrate * norm_mse_yawrate + w_effort * norm_mse_effort + w_delta_dot * norm_mse_delta_dot
        return total_cost
    
    def simulate_and_get_cost(self, deltas):
        N = len(deltas)
        xs, ys, thetas, omegas = self.simulate_over_horizon(deltas)
        return self.cost_function(
            self.path[0][self.timestep:self.timestep+N], # x values from trajectory over horizon
            self.path[1][self.timestep:self.timestep+N], # y values from trajectory over horizon
            self.headings[self.timestep:self.timestep+N], # theta values from trajectory over horizon
            self.curvatures[self.timestep:self.timestep+N], # theta values from trajectory over horizon
            xs, # x values from simulated vbm over horizon
            ys, # y values from simulated vbm over horizon
            thetas, # theta values from simulated vbm over horizon
            omegas,
            deltas # control actions (rwas)
        )
    
    def get_init_feedforward_deltas(self, curvatures):
    
        if self.speed_mps >= 0: vx_mps = max(self.speed_mps, MIN_SPEED)
        else: vx_mps = min(self.speed_mps, -1*MIN_SPEED)
        cf_Nprad = self.params.cf_Nprad
        cr_Nprad = self.params.cr_Nprad
        mass_kg = self.params.mass_kg
        lf_m = self.params.lf_m
        lr_m = self.params.lr_m
        
        delta_ff = curvatures * ((lf_m + lr_m) + (mass_kg / (lf_m + lr_m))*(lr_m/(cf_Nprad) - lf_m/(cr_Nprad))*(vx_mps)*(vx_mps))
        
        return delta_ff
        
    def step(self):
        
        # Get horizon length
        init_ts = self.timestep
        final_ts = min(self.timestep + self.horizon, self.last_timestep)
        num_steps = final_ts - init_ts
        
        # Solve MPC optimization problem
        delta_init = self.get_init_feedforward_deltas(self.curvatures[init_ts:final_ts]) # initial guess for control signal
        self.delta_ff = delta_init
        # print(self.delta_ff)
        bounds = [(-0.3, 0.3)] * num_steps
        result = minimize(self.simulate_and_get_cost, delta_init, method='SLSQP', bounds=bounds) # optimization
        
        # increment controller timestep
        self.timestep += 1
        
        # return first rwa in horizon
        curr_delta = result.x[0]
        self.last_delta = curr_delta
        
        # update simulated current state and vehicle pose (use to get an estimate for vy since that's not measured)
        self.step_simulation(self.curr_state, self.curr_pose, curr_delta)
        
        return curr_delta
        
    def set_curr_state(self, curr_state):
        self.curr_state = curr_state.copy()
    
    def set_curr_pose(self, curr_pose):
        # print('curr pose', curr_pose)
        self.curr_pose = curr_pose.copy()
        
