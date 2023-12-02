function updateCubeSatControllerProperties()
% updateCubeSatControllerProperties Set CubeSat Simulation Model Controller
% Properties

%  Copyright 2019-2022 The MathWorks, Inc.

    mydataDict = Simulink.data.dictionary.open('asbCubeSatModelData.sldd');
    dDataSectionObj = getSection(mydataDict,'Design Data');

    initKp = num2str(evalin(dDataSectionObj, 'gains.Kp'));
    initKi = num2str(evalin(dDataSectionObj, 'gains.Ki'));
    initKd = num2str(evalin(dDataSectionObj, 'gains.Kd'));

    prompt = {'CubeSat Proportional Controller Gain (Kp):','CubeSat Integral Controller Gain (Ki):',...
              'CubeSat Derivative Controller Gain (Kd):'};
    title = 'CubeSat Controller Properties';
    dims = [1 50];
    definput = {initKp,initKi,initKd};
    opts.Resize = 'on';
    opts.WindowStyle = 'normal';
    userInput = inputdlg(prompt,title,dims,definput, opts);

    if ~isempty(userInput)
        gains.Kp = eval(userInput{1});
        gains.Ki = eval(userInput{2});
        gains.Kd = eval(userInput{3});
        assignin(dDataSectionObj, 'gains', gains);
    end

end
