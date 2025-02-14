function initCond = computeCubeSatState(blk, mode, sim_t0, epoch, varargin)
%computeCubeSatState Compute CubeSat orbit trajectory and attitude

%  Copyright 2019-2022 The MathWorks, Inc.

% Convert julian dates to date vectors
    epochDT = datetime(epoch,'convertfrom', 'juliandate');
    sim_t0DT = datetime(sim_t0,'convertfrom', 'juliandate');

    epochVec = Aero.internal.math.createDateVec( epochDT );
    sim_t0Vec = Aero.internal.math.createDateVec( sim_t0DT );

    mjul_simT0 = mjuliandate(sim_t0DT);
    dAT = 37;
    dUT1 = deltaUT1(mjul_simT0);
    pm = polarMotion(mjul_simT0);
    dCIP = deltaCIP(mjul_simT0);
    lod = 0;

    % Conpute transformation between J2000 and MOD ECI frames
    R_ijk2j2000 = Aero.spacecraft.transform.internal.dcmMOD2J2000(epochVec, dAT)';

    switch mode
      case 'Keplerian Orbital Elements'
        % Parse inputs
        a = varargin{1};
        ecc = varargin{2};
        incl = varargin{3};
        RAAN = varargin{4};
        argp = varargin{5};
        nu = varargin{6};
        truelon = varargin{7};
        arglat = varargin{8};
        lonper = varargin{9};
        euler = varargin{10};
        pqr = varargin{11};

        % Kepler to RV_eci
        small = 1e-12;
        if ( ecc < small )
            if incl < small || abs(incl-pi)< small % circular equatorial orbit
                [r_ijk, v_ijk] = keplerian2ijk(a, ecc, incl, 0, 0,...
                                               0, 'truelon', truelon);
            else % circular inclined
                [r_ijk, v_ijk] = keplerian2ijk(a, ecc, incl, RAAN, 0,...
                                               0, 'arglat', arglat);
            end
        else
            if ( ( incl<small) || (abs(incl-pi)<small) ) % elliptical equatorial
                [r_ijk, v_ijk] = keplerian2ijk(a, ecc, incl, 0, 0,...
                                               nu, 'lonper', lonper);
            else % elliptical inclined
                [r_ijk, v_ijk] = keplerian2ijk(a, ecc, incl, RAAN, argp,...
                                               nu);
            end
        end

        % RV_tod to RV_j2000
        r_j2000 = R_ijk2j2000*r_ijk;
        v_j2000 = R_ijk2j2000*v_ijk;

        % RV_j2000 to RV_ecef
        [r_ecef, v_ecef] = eci2ecef(sim_t0Vec, r_j2000, v_j2000, 'dAT', dAT,...
                                    'dUT1', dUT1, 'pm', pm, 'dCIP', dCIP, 'lod', lod);

        % R_ecef to R_lla
        lla = ecef2lla(r_ecef(:)');

        % V_ecef to V_ned
        v_ned = dcmecef2ned(lla(1), lla(2))*v_ecef(:);

        % V_ned to V_body
        uvw = angle2dcm(euler(3)*pi/180, euler(2)*pi/180, euler(1)*pi/180, 'ZYX')*v_ned;

      case 'ECI Position and Velocity'
        % Parse inputs
        r_ijk = varargin{1};
        v_ijk = varargin{2};
        euler = varargin{3};
        pqr = varargin{4};

        % RV_eci to Kepler
        [a, ecc, incl, RAAN, argp, nu, truelon, arglat, lonper] =...
            ijk2keplerian(r_ijk,v_ijk);

        % RV_tod to RV_j2000
        r_j2000 = R_ijk2j2000*r_ijk(:);
        v_j2000 = R_ijk2j2000*v_ijk(:);

        % RV_j2000 to RV_ecef
        [r_ecef, v_ecef] = eci2ecef(sim_t0Vec, r_j2000, v_j2000, 'dAT', dAT,...
                                    'dUT1', dUT1, 'pm', pm, 'dCIP', dCIP, 'lod', lod);

        % R_ecef to R_lla
        lla = ecef2lla(r_ecef(:)');

        % V_ecef to V_ned
        v_ned = dcmecef2ned(lla(1), lla(2))*v_ecef(:);

        % V_ned to V_body
        uvw = angle2dcm(euler(3)*pi/180, euler(2)*pi/180, euler(1)*pi/180, 'ZYX')*v_ned;

      case 'ECEF Position and Velocity'
        % Parse inputs
        r_ecef = varargin{1};
        v_ecef = varargin{2};
        euler = varargin{3};
        pqr = varargin{4};

        % RV_ecef to RV_j2000
        [r_j2000, v_j2000] = ecef2eci(sim_t0Vec, r_ecef, v_ecef, 'dAT', dAT,...
                                      'dUT1', dUT1, 'pm', pm, 'dCIP', dCIP, 'lod', lod);

        % RV_j2000 to RV_tod
        r_ijk = R_ijk2j2000*r_j2000;
        v_ijk = R_ijk2j2000*v_j2000;

        % RV_eci to Kepler
        [a, ecc, incl, RAAN, argp, nu, truelon, arglat, lonper] =...
            ijk2keplerian(r_ijk,v_ijk);

        % R_ecef to R_lla
        lla = ecef2lla(r_ecef(:)');

        % V_ecef to V_ned
        v_ned = dcmecef2ned(lla(1), lla(2))*v_ecef(:);

        % V_ned to V_body
        uvw = angle2dcm(euler(3)*pi/180, euler(2)*pi/180, euler(1)*pi/180, 'ZYX')*v_ned;

      case 'Geodetic LatLonAlt and Velocity in NED'
        % Parse inputs
        lla = varargin{1};
        v_ned = varargin{2};
        euler = varargin{3};
        pqr = varargin{4};

        % V_lla to V_ecef
        r_ecef = lla2ecef(lla(:)');

        % V_ned to V_body
        uvw = angle2dcm(euler(3)*pi/180, euler(2)*pi/180, euler(1)*pi/180, 'ZYX')*v_ned(:);

        % V_ned to V_ecef
        v_ecef = dcmecef2ned(lla(1), lla(2))'*v_ned(:);

        % RV_ecef to RV_j2000
        [r_j2000, v_j2000] = ecef2eci(sim_t0Vec, r_ecef, v_ecef, 'dAT', dAT,...
                                      'dUT1', dUT1, 'pm', pm, 'dCIP', dCIP, 'lod', lod);

        % RV_j2000 to RV_tod
        r_ijk = R_ijk2j2000*r_j2000;
        v_ijk = R_ijk2j2000*v_j2000;

        % RV_eci to Kepler
        [a, ecc, incl, RAAN, argp, nu, truelon, arglat, lonper] =...
            ijk2keplerian(r_ijk,v_ijk);
    end

    % Update initial conditions in base workspace
    initCond.simStartDate.JD = sim_t0;
    initCond.simStartDate.dateVector = sim_t0Vec;
    initCond.CoordEpoch.JD = epoch;
    initCond.CoordEpoch.dateVector = epochVec;
    initCond.OrbitalElements.semiMajorAxis = a;
    initCond.OrbitalElements.eccentricity = ecc;
    initCond.OrbitalElements.inclination = incl;
    initCond.OrbitalElements.RAAN = RAAN;
    initCond.OrbitalElements.argumentOfPerigee = argp;
    initCond.OrbitalElements.trueAnomoly = nu;
    initCond.OrbitalElements.trueLongitude = truelon;
    initCond.OrbitalElements.argumentOfLatititude = arglat;
    initCond.OrbitalElements.longitudeOfPerigee = lonper;
    initCond.r_eci = r_ijk(:)';
    initCond.v_eci = v_ijk(:)';
    initCond.r_ecef = r_ecef(:)';
    initCond.v_ecef = v_ecef(:)';
    initCond.lla = lla(:)';
    initCond.v_ned = v_ned(:)';
    initCond.uvw = uvw(:)';
    initCond.euler = euler(:)';
    initCond.pqr = pqr(:)';

    mydataDict = Simulink.data.dictionary.open('asbCubeSatModelData.sldd');
    dDataSectionObj = getSection(mydataDict,'Design Data');
    icObj = getEntry(dDataSectionObj, 'initCond');
    savedInitCond = getValue(icObj);

    % Sync initial conditions block with data dictionary workspace if values have changed
    if ~isequal(initCond,savedInitCond)
        if ~isempty(blk)
            % Block callback, set values in mask
            syncICwithWS(blk, initCond);

            % If MBSE project is loaded and architecture model is open,
            % entry point is from the MBSE demo, update the stereotype
            % values to match values set in the Initial Orbit and Attitude
            % block
            if exist("asbCubeSatArchModel", "file") ...
                    && bdIsLoaded("asbCubeSatArchModel")
                syncICwithStereo(initCond);
            end

        end
        assignin(dDataSectionObj,'initCond',initCond);
    end


end

function syncICwithWS(blk, initCond)
%syncICwithWS Update modified block parameters in Initial Conditions block

    set_param(blk, 'sim_t0' ,num2str(initCond.simStartDate.JD));
    set_param(blk, 'epoch' ,num2str(initCond.CoordEpoch.JD));
    set_param(blk, 'a', num2str(initCond.OrbitalElements.semiMajorAxis));
    set_param(blk, 'ecc', num2str(initCond.OrbitalElements.eccentricity));
    set_param(blk, 'incl', num2str(initCond.OrbitalElements.inclination));
    set_param(blk, 'omega', num2str(initCond.OrbitalElements.RAAN));
    set_param(blk, 'argp', num2str(initCond.OrbitalElements.argumentOfPerigee));
    set_param(blk, 'nu', num2str(initCond.OrbitalElements.trueAnomoly));
    set_param(blk, 'truelon', num2str(initCond.OrbitalElements.trueLongitude));
    set_param(blk, 'arglat', num2str(initCond.OrbitalElements.argumentOfLatititude));
    set_param(blk, 'lonper', num2str(initCond.OrbitalElements.longitudeOfPerigee));
    set_param(blk, 'r_eci', regexprep(['[' num2str(initCond.r_eci(:)') ']'],' +',' '));
    set_param(blk, 'v_eci', regexprep(['[' num2str(initCond.v_eci(:)') ']'],' +',' '));
    set_param(blk, 'r_ecef', regexprep(['[' num2str(initCond.r_ecef(:)') ']'],' +',' '));
    set_param(blk, 'v_ecef', regexprep(['[' num2str(initCond.v_ecef(:)') ']'],' +',' '));
    set_param(blk, 'lla', regexprep(['[' num2str(initCond.lla(:)') ']'],' +',' '));
    set_param(blk, 'v_ned', regexprep(['[' num2str(initCond.v_ned(:)') ']'],' +',' '));
    set_param(blk, 'euler', regexprep(['[' num2str(initCond.euler(:)') ']'],' +',' '));
    set_param(blk, 'pqr', regexprep(['[' num2str(initCond.pqr(:)') ']'],' +',' '));
end

function syncICwithStereo(initCond)
%syncICwithStereo Update stereotype parameters (only applies when entry
%point is CubeSat MBSE Project)

    cubeSatModel = systemcomposer.loadModel("asbCubeSatArchModel");
    enterpriseComp = cubeSatModel.lookup("Path", ...
                                         "asbCubeSatArchModel/CubeSat Mission Enterprise");
    orbitComp = cubeSatModel.lookup("Path", ...
                                    "asbCubeSatArchModel/CubeSat Mission Enterprise/Space Segment/CubeSat Initial Orbit");
    attComp = cubeSatModel.lookup("Path", ...
                                  "asbCubeSatArchModel/CubeSat Mission Enterprise/Space Segment/CubeSat Initial Attitude");

    % Set stereotype values
    setProperty(enterpriseComp, "CubeSatProfile.CubeSatEnterprise.MissionStartDate", num2str(initCond.simStartDate.JD));
    setProperty(orbitComp, "CubeSatProfile.Orbit.semiMajorAxis", num2str(initCond.OrbitalElements.semiMajorAxis));
    setProperty(orbitComp, "CubeSatProfile.Orbit.eccentricity", num2str(initCond.OrbitalElements.eccentricity));
    setProperty(orbitComp, "CubeSatProfile.Orbit.inclination", num2str(initCond.OrbitalElements.inclination));
    setProperty(orbitComp, "CubeSatProfile.Orbit.argOfPeriapsis", num2str(initCond.OrbitalElements.argumentOfPerigee));
    setProperty(orbitComp, "CubeSatProfile.Orbit.rightAscensionAscendingNode", num2str(initCond.OrbitalElements.RAAN));
    setProperty(orbitComp, "CubeSatProfile.Orbit.trueAnomaly", num2str(initCond.OrbitalElements.trueAnomoly));
    setProperty(attComp, "CubeSatProfile.Attitude.eulerAngles", regexprep(['[' num2str(initCond.euler(:)') ']'],' +',' '));
    setProperty(attComp, "CubeSatProfile.Attitude.bodyRates", regexprep(['[' num2str(initCond.pqr(:)') ']'],' +',' '));
end
