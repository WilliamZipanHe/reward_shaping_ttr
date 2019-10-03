clear all; clc; close all;

global alpha; global beta;
global V1; global V2;
global r;

alpha = 1; beta = 1; 
V1 = 5; % V2 = 5;
V2 = 100;
r = 5;

epsilon = 1e-6;

dim = 3;
Min = zeros(dim,1);
Max = zeros(dim,1);
Min(1) = -6;
Min(2) = -10;
Min(3) = 0;
Max(1) = 20;
Max(2) = 10;
Max(3) = 2*pi;

% dx = [0.1; 0.1; 2*pi/100];
dx = [0.5; 0.5; 2*pi/100];

% dx = [26/50; 20/39; 2*pi/49];
% dx = [26/100; 20/77; 2*pi/100];

Max(3) = Max(3) - dx(3);

[xs N] = gridGeneration(dim, Min, Max, dx);

% initialization
phi = 100*ones(N(1),N(2),N(3));

% Target
phi((xs(:,:,:,1).^2 + xs(:,:,:,2).^2) <= r^2) = 0;

% 1 for games
R = ones(size(phi));

%numerical viscosity 

% sigma1 = abs(-V1+V2*cos(xs(:,:,:,3))) + alpha*abs(xs(:,:,:,2));
% sigma2 = abs(V2*sin(xs(:,:,:,3))) + alpha*abs(xs(:,:,:,1));
% sigma3 = abs(alpha - beta)+eps;

% sigma1P = abs(V1 - V2*cos(xs(:,:,:,3)) - alpha*xs(:,:,:,2));
% sigma1N = abs(V1 - V2*cos(xs(:,:,:,3)) + alpha*xs(:,:,:,2));
% sigma2P = abs(-V2*sin(xs(:,:,:,3)) - alpha*xs(:,:,:,1));
% sigma2N = abs(-V2*sin(xs(:,:,:,3)) + alpha*xs(:,:,:,1));

%LF sweeping
mex mexLFsweep.cpp; disp('mexing done!');

% numIter = 10000;
numIter = 100;
TOL = eps;

startTime = cputime;
tic;
mexLFsweep(phi,xs,dx,alpha,beta,V1,V2,numIter,TOL);
toc;


endTime = cputime;
fprintf('Total execution time %g seconds', endTime - startTime);

% phiVis = zeros(size(phi));
% phiVis((phi == 100)) = +Inf;

%[X Y Z] = meshgrid(linspace(Min(2),Max(2),N(2)),linspace(Min(1),Max(1),N(1)), linspace(Max(3),Min(3),N(3)));
X = permute(xs(:,:,:,1), [2,1,3]);
Y = permute(xs(:,:,:,2), [2,1,3]);
Z = permute(xs(:,:,:,3), [2,1,3]);

phiDis = permute(phi, [2,1,3]);

t=1;

aspectRatio = [ 1 1 0.4 ];
figure(1)
p = patch(isosurface(X, Y, Z, phiDis, t));
isonormals(X, Y, Z, phiDis ,p)
set(p,'FaceColor','red','EdgeColor','none');
axis([Min(1) Max(1) Min(2) Max(2) Min(3) Max(3)]);
% axis square;
lighting phong;
view(3)
daspect(aspectRatio);
view([10,-5,3])
camlight left;  camlight right;
title([ 't = ' num2str(t) ]);
grid on;
xlabel('x_1');  ylabel('x_2');  zlabel('x_3');


% load('sol_101_10.mat');
% 
% dataDis = permute(data, [2,1,3]);
% figure(2)
% p = patch(isosurface(X, Y, Z, dataDis, 0));
% isonormals(X, Y, Z, dataDis ,p)
% set(p,'FaceColor','red','EdgeColor','none');
% axis([Min(1) Max(1) Min(2) Max(2) Min(3) Max(3)]);
% % axis square;
% lighting phong;
% view(3)
% daspect(aspectRatio);
% view([10,-5,3])
% camlight left;  camlight right;
% title([ 't = ' num2str(t) ]);
% grid on;
% xlabel('x_1');  ylabel('x_2');  zlabel('x_3');

% n = 9;
% figure(2)
% hold on;
% %contour(xs(:,:,n,1),xs(:,:,n,2),phiVis(:,:,t),20,'k')
% pcolor(xs(:,:,n,1),xs(:,:,n,2),phiVis(:,:,n))
% shading flat;
% % colorbar('location','NorthOutside');
% %axis square;
% colorbar;
% caxis([0 100]);
% xlabel 'x'; ylabel 'y';







    