#include <math.h>
#include "matrix.h"
#include "mex.h"   //--This one is required
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

double sweepingLF(double*** phi, int N1, int N2, int N3, double**** xs, double* dx, double alpha, double beta, double V1, double V2)
{
    int i,j,k,s1,s2,s3;
    double c, p, q, r, H, phiTemp, phiOld, error;
    double sigma1, sigma2, sigma3;
    
    int count;
    count = 0;
//     double small=0.1;
//     double pP, pM, qP, qM, rP, rM, HP, HM, sigmaP, sigmaM;
    
    error = 0;
//     N1 = N[0]; N2 = N[1]; N3 = N[2];
    
    
    for (s1=1; s1>=-1; s1-=2 )
    for (s2=1; s2>=-1; s2-=2 )
    for (s3=1; s3>=-1; s3-=2 )
    {
        // LF sweeping module
        for ( i=(s1<0 ? (N1-2):1); (s1<0 ? i>=1:i<=(N1-2)); i+=s1 )
        for ( j=(s2<0 ? (N2-2):1); (s2<0 ? j>=1:j<=(N2-2)); j+=s2 ) 
        for ( k=(s3<0 ? (N3-1):0); (s3<0 ? k>=0:k<=(N3-1)); k+=s3 ) 
        {
            phiOld = phi[i][j][k];
            
            count += 1;
//             c = (sigma1[i][j][k]/dx[0] + sigma2[i][j][k]/dx[1] + sigma3/dx[2]);
            
            if (k == 0)
            {
                p = (phi[i+1][j][k] - phi[i-1][j][k])/(2*dx[0]);
                q = (phi[i][j+1][k] - phi[i][j-1][k])/(2*dx[1]);
                r = (phi[i][j][k+1] - phi[i][j][N3-1])/(2*dx[2]);
                
                sigma1 = abs(V1 - V2*cos(xs[i][j][k][2])) + abs(alpha*xs[i][j][k][1]);
                sigma2 = abs(-V2*sin(xs[i][j][k][2])) + abs(alpha*xs[i][j][k][0]);
                sigma3 = alpha+beta;
//                 sigma3 = 1;
                

                c = (sigma1/dx[0] + sigma2/dx[1] + sigma3/dx[2]);

                H = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;
                

                phiTemp = - H + sigma1*(phi[i+1][j][k] + phi[i-1][j][k])/(2*dx[0]) + sigma2*(phi[i][j+1][k] + phi[i][j-1][k])/(2*dx[1]) + sigma3*(phi[i][j][k+1] + phi[i][j][N3-1])/(2*dx[2]);
            }
            else if (k == N3-1)
            {
                p = (phi[i+1][j][k] - phi[i-1][j][k])/(2*dx[0]);
                q = (phi[i][j+1][k] - phi[i][j-1][k])/(2*dx[1]);
                r = (phi[i][j][0] - phi[i][j][k-1])/(2*dx[2]);
                
                sigma1 = abs(V1 - V2*cos(xs[i][j][k][2])) + abs(alpha*xs[i][j][k][1]);
                sigma2 = abs(-V2*sin(xs[i][j][k][2])) + abs(alpha*xs[i][j][k][0]);
                sigma3 = alpha+beta;
//                 sigma3 = 1;

                
                c = (sigma1/dx[0] + sigma2/dx[1] + sigma3/dx[2]);
                
                H = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;

                phiTemp = - H + sigma1*(phi[i+1][j][k] + phi[i-1][j][k])/(2*dx[0]) + sigma2*(phi[i][j+1][k] + phi[i][j-1][k])/(2*dx[1]) + sigma3*(phi[i][j][0] + phi[i][j][k-1])/(2*dx[2]);
            }
            else
            {
                p = (phi[i+1][j][k] - phi[i-1][j][k])/(2*dx[0]);
                q = (phi[i][j+1][k] - phi[i][j-1][k])/(2*dx[1]);
                r = (phi[i][j][k+1] - phi[i][j][k-1])/(2*dx[2]);
                
                sigma1 = abs(V1 - V2*cos(xs[i][j][k][2])) + abs(alpha*xs[i][j][k][1]);
                sigma2 = abs(-V2*sin(xs[i][j][k][2])) + abs(alpha*xs[i][j][k][0]);
                sigma3 = alpha+beta;
//                 sigma3 = 1;

                
                c = (sigma1/dx[0] + sigma2/dx[1] + sigma3/dx[2]);
                
                H = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;

//                 pP = p*(1+small);
//                 pM = p*(1-small);
//                 HP = (V1 - V2*cos(xs[i][j][k][2]))*pP - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*pP - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;
//                 HM = (V1 - V2*cos(xs[i][j][k][2]))*pM - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*pM - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;
//                 sigmaP = abs(HP-H)/(p*small);
//                 sigmaM = abs(HM-H)/(p*small);
//                 sigma1 = max(sigmaP, sigmaM);
//                 
//                 qP = q*(1+small);
//                 qM = q*(1-small);
//                 HP = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*qP - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*qP - r) + beta*abs(r) - 1;
//                 HM = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*qM - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*qM - r) + beta*abs(r) - 1;
//                 sigmaP = abs(HP-H)/(q*small);
//                 sigmaM = abs(HM-H)/(q*small);
//                 sigma2 = max(sigmaP, sigmaM);
//                 
//                 rP = r*(1+small);
//                 rM = r*(1-small);
//                 HP = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - rP) + beta*abs(rP) - 1;
//                 HM = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - rM) + beta*abs(rM) - 1;
//                 sigmaP = abs(HP-H)/(r*small);
//                 sigmaM = abs(HM-H)/(r*small);
//                 sigma3 = max(sigmaP, sigmaM);
                
                phiTemp = - H + sigma1*(phi[i+1][j][k] + phi[i-1][j][k])/(2*dx[0]) + sigma2*(phi[i][j+1][k] + phi[i][j-1][k])/(2*dx[1]) + sigma3*(phi[i][j][k+1] + phi[i][j][k-1])/(2*dx[2]);
            }
            
            phi[i][j][k] = min(phiTemp/c, phiOld);

            error = max(error, phiOld - phi[i][j][k]);

        }
        // computational boundary condition
        
        for ( j = 0; j <= (N2-1); j++)
        for ( k = 0; k <= (N3-1); k++)
        {
            phiOld = phi[0][j][k]; 
            phi[0][j][k] = min(max(2*phi[1][j][k] - phi[2][j][k], phi[2][j][k]), phiOld); 
            error = max(error, phiOld - phi[0][j][k]);
            
            phiOld = phi[N1-1][j][k];
            phi[N1-1][j][k] = min(max(2*phi[N1-2][j][k] - phi[N1-3][j][k], phi[N1-3][j][k]), phiOld); 
            error = max(error, phiOld - phi[N1-1][j][k]);
        }

        for ( k = 0; k <= (N3-1); k++)
        for ( i = 0; i <= (N1-1); i++)
        {
            phiOld = phi[i][0][k]; 
            phi[i][0][k] = min(max(2*phi[i][1][k] - phi[i][2][k], phi[i][2][k]), phiOld); 
            error = max(error, phiOld - phi[i][0][k]);
            
            phiOld = phi[i][N2-1][k];
            phi[i][N2-1][k] = min(max(2*phi[i][N2-2][k] - phi[i][N2-3][k], phi[i][N2-3][k]), phiOld); 
            error = max(error, phiOld - phi[i][N2-1][k]);
            
        }

//         for ( i = 0; i <= (N1-1); i++)
//         for ( j = 0; j <= (N2-1); j++)
//         {
//             phiOld = phi[i][j][0]; 
//             phi[i][j][0] = min(max(2*phi[i][j][1] - phi[i][j][2], phi[i][j][2]), phiOld); 
//             error = max(error, phiOld - phi[i][j][0]);
//             
//             phiOld = phi[i][j][N3-1];
//             phi[i][j][N3-1] = min(max(2*phi[i][j][N3-2] - phi[i][j][N3-3], phi[i][j][N3-3]), phiOld); 
//             error = max(error, phiOld - phi[i][j][N3-1]);
//         }
    }
    mexPrintf("count = %d", count);
    return error;
}



