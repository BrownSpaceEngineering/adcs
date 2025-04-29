classdef constants
    properties (Constant)
        system_dt = 1;
        MEKF_process_noise_mat = eye(6);
        MEKF_observation_noise_mat = eye(9);
    end
end

