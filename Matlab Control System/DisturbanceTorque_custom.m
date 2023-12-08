function [gravity, solar, aero, total] = DisturbanceTorque_custom() 
    % This function returns the maximum expected disturbance torques as scalars
    % Migrated from ADCS_MODEL_2_0.py by Milan Capoor on 2023-11-20 @ 19:30

    % Inputs: 
    %         
    % Outputs: 4x1 vector of scalar torque values in Nm

    gravity = GravityGradientTorque(seconds_per_orbit, inertia_z, inertia_xy);
    solar = SolarTorque();
    aero = AerodynamicTorque();
    total = gravity + solar + aero; 
end

function gravity = GravityGradientTorque(seconds_per_orbit, inertia_z, inertia_xy) 
    gravity = 3 * (inertia_z - inertia_xy) *  (2 * pi / seconds_per_orbit)^3;
end

function solar = SolarTorque(angle_incidence_to_sun, center_solar_pressure, center_gravity, satellite_largest_surface_area, satellite_reflection_factor)
    SOLAR_CONSTANT = 1367;              %W/m2 (solar radiation flux constant)
    SPEED_OF_LIGHT = 3 * 10^8;          % m/s

    pressure_differential = center_solar_pressure - center_gravity; 
    F = (SOLAR_CONSTANT / SPEED_OF_LIGHT) * satellite_largest_surface_area * (1 + satellite_reflection_factor) * cos(angle_incidence_to_sun);

    solar = F * pressure_differential; 
end

function aero = AerodynamicTorque(altitude, satellite_drag_coefficient, satellite_largest_surface_area, satellite_velocity, center_aerodynamic_pressure, center_gravity)
    rho = AtmosphericDensity(altitude); %kg/m3

    F = 0.5 * rho * satellite_drag_coefficient * satellite_largest_surface_area * satellite_velocity^2;
    pressure_differential = center_aerodynamic_pressure - center_gravity;

    aero = F * pressure_differential;
end



