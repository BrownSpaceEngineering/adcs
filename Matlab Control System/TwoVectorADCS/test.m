k = TwoVectorADCS(quaternion(1, 0, 0, 0), ...
    [0,0,0], eye(6));
mekf = MEKF(quaternion(1, 0, 0, 0), ...
    [0,0,0], ...
    eye(6), ...
    eye(6), ...
    eye(9), ...
    1);
true_rot = quaternion(eul2quat([0, pi/3, pi/3], "XYZ"));

basis_vec_1 = [1,2,3]/norm([1,2,3]);
basis_vec_2 = [4,2,1]/norm([4,2,1]);
basis_vec_3 = [1,2,9]/norm([1,2,9]);

observed_vec_1 = rotatepoint(true_rot, basis_vec_1);
observed_vec_2 = rotatepoint(true_rot, basis_vec_2);
observed_vec_3 = rotatepoint(true_rot, basis_vec_3);
observed_stacked = [observed_vec_1; observed_vec_2; observed_vec_3];
true_stacked = [basis_vec_1; basis_vec_2; basis_vec_3];
iter = 0;

while iter < 30
    vecs_noisy = vecs + 0.1 * rand(9, 1);
    stacked_noisy = observed_stacked + 0.05*rand(3, 3);
    k = k.iterate(stacked_noisy, true_stacked, [0,0,0]);
    iter = iter + 1;
end
disp(true_rot);
disp(k.get_world_to_body());