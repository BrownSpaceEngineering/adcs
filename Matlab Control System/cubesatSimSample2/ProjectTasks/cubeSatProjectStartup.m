function cubeSatProjectStartup
% cubeSatProjectStartup Initialize CubeSat Simulation Model
% Initial orbital state is taken from ISS trajectory data for
% 2019/004/12:00:00 UTC (Orbit 2981).  Real-time ISS trajectory data is
% available at:
% https://spaceflight.nasa.gov/realdata/sightings/SSapplications/Post/JavaSSOP/orbit/ISS/SVPOST.html

%  Copyright 2019-2021 The MathWorks, Inc.


%% Load model bus definitions into data dictionary asbCubeSatModelData
% cubeSatBusDefinitions;

%% Visualization control
    mydataDict = Simulink.data.dictionary.open('asbCubeSatModelData.sldd');
    dDataSectionObj = getSection(mydataDict,'Design Data');
    if evalin(dDataSectionObj, 'variantVisualization') == 1 && ~builtin('license','test','Virtual_Reality_Toolbox')
        evalin(dDataSectionObj,'variantVisualization = 0;'); % Disable SL3D animation
    else
        close(mydataDict);
    end

end
