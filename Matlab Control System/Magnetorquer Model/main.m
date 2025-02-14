
[current, core_radius, core_length, layers, temp] = deal(0.075, 0.005, 0.045, 6, 20);

cm = CoreMagnetorquer(current, core_radius, core_length, layers, temp);
am = AirMagnetorquer(current, 0.045, 0.025, 5, 20);