classdef AirMagnetorquer < Magnetorquer
    properties
        side_length=0;
        total_side_length=0;
        wire_length=0;
        core_mass=0;
        max_dipole=0;
    end
    methods
        function obj = AirMagnetorquer(side_length, core_length, layers, temp)
            obj@Magnetorquer(core_length, layers, temp);
            obj.side_length = side_length;
            obj.total_side_length = side_length + 2 * obj.wire_height;
            obj.wire_length = obj.calc_wire_length();
            obj.core_mass = obj.calc_core_mass();
            % obj.dipole_moment = obj.calc_dipole_moment();
            obj.calculate_total_mass();
            % obj.calculate_voltage();
            obj.max_dipole = obj.calc_max_dipole();
        end
        function moment = calc_dipole_moment(obj, current)
            if current > Constants.MAX_CURRENT
                disp('Current %f exceeds maximum current of %f A for 30 AWG wire', current, Constants.MAX_CURRENT)
            end
            moment = obj.side_length^2 * obj.turns * current;
        end
        function md = calc_max_dipole(obj)
            md = calc_dipole_moment(obj, Constants.MAX_CURRENT);
        end
        function I = calc_current(obj, dipole_moment)
            I = dipole_moment / (obj.turns * obj.side_length^2);
        end
        function mass = calc_core_mass(obj)
            mass = 0;
        end
        function length = calc_wire_length(obj)
            length = 0;
            for i = 1:obj.layers
                h_row = Constants.WIRE_DIAMETER * (1/2 + sqrt(3) * (i - 1));
                length = length + 4 * (obj.side_length + ( 2 * h_row)) * obj.turns_per_layer;
            end
        end
    end
end