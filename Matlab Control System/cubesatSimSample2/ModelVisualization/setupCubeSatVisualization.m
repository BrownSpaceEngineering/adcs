function setupCubeSatVisualization()
%setupVisualization Set CubeSat Simulation Visualization Properties

%  Copyright 2019-2022 The MathWorks, Inc.

    mydataDict = Simulink.data.dictionary.open('asbCubeSatModelData.sldd');
    dDataSectionObj = getSection(mydataDict,'Design Data');

    visVariant = -1;
    switch evalin(dDataSectionObj, 'variantVisualization')
      case 0
        visVariant = 2; % No Visualization
      case 1
        visVariant = 1; % Simulink 3D Animation
    end

    if builtin('license','test','Virtual_Reality_Toolbox')
        [indx,tf] = listdlg('PromptString','Select a Visualization Tool:',...
                            'SelectionMode','single', 'ListSize', [200,60],...
                            'ListString',{'Simulink 3D Animation','No Visualization'});
        if tf && indx ~= visVariant
            if indx == 1
                assignin(dDataSectionObj, 'variantVisualization', 1); % Simulink 3D Animation
            else
                assignin(dDataSectionObj, 'variantVisualization', 0); % No Visualization
            end
            if bdIsLoaded('asbCubeSat')
                model_obj = get_param('asbCubeSat','Object');
                model_obj.refreshModelBlocks;
            end
        end
    else
        assignin(dDataSectionObj, 'variantVisualization', 0);
        if bdIsLoaded('asbCubeSat')
            model_obj = get_param('asbCubeSat','Object');
            model_obj.refreshModelBlocks;
        end
        msgbox('No License found for Simulink 3D Animation. Turning off visualization.');
    end
end
