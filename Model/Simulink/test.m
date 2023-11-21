
[XYZ,H,D,I,F] ...
    = igrfmagm(400000, 41, 71, decyear(datetime('now')));
[Bx, By, Bz] = deal(XYZ);

disp(Bx)
disp(By)
disp(Bz)

disp('Current ' + Bx + ' exceeds maximum current of' + Constants.MAX_CURRENT + 'A for 30 AWG wire')