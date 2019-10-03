clear all; clc; close all;

global alpha; global beta;
global V1; global V2;
global r;

alpha = 1; beta = 2; 


epsilon = 1e-6;

dim = 2;
Min = zeros(dim,1);
Max = zeros(dim,1);
Min(1) = -1;
Min(2) = -1;

Max(1) = 1;
Max(2) = 1;


dx = 0.04;

[xs N] = gridGeneration(dim, Min, Max, dx);

% initialization
phi = 100*ones(N(1),N(2));

% Target
phi((xs(:,:,1).^2 + xs(:,:,2).^2) <= 0) = 0;

% 1 for games
R = ones(size(phi));

%numerical viscosity 
sigma = zeros(2,1);
sigma(1) = abs(alpha-beta); sigma(2) = abs(alpha-beta);


%LF sweeping
phi = LFsweep(phi,N,sigma,xs,dx,dim);




hold on;
contour(xs(:,:,10,1),xs(:,:,10,2),phi(:,:,10),20,'k')
pcolor(xs(:,:,10,1),xs(:,:,10,2),phi(:,:,10))
shading flat;
colorbar('location','NorthOutside');
axis square;
% caxis([0 0.4]);




[X Y Z] = meshgrid(linspace(Min(1),Max(1),N(1)), linspace(Min(2),Max(2),N(2)), linspace(Min(3),Max(3),N(3)));

t=20;
p = patch(isosurface(X, Y, Z, phi, t));
isonormals(X, Y, Z, phi ,p)
set(p,'FaceColor','red','EdgeColor','none');
camlight
lighting phong;
view(3)
axis square;







    