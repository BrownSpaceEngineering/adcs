
p = [0.1,0.1,0.8; 0.1,0.8,0.1]';
q = [0,0, 1; 0,1,0]';

% disp(p);
% disp(size(p));
% % disp(p(:,1));

[R t err] = quest(p,q);

disp(R*p);
% disp(R*q);

% disp(R);
disp("Error");
disp(err);