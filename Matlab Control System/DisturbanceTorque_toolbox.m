function maxTorque = DisturbanceTorque_toolbox()
%Taken from CubeSatDisturbanceAnalysis.m
%Returns the absolute maximum body torque applied by
%the drag, magnetic, gravity gradient, and optical disturbances
%within a 90-minute period. 

  d      = RHSCubeSat;
  t      = linspace(0,90,60); %seconds per 90-minute orbit
  el     = [7100 pi/2 0 0 0 0];
  [r, v] = RVFromKepler( el, t );
  % LVLH - align z axis with nadir
  q      = QLVLH( r, v );
  % Introduce some quaternion offset for more interesting results
  qDelta = AU2Q( 0.1*sin(t/Period(7100)), [1;1;1] );
  for k = 1:length(t)
    q(:,k) = QMult(q(:,k),qDelta(:,k));
  end
  jD = Date2JD([2013 4 2 0 0 0]) + t/86400;
  % Introduce some CM offset (m)
  d.surfData.cM = [0.02;0.02;0];
  % differentiate the optical properties
  solarOpt = OpticalSurfaceProperties('solar cell');
  pSolar = [solarOpt.sigmaA;solarOpt.sigmaS;solarOpt.sigmaD];
  radOpt = OpticalSurfaceProperties('radiator');
  pRadiator = [radOpt.sigmaA;radOpt.sigmaS;radOpt.sigmaD];
  d.surfData.sigma = [pSolar pSolar pRadiator pSolar pSolar pRadiator];
  % Residual magnetic dipole (ATM^2)
  d.dipole = [0;0;0.01];
  [tT, ~, ~, ~, ~, ~, ~] = CubeSatDisturbanceAnalysis( d, q, r, v, jD );

  maxTorque = max(tT,[],"all");
end
