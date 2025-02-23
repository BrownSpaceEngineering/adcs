%% Least Squares Sun Vector Triangulation

sun = [0.2 0.5 0.3];

d1 = [
    [0 0 1]
    [0 1 0]
    [1 0 0]
    ];
d2 = -d1;

r1 = [0.29 0.5 0.2];
r2 = [0 0 0];

sunTriangulationFunc(d1, r1, d2, r2)


function v_sun = sunTriangulationFunc(d1, r1, d2, r2)

    assert(isequal(size(d1, 1), size(d2, 1), size(r1, 2), size(r2, 2)))
    assert(isequal(size(d1, 2), size(d2, 2), 3))
    
    n = size(d1, 2);
    D = zeros(n, 3);
    r = zeros(n, 1);
    
    for i=1:n
        if r1(i) > r2(i)
            D(i,:) = d1(i,:);
            r(i) = r1(i);
        else
            D(i,:) = d2(i,:);
            r(i) = r2(i);
        end
    end

    disp(D);
    disp(r);

    out = D \ r;

    disp(out / norm(out))
    norm()

end


