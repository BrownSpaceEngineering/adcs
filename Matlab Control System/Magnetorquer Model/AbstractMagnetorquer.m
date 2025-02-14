%% Magnetorquer Model

classdef (Abstract) AbstractMagnetorquer
    properties (Abstract)
        current;
        core_radius;
        core_length;
        layers;
        temp;
        total_radius;
        dipole_moment;
        core_mass;
        wire_length;
        wire_height;
    end
    properties (Dependent)
        turns_per_layer;
        turns;
        wire_mass;
        total_mass;
        wire_resistance;
        voltage;
        max_voltage;
    end
    methods
        function tpl = get.turns_per_layer(obj)
            tpl = obj.core_length / Constants.WIRE_DIAMETER;
        end
        function t = get.turns(obj)
            t = floor(obj.turns_per_layer * obj.layers);
        end
        function wm = get.wire_mass(obj)
            wire_volume = obj.wire_length * pi * (Constants.WIRE_DIAMETER / 2)^2;
            wm = wire_volume * Constants.WIRE_DENSITY;
        end
        function mass = get.total_mass(obj)
            mass = obj.core_mass + obj.wire_mass;
        end
        function v = get.voltage(obj)
            v = obj.current * obj.calc_wire_resistance(obj.temp);
        end
        function mv = get.max_voltage(obj)
            mv = obj.current * obj.calc_wire_resistance(Constants.MAX_TEMP);
        end
        function wire_resistance = calc_wire_resistance(obj, temp)
            resist = Constants.WIRE_REF_RESISTIVITY * (1 ... 
                + Constants.WIRE_TEMP_COEFF * (temp - Constants.TEMP_REF));
            cross_section = pi * (Constants.WIRE_DIAMETER / 2)^2;
            wire_resistance = resist * obj.wire_length / cross_section;
        end
        function wr = get.wire_resistance(obj)
            wr = obj.calc_wire_resistance(obj.temp);
        end
    end
end
