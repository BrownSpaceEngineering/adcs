classdef Constants
    %CONSTANTS Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (Constant = true)
        CORE_PERMEABILITY = 100000;           % relative permeability of permalloy
        CORE_DENSITY = 8700;                  % kg/m3
        WIRE_DENSITY = 8930;                  % kg/m3
        WIRE_DIAMETER = 0.000254;             % copper wire 30 AWG in m
        SATELLITE_MASS = 4;                   % kg
        SATELLITE_LENGTH = 0.3;               % m
        SATELLITE_WIDTH = 0.1;                % m
        
        SECONDS_PER_ORBIT = 5574;             % s
        EARTH_BFIELD_EQUATOR = 0.000026;      % Tesla
        EARTH_BFIELD_NORTHPOLE = 0.000048;    % Tesla
    
        WIRE_TEMP_COEFF = 0.00393;            % 1/Celsius
        WIRE_REF_RESISTIVITY = 1.71e-8;       % Ohm*m
        TEMP_REF = 20;                        % Celsius
        MAX_TEMP = 80;                        % Celsius
        MIN_TEMP = -80;                       % Celsius
        MAX_CURRENT = 0.1;                    % A

        MU_0 = 4 * pi * 10^-7;            % H/m
    
        % DISTURBANCE ASSUMTIONS
        ALTITUDE = 400000;                    % m
        EARTH_RADIUS = 6378140;               % m
        EARTH_GRAV_CONSTANT = 3.986 * 10^14; % m3/s2
        SOLAR_CONSTANT = 1367;                % W/m2 (solar radiation flux constant)
        SPEED_OF_LIGHT = 3 * 10^8;           % m/s
        REFLECT_FACTOR = 0.6;                 % reflectance factor of satellite; ranges on [0, 1]
        ATMOSPHERIC_DENSITY = 2.62 * 10^-12; % kg/m3 (mean atmospheric density at 400km)
        DRAG_COEFF = 2.25;                    % drag coefficient of satellite; typ. [2, 2.5]
    end
    properties (Dependent)
        TOTAL_SATELLITE_SURFACE_AREA; %m2
        LARGEST_SURFACE_AREA; %m2
        INERTIA_Z; % long axis
        INERTIA_XY; % short axes
        SEMIMAJOR_AXIS; % m
        SATELLITE_VELOCITY; % m/s approximation
    end
    methods
        function area = get.TOTAL_SATELLITE_SURFACE_AREA(obj)
            area = (4 * obj.SATELLITE_LENGTH * obj.SATELLITE_WIDTH) ...
            + (2 * obj.SATELLITE_WIDTH * obj.SATELLITE_WIDTH);
        end
        function area = get.LARGEST_SURFACE_AREA(obj)
            area = obj.SATELLITE_LENGTH * obj.SATELLITE_WIDTH;
        end
        function inertia = get.INERTIA_Z(obj)
            inertia = 1/12 * obj.SATELLITE_MASS ...
                * (obj.SATELLITE_WIDTH^2 + obj.SATELLITE_LENGTH^2);
        end 
        function inertia = get.INERTIA_XY(obj)
        inertia = 1/12 * obj.SATELLITE_MASS ...
            * (obj.SATELLITE_WIDTH^2 + obj.SATELLITE_WIDTH^2);
        end
        function axis = get.SEMIMAJOR_AXIS(obj)
            axis = obj.ALTITUDE + obj.EARTH_RADIUS;
        end
        function v = get.SATELLITE_VELOCITY(obj)
            v = 2 * pi * obj.SEMIMAJOR_AXIS / obj.SECONDS_PER_ORBIT;
        end
    end
end

