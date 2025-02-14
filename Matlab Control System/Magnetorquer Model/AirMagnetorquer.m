classdef AirMagnetorquer < Magnetorquer
    properties
        side_length;
        total_side_length;
        dipole_moment;
        wire_length;
        core_mass;
    end
    methods
        function obj = AirMagnetorquer(current, side_length, core_length, layers, temp)
            obj@Magnetorquer(current, core_length, layers, temp);
            obj.side_length = side_length;
            obj.total_side_length = side_length + 2 * obj.wire_height;
            obj.wire_length = obj.calc_wire_length();
            obj.core_mass = obj.calc_core_mass();
            obj.dipole_moment = obj.calc_dipole_moment();
            obj.calculate_total_mass();
            obj.calculate_voltage();
        end
        function moment = calc_dipole_moment(obj)
            moment = obj.side_length^2 * obj.turns * obj.current;
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