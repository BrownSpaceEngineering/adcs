%% ASSUMPTIONS
% Copper wire 36 AWG
% Steel Core
% Max. power draw is 0.2W (double check this)
% Max. volts is 3.7 (ask Julien)
% Max. Mass

%% CONSTANTS
% PARAMETRIC CONSTANTS
D = 0.49; % A*m^2
D_range = 0.01;
plot = false;
num_points_1 = 50; % number of points in param. analysis
num_points_2 = 50; % use 500+ for accurate numbers, use ~50 for plot

% MATERIAL CONSTANTS
mu_r = 1554; % Steel
rho_c = 8.74*1000; % kg/m^3
W_w = 1.77e-8; % ohm-metre
rho_w = 8.96*1000; % kg/m^3 (near room temp)
r_w = 0.0635*0.001; % m

% LOGISTIC CONSTRAINTS
M_max = 5/1000; % kg max. mass
V = 3.7; % volts (max)
P = 0.2; % W (max power draw)

%% PARAMETRIC ANALYSIS
syms r_c l_c
assume(r_c > 0);
assume(l_c > 0);

I = P / V;

r_c_values = linspace(0.001, 0.02, num_points_1);
l_c_values = linspace(0.01, 0.05, num_points_2);
D_values = zeros(num_points_1, num_points_2);

valid_vals = zeros(max(num_points_2, num_points_1), 2);
iter = 0;
for i = 1:num_points_1
    for j = 1:num_points_2
        r_c = r_c_values(i);
        l_c = l_c_values(j);
        N_d = (4*(log(l_c/r_c)-1)) / ((l_c/r_c)^2-4*log(l_c/r_c));
        N = round(l_c / (r_w * 2),0);
        D_values(i,j) = pi * (r_c^2) * N * I * (1 + ((mu_r - 1)/(1 + ((mu_r - 1) * N_d))));
        if (D_values(i,j) > (D - D_range) && D_values(i,j) < (D + D_range))
            iter = iter + 1;
            valid_vals(iter, 1) = r_c;
            valid_vals(iter, 2) = l_c;
        end
    end
end

valid_vals( all(~valid_vals,2), : ) = [];


%% PLOT RESULTS

[X,Y] = meshgrid(l_c_values,r_c_values);
contour(X,Y,D_values,30);
xlabel('Core Length (m)');
ylabel('Core Radius (m)');
title('Parametric Analysis of Magnetic Dipole Moment (A*m^2)');

%% PLOT 3D
figure
surf(l_c_values, r_c_values, D_values);
title('Optimal Core Length and Radius for Magnetic Dipole Moment');
xlabel('Core Length (m)');
ylabel('Core Radius (m)');
zlabel('Magnetic Dipole Moment (A*m^2)');

%% INTERPOLATE VALUES
% Define values to interpolate
point_r_c = 0.01; % m
point_l_c = 0.04; % m

% Interpolate value at specific rc and lc
D_value = interp2(l_c_values, r_c_values, D_values, point_l_c, point_r_c, 'linear');
disp(['At r_c=', num2str(point_r_c), 'm and l_c=', num2str(point_l_c)])
disp(['DIPOLE: ', num2str(D_value), ' A*m^2']);

