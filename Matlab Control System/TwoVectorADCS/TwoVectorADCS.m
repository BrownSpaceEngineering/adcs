%ADCS structure to solve when given a magnetometer & sun sensor
classdef TwoVectorADCS
    properties
        MEKF_filter;
    end
    methods
        function self = TwoVectorADCS(starting_MEKF_rotation, starting_MEKF_w, ...
                starting_MEKF_covariance)
            self.MEKF_filter = MEKF(starting_MEKF_rotation, starting_MEKF_w, ...
                starting_MEKF_covariance, constants.MEKF_process_noise_mat, ...
                constants.MEKF_observation_noise_mat, constants.system_dt);
        end
        function self = iterate(self, observation_vectors, reference_vectors, predicted_w)
            %predicted w is the w we think we might be going at due to magnetorquers
            quest_guess = QuEST.QuEST_Algorithm(observation_vectors, reference_vectors);%gets a guess from QuEST
            %generates 3 unit vectors to use with the MEKF
            vec_1 = rotatepoint(quest_guess, [1,0,0]);
            vec_2 = rotatepoint(quest_guess, [0,1,0]);
            vec_3 = rotatepoint(quest_guess, [0,0,1]);
            rotated_unit_vecs = [vec_1, vec_2, vec_3]';
            self.MEKF_filter = self.MEKF_filter.iterate(predicted_w, rotated_unit_vecs);
        end
        function q = get_world_to_body(self)
            q = self.MEKF_filter.get_world_to_body();
        end
        function q = get_body_to_world(self)
            q = self.MEKF_filter.get_body_to_world();
        end
        function b = get_gyro_bias(self)
            b = self.MEKF_filter.get_gyro_bias();
        end
    end
end