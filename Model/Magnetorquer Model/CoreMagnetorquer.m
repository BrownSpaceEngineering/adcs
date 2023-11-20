classdef CoreMagnetorquer < Magnetorquer
    properties
        core_radius;
        total_radius;
        dipole_moment;
        wire_length;
        core_mass;
    end
    methods
        function obj = CoreMagnetorquer(current, core_radius, core_length, layers, temp)
            obj@Magnetorquer(current, core_length, layers, temp);
            obj.core_radius = core_radius;
            obj.total_radius = core_radius + obj.wire_height;
            obj.dipole_moment = obj.calc_dipole_moment;
            obj.wire_length = obj.calc_wire_length;
            obj.core_mass = obj.calc_core_mass;
            obj.calculate_total_mass
            obj.calculate_voltage
        end
        function moment = calc_dipole_moment(obj)
            r = obj.core_radius; N = obj.turns; I = obj.current; mu = Constants.CORE_PERMEABILITY; L = obj.core_length;
            Nd = (4*(log(L/r) - 1))/((L/r)^2 - 4*(log(L/r)));
            moment = pi * (r^2) * N * I * (1 + ((mu - 1)/(1 + ((mu - 1) * Nd))));
        end
        function mass = calc_core_mass(obj)
            core_volume = (obj.core_radius ^2) * obj.core_length * pi;
            mass = core_volume * Constants.CORE_DENSITY;
        end
        function length = calc_wire_length(obj)
            length = 0;
            for i = 1:obj.layers
                h_row = Constants.WIRE_DIAMETER * (1/2 + sqrt(3) * (i - 1));
                r_turn = obj.core_radius + h_row;
                length = length + 2 * pi * r_turn * obj.turns_per_layer;
            end
        end
    end
end