void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    //---Inside mexFunction---
    //Declarations
    double *phiValues, *xsValues, *dxValues;
    double ***phi, ****xs, *dx;
    //const int *N;
    const mwSize *N;
	int numIter;
    double alpha,beta,V1,V2,error,TOL;
    int i,j,k,l, N1,N2,N3;

    //double L = 1;
    double numInfty = 1000;
    
    //Get the input
    phiValues    = mxGetPr(prhs[0]);
    xsValues    = mxGetPr(prhs[1]);
    dxValues    = mxGetPr(prhs[2]);
    alpha       = (double)mxGetScalar(prhs[3]);
    beta        = (double)mxGetScalar(prhs[4]);
    V1          = (double)mxGetScalar(prhs[5]);
    V2          = (double)mxGetScalar(prhs[6]);
    numIter     = (int)mxGetScalar(prhs[7]);
    TOL         = (double)mxGetScalar(prhs[8]);
    
    N           = mxGetDimensions(prhs[0]);
    
    N1 = N[0]; N2 = N[1]; N3 = N[2];
    
    // memory allocation & value assignment
	phi   = (double ***) malloc ( N1 * sizeof(double**));
    dx    = (double *) malloc ( 3 * sizeof(double));
    xs    = (double ****) malloc ( N1 * sizeof(double***));
	for (i=0; i<N1; i++)
    {
		phi[i]   = (double **) malloc ( N2 * sizeof(double*));
        xs[i]    = (double ***) malloc ( N2 * sizeof(double**));
        for (j=0; j<N2; j++)
        {
            phi[i][j]   = (double *) malloc ( N3 * sizeof(double));
            xs[i][j]    = (double **) malloc ( N3 * sizeof(double*));
            for (k=0; k<N3; k++)
            {
                phi[i][j][k]   = phiValues[(k*N2+j)*N1+i];
                xs[i][j][k]    = (double *) malloc ( 3 * sizeof(double));
                for (l=0; l<3; l++)
                {
                    xs[i][j][k][l]    = xsValues[((l*N3+k)*N2+j)*N1+i];
                }
            }
        }
    }
    for (i=0; i<3; i++)
    {
        dx[i] = dxValues[i];
    }
    
   
    
    // run LF sweeping algorithm
    for(k=0; k<numIter; k++) 
    {
        error = sweepingLF(phi, N1,N2,N3, xs, dx, alpha, beta, V1, V2);
        mexPrintf("Error = %g at iteration %i. \n", error, k);
        if (error <= TOL) {
            mexPrintf("Stopped at iteration %i. \n", k);
            break;
        } 
        
    }
    
		
  
    // send the processed phi to the output  
    for (i=0; i < N1; i++)
	for (j=0; j < N2; j++)
    for (k=0; k < N3; k++)
        phiValues[((k*N2+j)*N1)+i] = phi[i][j][k];
           
    
    // delete memory;
	for(i=0; i< N1; i++)
    {
        for(j=0; j<N2; j++)
        {
            for(k=0; k<N3; k++)
            {
                free(xs[i][j][k]);
            }
            free(phi[i][j]);
            free(xs[i][j]);
        }
        free(phi[i]);
        free(xs[i]);
	}
	free(phi);
    free(xs);
    free(dx);
}
