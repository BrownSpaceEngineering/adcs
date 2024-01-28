% Define the function
fun = @(x) x(1)^2 + x(2)^2 + x(3)^2 - x(1)*x(3) + x(2)*x(3);

% Initial guess
x0 = [0,0,0];

% Call the optimization function
[x,fval] = fminsearch(fun,x0);

% Display the result
disp('The minimum value is:'), disp(fval)
disp('The values of x, y, and z are:'), disp(x)
