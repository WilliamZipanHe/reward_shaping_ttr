function [xs N] = gridGeneration(dim, Min, Max, dx)

N = zeros(dim,1);

N = (Max-Min)./dx; % # of points on each axis
N(1) = N(1)+1;
N(2) = N(2)+1;
N(3) = 100;

% N = [51; 40; 50];
% N = [101; 78; 100];



    xs = zeros(N(1),N(2),N(3),dim);
    for k = 1:N(3)
        xs(:,:,k,1) = linspace(Min(1),Max(1),N(1))'*ones(1,N(2));
        xs(:,:,k,2) = ones(N(1),1)*linspace(Min(2),Max(2),N(2));
        xs(:,:,k,3) = ones(N(1),N(2))*(Min(3) + (k-1)*dx(3));
    end
    
