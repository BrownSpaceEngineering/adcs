function openVisualizationSettings()
%openVisualizationSettings Change CubeSat Animation Settings

%  Copyright 2019-2022 The MathWorks, Inc.

% If MBSE project is loaded and architecture model is open,
% entry point is from the MBSE demo, update the MBSE
% visualization block
if exist("asbCubeSatArchModel", "file") ...
        && bdIsLoaded("asbCubeSatArchModel")
    load_system("asbCubeSatVisualization")
    open_system("asbCubeSatVisualization/Visualization","mask");
else
    open_system("asbCubeSat");
    open_system("asbCubeSat/Visualization","mask");
end
