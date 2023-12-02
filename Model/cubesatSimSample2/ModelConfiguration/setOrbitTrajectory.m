function setOrbitTrajectory()
%setOrbitTrajectory Set CubeSat Simulation Trajectory
%Characteristics

%  Copyright 2019-2022 The MathWorks, Inc.

    if ~bdIsLoaded('asbCubeSat')
        load_system('asbCubeSat');
    end

    open_system('asbCubeSat/Edit Initial Orbit and Attitude','mask');
end
