CREATE DATABASE veh_data;
ALTER USER postgres PASSWORD 'password';
CREATE EXTENSION IF NOT EXISTS timescaledb CASCADE;
CREATE TABLE veh_data (
    time            TIMESTAMP NOT NULL,
    speed_mps       NUMERIC,
    yawrate_radps   NUMERIC,
    rwa_rad         NUMERIC,
    lat_deg         NUMERIC,
    long_deg        NUMERIC,
    heading_deg     NUMERIC
);
SELECT create_hypertable('veh_data', 'time');
