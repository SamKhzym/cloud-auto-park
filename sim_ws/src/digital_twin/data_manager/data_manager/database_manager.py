import psycopg2, time
import psycopg2.extras
from typing import List

class DatabaseManager:
    
    def __init__(self, buffer_length=1000):
        self.connection = psycopg2.connect(database="veh_data", user='postgres', password='password', host="localhost", port=5432)
        self.odom_buffer = []
        self.drive_data_buffer = []
        self.buffer_length = buffer_length
        
    def buffer_odom_data(self, timestamp_s: float, speed_mps: float, yawrate_radps: float, gps_lat_deg: float, gps_long_deg: float):
        new_tuple = (timestamp_s, speed_mps, yawrate_radps, gps_lat_deg, gps_long_deg)
        self.odom_buffer.append(new_tuple)
        if len(self.odom_buffer) >= self.buffer_length:
            self.write_odom_data()
        
    def write_odom_data(self):
        
        # database schema: (timestamp, speed, yawrate, rwa, lat, long)
        # SQL template with placeholders. 
        # We use 'to_timestamp(%s)' for the first column and hardcode NULL for the 4th.
        insert_query = """
            INSERT INTO veh_data (time, speed_mps, yawrate_radps, rwa_rad, lat_deg, long_deg)
            VALUES %s
        """
        
        # The template for an individual row within the VALUES list
        # %s is used for the parameters we provide in the tuple
        template = "(to_timestamp(%s), %s, %s, NULL, %s, %s)"

        try:
            with self.connection.cursor() as cur:
                psycopg2.extras.execute_values(cur, insert_query, self.odom_buffer, template=template)
                self.connection.commit()
                print(f"Successfully inserted {len(self.odom_buffer)} rows.")
            self.odom_buffer.clear()
        except Exception as e:
            self.connection.rollback()
            print(f"An error occurred: {e}")
            raise
        
    def buffer_drive_data(self, timestamp_s: float, rwa_rad: float):
        new_tuple = (timestamp_s, rwa_rad)
        self.drive_data_buffer.append(new_tuple)
        if len(self.drive_data_buffer) >= self.buffer_length:
            self.write_drive_data()
        
    def write_drive_data(self):
        
        # database schema: (timestamp, speed, yawrate, rwa, lat, long)
        # SQL template with placeholders. 
        # We use 'to_timestamp(%s)' for the first column and hardcode NULL for all values but the 4th.
        insert_query = """
            INSERT INTO veh_data (time, speed_mps, yawrate_radps, rwa_rad, lat_deg, long_deg),
            VALUES %s
        """
        
        # The template for an individual row within the VALUES list
        # %s is used for the parameters we provide in the tuple
        template = "(to_timestamp(%s), NULL, NULL, %s, NULL, NULL)"

        try:
            with self.connection.cursor() as cur:
                psycopg2.extras.execute_values(cur, insert_query, self.drive_data_buffer, template=template)
                self.connection.commit()
                print(f"Successfully inserted {len(self.drive_data_buffer)} rows.")
            self.drive_data_buffer.clear()
        except Exception as e:
            self.connection.rollback()
            print(f"An error occurred: {e}")
            raise
        
    def get_records_from_last_n_seconds(self, timestamp_offset_s=None):
        
        # Execute a SELECT statement
        time_threshold = 0.0
        if timestamp_offset_s is not None:
            time_threshold = time.time() - timestamp_offset_s
        
        with self.connection.cursor() as cur:
            cur.execute(f"SELECT * FROM veh_data WHERE time >= to_timestamp({time_threshold});")
            
            # Fetch all the rows
            records = cur.fetchall()
            
            print(records)
        
if __name__ == '__main__':
    print('test record insertions...')
    dm = DatabaseManager()
    dm.buffer_odom_data(time.time(), 10.0, 1.0, 100.0, -20.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 200.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 300.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 400.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 500.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 600.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 700.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 800.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 900.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 1000.0, -23.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 200.0, -24.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 200.0, -25.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 200.0, -26.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 200.0, -27.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 200.0, -28.0)
    dm.buffer_odom_data(time.time(), 12.0, 2.0, 200.0, -29.0)
    dm.get_records_from_last_n_seconds()
    print('done!')
