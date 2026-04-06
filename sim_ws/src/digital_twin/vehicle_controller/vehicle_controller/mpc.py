from dataclasses import dataclass
import matplotlib.pyplot as plt
import math
import numpy as np
from scipy.interpolate import CubicSpline
from scipy import interpolate
from copy import deepcopy
from scipy.optimize import minimize

CONTROLLER_SAMPLETIME_S = 0.02

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
        self.headingErrorGain = 0.001
        self.reset()
        
    def reset(self):
        self.timestep = 0
        self.curr_state = np.array([[0.0], [0.0]])
        self.curr_pose = np.array([[0.0], [0.0], [0.0]])
        
    def set_path(self, path, curvatures):
        self.path = path
        self.curvatures = curvatures
        self.last_timestep = len(self.curvatures)
        self.reset()
        
    def get_a_b(self, vx_mps):
    
        vx_mps = max(vx_mps, 0.000001)
        cf_Nprad = self.params.cf_Nprad
        cr_Nprad = self.params.cr_Nprad
        mass_kg = self.params.mass_kg
        lf_m = self.params.lf_m
        lr_m = self.params.lr_m
        izz_kgm2 = self.params.izz_kgm2
        
        A = np.array([
            [ -(cf_Nprad + cr_Nprad) / (mass_kg * vx_mps), (cr_Nprad*lr_m - cf_Nprad*lf_m)/(mass_kg * vx_mps) - vx_mps ],
            [ (lr_m*cr_Nprad - lf_m*cf_Nprad) / (izz_kgm2*vx_mps), -(lf_m * lf_m * cf_Nprad + lr_m * lr_m * cr_Nprad)/(izz_kgm2*vx_mps) ]
        ])
        B = np.array([
            [cf_Nprad/mass_kg],
            [cf_Nprad*lf_m/izz_kgm2]
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
        
        for i in range(N):
            simulated_state, simulated_pose = self.step_simulation(simulated_state, simulated_pose, deltas[i])
            
            # save intermediates for cost function
            xs[i] = simulated_pose[0]
            ys[i] = simulated_pose[1]
            
        return xs, ys
        
    def cost_function(self, desired_x, desired_y, actual_x, actual_y, deltas):
        REGULARIZATION_PENALTY = 0.0007
        squared_path_cost = np.sum(np.square(desired_x - actual_x) + np.square(desired_y - actual_y))
        regularization_cost = np.linalg.norm(deltas)
        # print('squared path:', squared_path_cost, '| regularization', regularization_cost)
        total_cost = squared_path_cost + REGULARIZATION_PENALTY * regularization_cost
        return total_cost
    
    def simulate_and_get_cost(self, deltas):
        N = len(deltas)
        xs, ys = self.simulate_over_horizon(deltas)
        return self.cost_function(self.path[0][self.timestep:self.timestep+N], self.path[1][self.timestep:self.timestep+N], xs, ys, deltas)
    
    def get_init_feedforward_deltas(self, curvatures):
    
        vx_mps = max(self.speed_mps, 0.000001)
        cf_Nprad = self.params.cf_Nprad
        cr_Nprad = self.params.cr_Nprad
        mass_kg = self.params.mass_kg
        lf_m = self.params.lf_m
        lr_m = self.params.lr_m
        izz_kgm2 = self.params.izz_kgm2
        
        kus = (mass_kg / (lf_m + lr_m)) * ((lr_m / cf_Nprad) - (lf_m / cr_Nprad))
        delta_ff = curvatures * ((lf_m + lr_m + kus * vx_mps * vx_mps) + self.headingErrorGain * ((mass_kg * vx_mps * vx_mps * lf_m) / (cr_Nprad * (lf_m + lr_m)) - lr_m))
        
        return delta_ff
        
    def step(self):
        
        # Get horizon length
        init_ts = self.timestep
        final_ts = min(self.timestep + self.horizon, self.last_timestep)
        num_steps = final_ts - init_ts
        
        # Solve MPC optimization problem
        delta_init = self.get_init_feedforward_deltas(self.curvatures[init_ts:final_ts]) # initial guess for control signal
        bounds = [(-0.5, 0.5)] * num_steps
        result = minimize(self.simulate_and_get_cost, delta_init, method='SLSQP', bounds=bounds) # optimization
        
        # increment controller timestep
        self.timestep += 1
        
        # return first rwa in horizon
        curr_delta = result.x[0]
        
        # update simulated current state and vehicle pose (use to get an estimate for vy since that's not measured)
        self.step_simulation(self.curr_state, self.curr_pose, curr_delta)
        
        return curr_delta
        
    def set_curr_state(self, curr_state):
        self.curr_state = curr_state
    
    def set_curr_pose(self, curr_pose):
        # print('curr pose', curr_pose)
        self.curr_pose = curr_pose
        
