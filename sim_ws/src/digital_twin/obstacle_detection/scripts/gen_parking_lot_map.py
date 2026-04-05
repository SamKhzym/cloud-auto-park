'''
Note: using the following coordinate system to create the parking lots.
Skew is considered clockwise as positive, with 0deg facing directly up. (-y)

     +----------------+
     |                |
  +y |      *         |
  ^  |                |
  |  |                |
  |  +----------------+
(0,0) ----> +x

'''

import matplotlib.pyplot as plt
import matplotlib.patches as patches
from typing import List
import math
from pathlib import Path
import numpy as np
import cv2
import matplotlib as mpl
import yaml

mpl.rcParams['savefig.pad_inches'] = 0

F1TENTH_GYM_NODE_BASE = Path(__file__).parents[3] / 'f1tenth_gym_ros'
print(F1TENTH_GYM_NODE_BASE)
MAP_PATH = F1TENTH_GYM_NODE_BASE / 'maps'

# sim length to actual length
RATIO = 0.966 / 2.0
ORIGIN = [3, 2, 0.000000]

class ParkedActor:
    
    def __init__(
        self,
        width_m: float,
        length_m: float,
        long_offset_from_line_m: float = 0.0,
        lat_offset_from_center_m: float = 0.0,
        skew_offset_deg: float = 0.0
    ):
        self.width_m = width_m
        self.length_m = length_m
        self.long_offset_from_line_m = long_offset_from_line_m
        self.lat_offset_from_center_m = lat_offset_from_center_m
        self.skew_offset_deg = skew_offset_deg

class ParkingLotRow:
    
    def __init__(
        self,
        x_coord_m: float,
        y_coord_m: float,
        num_spots: int,
        spot_skew_deg: float = 0.0,
        spot_width_m: float = 2.7,
        spot_length_m: float = 5.4,
        spot_separation_m: float = 0.1016
    ):
        
        # parameters configuring geometry of parking spaces
        self.x_coord_m = x_coord_m
        self.y_coord_m = y_coord_m
        self.num_spots = num_spots
        self.spot_skew_deg = spot_skew_deg
        self.spot_width_m = spot_width_m
        self.spot_length_m = spot_length_m
        self.spot_separation_m = spot_separation_m
        self.actor_centroids = []
        
        # occupancy map that contains actors
        self.occupancy_map: List[None | ParkedActor] = [None for _ in range(self.num_spots)]
        
    def set_actor_in_parking_space(
        self, 
        actor: ParkedActor,
        parking_spot_index: int
    ):
        self.occupancy_map[parking_spot_index] = actor
        
    def get_horizontal_spot_spacing(self):
        
        # saturate terms to prevent div by 0 errors
        cos_term = max(0.0001, math.cos(math.radians(self.spot_skew_deg)))
        sin_term = max(0.0001, math.sin(math.radians(self.spot_skew_deg)))
        x_spacing = min(self.spot_width_m / cos_term, self.spot_length_m / sin_term)
        return x_spacing
        
    def draw_parking_lot(self):
        
        # create matplotlib figure
        fig = plt.figure()
        ax = plt.axes([0,0,1,1], frameon=False)
        
        for idx in range(self.num_spots):
            
            # create light gray rectangle shading for parking spaces
            x_spacing = self.get_horizontal_spot_spacing()
            x1_m = self.x_coord_m + x_spacing * idx
            rect_patch = patches.Rectangle(
                (x1_m, self.y_coord_m), 
                self.spot_width_m, 
                self.spot_length_m, 
                angle=self.spot_skew_deg, 
                rotation_point='xy',
                color='silver',
                edgecolor='black',
                linewidth=1,
                fill=None
            )
            ax.add_patch(rect_patch)
            
            # create black rectangles for parked objects
            if self.occupancy_map[idx] is not None:
                actor = self.occupancy_map[idx]
                
                dx = (self.spot_width_m / 2) - (actor.width_m / 2) + actor.lat_offset_from_center_m
                dy = self.spot_length_m - actor.length_m - actor.long_offset_from_line_m
                
                theta = math.radians(self.spot_skew_deg)
                dx_prime = dx * math.cos(theta) - dy * math.sin(theta)
                dy_prime = dx * math.sin(theta) + dy * math.cos(theta)
                
                rect_patch = patches.Rectangle(
                    (x1_m + dx_prime, self.y_coord_m + dy_prime), 
                    # (x1_m, self.y_coord_m),
                    actor.width_m, 
                    actor.length_m, 
                    angle=(self.spot_skew_deg + actor.skew_offset_deg), 
                    rotation_point='xy',
                    facecolor='grey',
                    edgecolor='black',
                    linewidth=2,
                    zorder=999
                )
                
                centroid = list(np.mean(np.array(rect_patch.get_corners()), axis=0))
                self.actor_centroids.append([centroid[0], centroid[1], self.spot_skew_deg + actor.skew_offset_deg])
                print('actor centroid:', centroid)
                
            ax.add_patch(rect_patch)
            
        ax.set_xlim(0, 20)
        ax.set_ylim(0, 20)
        ax.set_frame_on(False) # Removes the frame
        ax.get_xaxis().set_visible(False)
        ax.get_yaxis().set_visible(False)

        
        plt.axis('off')
        fig.set_size_inches(10/RATIO, 10/RATIO)
        # fig.set_tight_layout(True)
        
        fig.canvas.draw()

        # save data to numpy array, convert to single-channel grayscale image
        data = np.frombuffer(fig.canvas.tostring_rgb(), dtype=np.uint8)
        data = data.reshape(fig.canvas.get_width_height()[::-1] + (3,))
        data = np.mean(data, axis=2)
        
        # save image to file
        cv2.imwrite(f'{MAP_PATH.absolute()}/my_custom_map.png',data)
        
    def write_yaml_file(self, filename):
        path = f'{MAP_PATH.absolute()}/my_custom_map.yaml'
        
        actor_centroid_array = []
        for centroid in self.actor_centroids:
            actor_centroid_array.append({'x': float(centroid[0]), 'y': float(centroid[1]), 'theta': float(centroid[2])})
        
        yaml_info = {
            'image': f'{filename}.png',
            'resolution': 0.01,
            'origin': list(ORIGIN),
            'negate': 0,
            'occupied_thresh': 0.6,
            'free_thresh': 0.196,
            'actors': list(actor_centroid_array)
        }
        
        with open(path, 'w') as f:
            yaml.dump(yaml_info, f)
        
p = ParkingLotRow(0, 0, 4, 0.0, spot_width_m=0.54, spot_length_m=1.08)
p.set_actor_in_parking_space(ParkedActor(0.40, 0.7, 0.1, 0.0, 0.0), 1)
p.set_actor_in_parking_space(ParkedActor(0.40, 0.7, 0.1, 0.0, 0.0), 3)
p.draw_parking_lot()
p.write_yaml_file('my_custom_map')
