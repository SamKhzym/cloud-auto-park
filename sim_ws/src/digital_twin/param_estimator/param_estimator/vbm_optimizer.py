from dataclasses import dataclass
from copy import deepcopy
from scipy.optimize import minimize
import numpy as np

MIN_SPEED = 0.01

@dataclass
class VehicleBicycleModelParams:
    cf_Nprad: float = 0.0
    cr_Nprad: float = 0.0
    mass_kg: float = 0.0
    lf_m: float = 0.0
    lr_m: float = 0.0
    izz_kgm2: float = 0.0
    
MIN_SPEED = 0.001

class VehiclePlantModel:
    
    def __init__(self, params: VehicleBicycleModelParams, major_sample_time_s=0.02, sample_time_s=0.005):
        self.params = params
        self.sample_time_s = sample_time_s
        self.major_sample_time_s = major_sample_time_s
        self.curr_state = np.array([[0.0], [0.0]])
        self.curr_pose = np.array([[0.0], [0.0], [0.0]])
        self.states, self.poses = [], []
        self.w_path, self.w_final_drift, self.w_theta, self.w_yawrate = 2.0, 0.1, 1.0, 100.0
        
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
            [ -(cf_Nprad + cr_Nprad) / (mass_kg * abs_vx), (cr_Nprad*lr_m - cf_Nprad*lf_m)/(mass_kg*abs_vx) - vx_mps ],
            [ (lr_m*cr_Nprad - lf_m*cf_Nprad) / (izz_kgm2*abs_vx), -(lf_m * lf_m * cf_Nprad + lr_m * lr_m * cr_Nprad)/(izz_kgm2*abs_vx) ]
        ])
        B = np.array([
            [(cf_Nprad*vx_mps)/(mass_kg*abs_vx)],
            [(cf_Nprad*lf_m*vx_mps)/(abs_vx*izz_kgm2)]
        ])
    
        return A, B
    
    def step_simulation(self, state, pose, delta, speed_mps):
        
        # using forward euler, may need to make this rk4 later
        A, B = self.get_a_b(speed_mps)
        state_dot = A @ state + B * delta
        state += state_dot * self.sample_time_s
        
        # get vx, vy, yaw rate, and update ego pose
        vx = speed_mps
        vy = state[0]
        yaw_rate = state[1]
        yaw = pose[2]
        
        vx_prime = vx*np.cos(yaw) - vy*np.sin(yaw)
        vy_prime = vx*np.sin(yaw) + vy*np.cos(yaw)
        
        pose_dot = np.array([vx_prime, vy_prime, yaw_rate])
        # print('plant pose dot', pose_dot)
        # print('=======')
        # print('plant pose', pose)
        pose += pose_dot * self.sample_time_s
        
        return state, pose
    
    def simulate_over_horizon(self, deltas, speeds_mps):
        
        self.states, self.poses = [], []
        
        N = len(deltas)
        for i in range(N):
            self.curr_state, self.curr_pose = self.step_simulation(self.curr_state, self.curr_pose, deltas[i], speeds_mps[i])
            self.states.append(self.curr_state.copy())
            self.poses.append(self.curr_pose.copy())
    
    def step(self, delta, speed_mps):
        num_timesteps = int(self.major_sample_time_s // self.sample_time_s)
        # print('num timesteps:', num_timesteps)
        deltas = [delta] * num_timesteps
        speeds = [speed_mps] * num_timesteps
        self.simulate_over_horizon(deltas, speeds)
        
    def get_curr_pose(self): return self.curr_pose
    def get_curr_state(self): return self.curr_state

class BicycleModelOptimizer:
    
    def __init__(self, init_vbm_params: VehicleBicycleModelParams, optimize_mass=True, optimize_iz=True):
        self.init_vbm_params = init_vbm_params
        self.vbm_params = deepcopy(init_vbm_params)
        
        # empty data fields for when the optimization happens
        self.times_s = None
        self.rwas_rad = None
        self.speeds_mps = None
        self.xs_actual = None
        self.ys_actual = None
        self.yrs_actual = None
        
        self.optimize_mass = optimize_mass
        self.optimize_iz = optimize_iz
        
    def get_a_b(self, vx_mps):
    
        if vx_mps >= 0: vx_mps = max(vx_mps, MIN_SPEED)
        else: vx_mps = min(vx_mps, -1*MIN_SPEED)
        abs_vx = abs(vx_mps)
        cf_Nprad = self.vbm_params.cf_Nprad
        cr_Nprad = self.vbm_params.cr_Nprad
        mass_kg = self.vbm_params.mass_kg
        lf_m = self.vbm_params.lf_m
        lr_m = self.vbm_params.lr_m
        izz_kgm2 = self.vbm_params.izz_kgm2
        
        A = np.array([
            [ -(cf_Nprad + cr_Nprad) / (mass_kg * abs_vx), (cr_Nprad*lr_m - cf_Nprad*lf_m)/(mass_kg * abs_vx) - vx_mps ],
            [ (lr_m*cr_Nprad - lf_m*cf_Nprad) / (izz_kgm2*abs_vx), -(lf_m * lf_m * cf_Nprad + lr_m * lr_m * cr_Nprad)/(izz_kgm2*abs_vx) ]
        ])
        B = np.array([
            [(cf_Nprad*vx_mps)/(mass_kg*abs_vx)],
            [(cf_Nprad*lf_m*vx_mps)/(izz_kgm2*abs_vx)]
        ])
    
        return A, B
    
    def simulate_vbm(self, times_s, rwas_rad, speeds_mps):
        
        N = len(speeds_mps)
        dts = np.diff(times_s)
        state = np.array([[0.0],[0.0]]) # [vy, yaw_rate]'
        yaws_pred = np.zeros(N)
        xs_pred = np.zeros(N)
        ys_pred = np.zeros(N)
        yaw_rates_pred = np.zeros(N)
        ay_pred = np.zeros(N)
        
        for i in range(0, N-1):
        
            vx = speeds_mps[i]
            
            # get bm equations and step bm forward a timestep
            A, B = self.get_a_b(vx)
            state_dot = A @ state + B * rwas_rad[i]
            state += state_dot * dts[i]
            
            # get vx, vy, yaw rate, and update ego pose
            vy = state[0]
            yaw_rate = state[1]
            x_last = xs_pred[i]
            y_last = ys_pred[i]
            yaw_last = yaws_pred[i]
            
            dx = vx * dts[i]
            dy = vy * dts[i]
            dyaw = yaw_rate * dts[i]
            
            dx_prime = dx*np.cos(yaw_last) - dy*np.sin(yaw_last)
            dy_prime = dx*np.sin(yaw_last) + dy*np.cos(yaw_last)
            
            xs_pred[i+1] = x_last + dx_prime
            ys_pred[i+1] = y_last + dy_prime
            yaws_pred[i+1] = yaw_last + dyaw
            yaw_rates_pred[i+1] = yaw_rate
            ay_pred[i+1] = state_dot[0] + vx*yaw_rate
            
        return xs_pred, ys_pred, yaws_pred, yaw_rates_pred, ay_pred
    
    # THIS IS THE COST FUNCTION AND I CAN CHANGE MY WEIGHTS HERE :)))))
    def cost_function(self, actual_x, actual_y, actual_yr, actual_theta, predicted_x, predicted_y, predicted_yr, predicted_theta):
        
        w_path = self.w_path
        max_mse_path = 10.0
        mse_path = np.mean(np.square(actual_x.flatten() - predicted_x.flatten()) + np.square(actual_y.flatten() - predicted_y.flatten()))
        
        w_theta = self.w_theta
        max_mse_theta = 0.1
        mse_theta = np.mean(np.square(actual_theta.flatten() - predicted_theta.flatten()))
        
        w_yawrate = self.w_yawrate
        max_mse_yawrate = 0.1
        mse_yawrate = np.mean(np.square(actual_yr.flatten() - predicted_yr.flatten()))
        
        # print(f'MSE path: {mse_path:.2f}, MSE heading: {mse_theta:.2f}, MSE yaw rate: {mse_yawrate:.2f}')
        
        cost = w_path * (mse_path / max_mse_path) + w_theta * (mse_theta / max_mse_theta) + w_yawrate * (mse_yawrate / max_mse_yawrate)        
        return cost
    
    def simulate_and_get_cost(self, param_scalars):
        
        # update vbm params with newest guess
        self.vbm_params.cf_Nprad = param_scalars[0] * self.init_vbm_params.cf_Nprad
        self.vbm_params.cr_Nprad = param_scalars[1] * self.init_vbm_params.cr_Nprad
        if self.optimize_iz:
            self.vbm_params.izz_kgm2 = param_scalars[2] * self.init_vbm_params.izz_kgm2
        if self.optimize_mass:
            self.vbm_params.mass_kg = param_scalars[3] * self.init_vbm_params.mass_kg  
            
        print('attempt: ' + str(self.vbm_params))
        
        xs_pred, ys_pred, yaws_pred, yaw_rates_pred, ay_pred = self.simulate_vbm(self.times_s, self.rwas_rad, self.speeds_mps)
        cost = self.cost_function(self.xs_actual, self.ys_actual, self.yrs_actual, self.thetas_actual, xs_pred, ys_pred, yaw_rates_pred, yaws_pred)
        
        # print(f'cost is {cost:.10f} for params {self.vbm_params}')
        
        return cost
    
    def optimize_vbm_params(self, times_s, rwas_rad, speeds_mps, xs_actual, ys_actual, yrs_actual, thetas_actual):
        param_scalars = [1, 1, 1]
        param_scalar_bounds = [[0.7, 1.3], [0.7, 1.3], [0.7, 1.3]]
        if self.optimize_iz:
            param_scalars += [1]
            param_scalar_bounds += [[0.7, 1.3]]
        if self.optimize_mass:
            param_scalars += [1]
            param_scalar_bounds += [[0.7, 1.3]]
        
        self.times_s = times_s
        self.rwas_rad = rwas_rad
        self.speeds_mps = speeds_mps
        self.xs_actual = xs_actual
        self.ys_actual = ys_actual
        self.yrs_actual = yrs_actual
        self.thetas_actual = thetas_actual
        
        # == FIRST PASS == #
        self.w_path, self.w_final_drift, self.w_theta, self.w_yawrate = 0.00, 0.0, 1.0, 1.0
        
        solution = minimize(
            self.simulate_and_get_cost,
            param_scalars,
            bounds=param_scalar_bounds,
            method='SLSQP'
        )
        best_param_scalars = solution.x

        self.vbm_params.cf_Nprad = best_param_scalars[0] * self.init_vbm_params.cf_Nprad
        self.vbm_params.cr_Nprad = best_param_scalars[1] * self.init_vbm_params.cr_Nprad
        if self.optimize_iz:
            self.vbm_params.izz_kgm2 = best_param_scalars[2] * self.init_vbm_params.izz_kgm2
        if self.optimize_mass:
            self.vbm_params.mass_kg = best_param_scalars[3] * self.init_vbm_params.mass_kg            
        
        self.init_vbm_params = deepcopy(self.vbm_params)
        
        print('== FIRST PASS DONE ==')
        
        # # == SECOND PASS == #
        # self.w_path, self.w_final_drift, self.w_theta, self.w_yawrate = 10.0, 10.0, 1.0, 1.0
        # param_scalars = [1, 1, 1, 1]
        # param_scalar_bounds = [[0.999, 1.001], [0.999, 1.001], [0.1, 5.0], [0.999, 1.001]]
        
        # solution = minimize(
        #     self.simulate_and_get_cost,
        #     param_scalars,
        #     bounds=param_scalar_bounds,
        #     method='SLSQP'
        # )
        # best_param_scalars = solution.x

        # self.vbm_params.cf_Nprad = best_param_scalars[0] * self.init_vbm_params.cf_Nprad
        # self.vbm_params.cr_Nprad = best_param_scalars[1] * self.init_vbm_params.cr_Nprad
        # self.vbm_params.mass_kg = best_param_scalars[2] * self.init_vbm_params.mass_kg
        # self.vbm_params.izz_kgm2 = best_param_scalars[3] * self.init_vbm_params.izz_kgm2
        
        # print('== SECOND PASS DONE ==')
        
        print(f'best params: {self.vbm_params}')
