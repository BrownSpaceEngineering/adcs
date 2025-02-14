function varargout = cubeSatCallback(blk, action, varargin)
%cubeSatCallback Callback for CubeSat initial conditions

%  Copyright 2019-2021 The MathWorks, Inc.

    switch action
      case 'computeIC'
        switch varargin{1}
          case 'Keplerian Orbital Elements'
            initCond = computeCubeSatState(blk, varargin{1}, varargin{2},...
                                           varargin{3}, varargin{4}, varargin{5}, varargin{6},...
                                           varargin{7}, varargin{8}, varargin{9}, varargin{10},...
                                           varargin{11}, varargin{12}, varargin{19}, varargin{20});
          case 'ECI Position and Velocity'
            initCond = computeCubeSatState(blk, varargin{1}, varargin{2},...
                                           varargin{3}, varargin{13}, varargin{14}, varargin{19},...
                                           varargin{20});
          case 'ECEF Position and Velocity'
            initCond = computeCubeSatState(blk, varargin{1}, varargin{2},...
                                           varargin{3}, varargin{15}, varargin{16}, varargin{19},...
                                           varargin{20});
          case 'Geodetic LatLonAlt and Velocity in NED'
            initCond = computeCubeSatState(blk, varargin{1}, varargin{2},...
                                           varargin{3}, varargin{17}, varargin{18}, varargin{19},...
                                           varargin{20});
        end
        varargout = {initCond};
      case 'handleCircularOrbit'
        handleCircularOrbit(blk);
      case 'handleMethod'
        handleMethod(blk);
    end
end

function handleCircularOrbit(blk)
    enable = get_param(blk,'MaskEnables');
    enable(7:9) = {'on'};
    enable(10:12) = {'off'};
    if strcmp(get_param(blk, 'method'), 'Keplerian Orbital Elements')
        incl_temp = abs(str2double(get_param(blk,'incl')));
        if abs(str2double(get_param(blk,'ecc'))) < 1e-12
            if incl_temp < 1e-12 || abs(incl_temp-pi)< 1e-12 % circular equatorial orbit
                enable(10) = {'on'};
                enable(7:9) = {'off'};
            else % circular inclined
                enable(11) = {'on'};
                enable(8:9) = {'off'};
            end
        else
            if incl_temp < 1e-12 || abs(incl_temp-pi) < 1e-12 % elliptical equatorial
                enable(12) = {'on'};
                enable(7:8) = {'off'};
            end
        end
    end
    set_param(blk,'MaskEnables', enable);
end

function handleMethod(blk)
    vis = get_param(blk,'MaskVisibilities');
    vis(4:18) = {'off'};
    switch get_param(blk, 'method')
      case 'Keplerian Orbital Elements'
        vis(4:12) = {'on'};
        handleCircularOrbit(blk);
      case 'ECI Position and Velocity'
        vis(13:14) = {'on'};
      case 'ECEF Position and Velocity'
        vis(15:16) = {'on'};
      case 'Geodetic LatLonAlt and Velocity in NED'
        vis(17:18) = {'on'};
    end
    set_param(blk,'MaskVisibilities', vis);
end
