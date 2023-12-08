function DipoleDemand()
%This function generates a least squares fit that matches the torque 
% the torquers can produce to the torque demand. 
% The output is the dipole demand in ATM^2 (amp-turn-meter-squared).
  el       = [6378+400,0.9006,0,0,0,0]; %orbit altitude and inclination (km, rad)
  [r, v]   = El2RV( el );
  q        = QLVLH( r, v );
  jD       = Date2JD([2026 6 1 0 0 0]);
  b        = QForm( q, BDipole( r, jD ) );
  u        = [1;1;1];
  sclrCost = 1;
  torqueDemand = DisturbanceTorque();
  disp("Torque Demand: " + torqueDemand);
  [dipole, ~] = MagneticControl(b, torqueDemand, u, sclrCost);

  disp("Dipole Demand:");
  disp(dipole);
end 

