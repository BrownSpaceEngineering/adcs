function updateCubeSatMassProperties()
%updateCubeSatMassProperties Set CubeSat Simulation Model Mass Properties

%  Copyright 2019-2022 The MathWorks, Inc.

    mydataDict = Simulink.data.dictionary.open('asbCubeSatModelData.sldd');
    dDataSectionObj = getSection(mydataDict,'Design Data');

    initMass = num2str(evalin(dDataSectionObj, 'vehicle.mass'));
    moi = num2str(evalin(dDataSectionObj, 'vehicle.inertia'));

    initMOI = regexprep(['[' moi(1,:) ';' moi(2,:) ';' moi(3,:) ']'],' +',' ');

    prompt = {'CubeSat Mass (kg):','CubeSat Moments of Inertia:'};
    title = 'CubeSat Mass Properties';
    dims = [1 50];
    definput = {initMass,initMOI};
    opts.Resize = 'on';
    opts.WindowStyle = 'normal';
    userInput = inputdlg(prompt,title,dims,definput,opts);

    if ~isempty(userInput)
        vehicle.mass = eval(userInput{1});
        vehicle.inertia = eval(userInput{2});
        assignin(dDataSectionObj, 'vehicle', vehicle);
    end
end
