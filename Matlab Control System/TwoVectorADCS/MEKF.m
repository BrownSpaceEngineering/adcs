classdef MEKF
    properties
        estimated_rotation
        estimated_w_bias
        estimated_covariance
        process_noise_matrix
        observation_noise_matrix
        dt
    end
    methods
        function self = MEKF(starting_rotation, starting_w, estimated_covariance, ...
                process_noise_matrix, observation_noise_matrix, dt)
            self.estimated_rotation = starting_rotation;
            self.estimated_w_bias = starting_w;
            self.estimated_covariance = estimated_covariance;
            self.process_noise_matrix = process_noise_matrix;
            self.observation_noise_matrix = observation_noise_matrix;
            self.dt = dt;
        end
        function S = skew(self, w)
            S = [  0   -w(3)  w(2)
              w(3)  0    -w(1)
             -w(2) w(1)   0];
        end
        function self = predict(self, predicted_w)
            true_w = predicted_w-self.estimated_w_bias;%predicted_w is the angular velocity we predict we're going at. in the beginning, it'll probably be 0,0,0
            approx_quaternion_update = quaternion(0, true_w(1), true_w(2), true_w(3));
            self.estimated_rotation = self.estimated_rotation + 1/2 * self.dt * quatmultiply(self.estimated_rotation, approx_quaternion_update);
            self.estimated_rotation = quatnormalize(self.estimated_rotation);

            F = zeros(6);
            F(1:3, 1:3) = -self.skew(true_w);
            F(1:3, 4:6) = -eye(3);

            G = eye(6) + F * self.dt;
            self.estimated_covariance = G*self.estimated_covariance*G' + self.process_noise_matrix;

        end
        function self = update(self, rotated_unit_vectors)
            quat_world_to_body = quatinv(self.estimated_rotation);%quaternion corresponding to world -> body rotation
            predicted_measurements = zeros(9, 1);
            predicted_measurements(1:3) = rotatepoint(quat_world_to_body, [1, 0, 0]);
            predicted_measurements(4:6) = rotatepoint(quat_world_to_body, [0, 1, 0]);
            predicted_measurements(7:9) = rotatepoint(quat_world_to_body, [0, 0, 1]);

            H = zeros(9, 6);
            H(1:3, 1:3) = self.skew(rotatepoint(quat_world_to_body, [1, 0, 0]));
            H(4:6, 1:3) = self.skew(rotatepoint(quat_world_to_body, [0, 1, 0]));
            H(7:9, 1:3) = self.skew(rotatepoint(quat_world_to_body, [0, 0, 01]));
            
            PH_T = self.estimated_covariance*H';
            inn_cov = H*(PH_T) + self.observation_noise_matrix;
            K = PH_T*pinv(inn_cov);
            self.estimated_covariance = (eye(6) - K*H)*self.estimated_covariance;

            updated_state = K*(rotated_unit_vectors - predicted_measurements);
            updated_state = updated_state';
            
            
            update_quaternion = quaternion(1, 1/2 * updated_state(1), 1/2 * updated_state(2), 1/2 * updated_state(3));
            self.estimated_rotation = quatmultiply(self.estimated_rotation, update_quaternion);
            self.estimated_rotation = quatnormalize(self.estimated_rotation);
            self.estimated_w_bias = self.estimated_w_bias + updated_state(4:6);
        end
        function self = iterate(self, predicted_w, rotated_unit_vectors)
            self = self.predict(predicted_w);
            self = self.update(rotated_unit_vectors);
        end
        function q = get_world_to_body(self)
            q = quatinv(self.estimated_rotation);
        end
        function q = get_body_to_world(self)
            q = self.estimated_rotation;
        end
        function b = get_gyro_bias(self)
            b = self.estimated_w_bias;
        end
    end
end
         
