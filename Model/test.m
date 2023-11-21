
[current, core_radius, core_length, layers, temp] = deal(0.075, 0.005, 0.045, 6, 20);

% current = 0.1; % example value, replace with actual value
% core_radius = 0.01; % example value, replace with actual value
% core_length = 0.1; % example value, replace with actual value
% layers = 10; % example value, replace with actual value
% temp = 300; % example value, replace with actual value

% Create an object of the CoreMagnetorquer class
coreMagnetorquer = CoreMagnetorquer(core_radius, core_length, layers, temp);

coreMagnetorquer.calc_dipole_moment(0.1)


cm = CoreMagnetorquer(core_radius, core_length, layers, temp);
cm2 = CoreMagnetorquer(core_radius, core_length, layers, temp);
am = AirMagnetorquer(0.045, 0.025, 5, 20);

cm.calc_dipole_moment(0.1)