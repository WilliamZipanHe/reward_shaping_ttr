clear all; clc; close all;

% global alpha; global beta;
% global V1; global V2;
% global r;

global T1Max; global T1Min;
global T2Max; global T2Min;
global m; global transDrag; global rotDrag;
global L; global Iyy; global grav;

T1Max = 36.7875/2; T2Max = 36.7875/2;
T1Min = 0; T2Min = 0;
m = 1.25; transDrag = 0.25; rotDrag = 0.02255;
L = 0.5; Iyy = 0.03; grav = 9.81;

r1 = 0.5; % goal radius of Z pos
c1 = 4.0; % goal center of Z pos
r2 = 0.2; % goal radius of Vz
c2 = 0.0; % goal center of Vz
r3 = pi/12; % goal radius of theta
c3 = -pi/6; 
%r4 = 0.2; 
r4 = pi/6; % goal radius of omega
c4 = 0;



% alpha = 1; beta = 1; 
% V1 = 5; % V2 = 5;
% V2 = 100;
% r = 5;

epsilon = 1e-6;

% Vy Vz Phi Wp;
dim = 4;
Min = zeros(dim,1);
Max = zeros(dim,1);
Min(1) = -5.0;
Min(2) = -5.0;
% Min(1) = -2.0;
% Min(2) = -2.0;
% roll range: [-pi, pi] in Gazebo
% Min(3) = -pi/2;
Min(3) = -pi;
Min(4) = -3*pi;
% Min(4) = -10*pi;

% Max(1) = 2.0;
% Max(2) = 2.0;
Max(1) = 5.0;
Max(2) = 5.0;
% Max(3) = pi/2;
Max(3) = pi;
% Max(4) = 10*pi;
Max(4) = 3*pi;

dx = [0.2; 0.2; 2*pi/36; pi/15];

% dx(3) should be change to pi/20;
% dx = [0.1; 0.1; pi/20; pi/80];
% dx = [0.1; 0.1; pi/40; pi/12];
% dx = [0.1; 0.1; pi/20; pi/15];

% dx = single(dx);
% dx = [0.1; 0.1; 2*pi/100];
% dx = [0.5; 0.5; 2*pi/100];
% dx = [26/50; 20/39; 2*pi/49];
% dx = [26/100; 20/77; 2*pi/100];

Max(3) = Max(3) - dx(3);
[xs N] = gridGeneration(dim, Min, Max, dx);
% xs = single(xs);
disp(N)

% initialization
phi = 100 * ones(N(1),N(2),N(3),N(4));
% phi = single(phi);
% phi = 100*ones(N(1),N(2),N(3));

% Target
flag = abs(c1 - xs(:,:,:,:,1)) <= r1 & abs(c2 - xs(:,:,:,:,2)) <= r2 & abs(c3 - xs(:,:,:,:,3)) <= r3 & abs(c4 - xs(:,:,:,:,4)) <= r4;
phi(flag) = 0;
% phi((xs(:,:,:,1).^2 + xs(:,:,:,2).^2) <= r^2) = 0;


% 1 for games
% R = ones(size(phi));

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
numIter = 50;
TOL = 0.1;

startTime = cputime;
tic;
% mexLFsweep(phi,xs,dx,alpha,beta,V1,V2,numIter,TOL);
mexLFsweep(phi,xs,dx,T1Max,T2Max, T1Min, T2Min,m,transDrag,rotDrag,L,Iyy,grav,numIter,TOL);
toc;


endTime = cputime;
fprintf('Total execution time %g seconds', endTime - startTime);
% 
% phi_plot = phi(:,:,1,1);




