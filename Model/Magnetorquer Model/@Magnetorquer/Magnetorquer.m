classdef Magnetorquer < handle
    properties
        core_length
        layers
        temp
        turns_per_layer
        turns
        total_mass
        voltage
        max_voltage
        wire_height
    end
    methods
        function obj = Magnetorquer(core_length, layers, temp)
            obj.core_length = core_length;
            obj.layers = layers;
            obj.temp = temp;
            obj.turns_per_layer = floor(core_length / Constants.WIRE_DIAMETER);
            obj.turns = obj.turns_per_layer * layers;
            obj.total_mass = obj.calc_core_mass + obj.wire_mass;
            % obj.voltage = current * obj.wire_resistance(obj.temp);
            % obj.max_voltage = current * obj.wire_resistance(Constants.MAX_TEMP);
            obj.wire_height = Constants.WIRE_DIAMETER * ( 1 + sqrt(3) * (layers - 1) );
        end
        function mass = wire_mass(obj)
            wire_volume = obj.wire_length() * pi * (Constants.WIRE_DIAMETER / 2) ^ 2;
            mass = wire_volume * Constants.WIRE_DENSITY;
        end
        function resist = wire_resistance(obj, temp)
            resist = Constants.WIRE_REF_RESISTIVITY * (1 + ...
                Constants.WIRE_TEMP_COEFF * (temp - Constants.TEMP_REF));
            cross_section = pi * (Constants.WIRE_DIAMETER / 2) ^ 2;
            resist = resist * obj.wire_length() / cross_section;
        end
        function calculate_total_mass(obj)
            obj.total_mass = obj.core_mass() + obj.wire_mass();
        end
        % function calculate_voltage(obj)
        %     obj.voltage = obj.current * obj.wire_resistance(obj.temp);
        %     obj.max_voltage = obj.current * obj.wire_resistance(Constants.MAX_TEMP);
        % end
    end
    methods(Abstract)
        calc_dipole_moment(obj)
        calc_wire_length(obj)
        calc_core_mass(obj)
        calc_current(obj)
    end
end