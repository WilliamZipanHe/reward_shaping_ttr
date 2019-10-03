#include <math.h>
#include "matrix.h"
#include "mex.h"   //--This one is required
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

double sweepingLF(double*** phi, int N1, int N2, int N3, double*** sigma1, double*** sigma2, double sigma3, double**** xs, double* dx, double alpha, double beta, double V1, double V2)
{
    int i,j,k,s1,s2,s3;
    double c, p, q, r, H, phiTemp, phiOld, error;
    
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
            
            c = (sigma1[i][j][k]/dx[0] + sigma2[i][j][k]/dx[1] + sigma3/dx[2]);
            
            if (k == 0)
            {
                p = (phi[i+1][j][k] - phi[i-1][j][k])/(2*dx[0]);
                q = (phi[i][j+1][k] - phi[i][j-1][k])/(2*dx[1]);
                r = (phi[i][j][k+1] - phi[i][j][N3-1])/(2*dx[2]);

                H = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;

                phiTemp = - H + sigma1[i][j][k]*(phi[i+1][j][k] + phi[i-1][j][k])/(2*dx[0]) + sigma2[i][j][k]*(phi[i][j+1][k] + phi[i][j-1][k])/(2*dx[1]) + sigma3*(phi[i][j][k+1] + phi[i][j][N3-1])/(2*dx[2]);
            }
            else if (k == N3-1)
            {
                p = (phi[i+1][j][k] - phi[i-1][j][k])/(2*dx[0]);
                q = (phi[i][j+1][k] - phi[i][j-1][k])/(2*dx[1]);
                r = (phi[i][j][0] - phi[i][j][k-1])/(2*dx[2]);

                H = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;

                phiTemp = - H + sigma1[i][j][k]*(phi[i+1][j][k] + phi[i-1][j][k])/(2*dx[0]) + sigma2[i][j][k]*(phi[i][j+1][k] + phi[i][j-1][k])/(2*dx[1]) + sigma3*(phi[i][j][0] + phi[i][j][k-1])/(2*dx[2]);
            }
            else
            {
                p = (phi[i+1][j][k] - phi[i-1][j][k])/(2*dx[0]);
                q = (phi[i][j+1][k] - phi[i][j-1][k])/(2*dx[1]);
                r = (phi[i][j][k+1] - phi[i][j][k-1])/(2*dx[2]);

                H = (V1 - V2*cos(xs[i][j][k][2]))*p - V2*sin(xs[i][j][k][2])*q - alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - r) + beta*abs(r) - 1;

                phiTemp = - H + sigma1[i][j][k]*(phi[i+1][j][k] + phi[i-1][j][k])/(2*dx[0]) + sigma2[i][j][k]*(phi[i][j+1][k] + phi[i][j-1][k])/(2*dx[1]) + sigma3*(phi[i][j][k+1] + phi[i][j][k-1])/(2*dx[2]);
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
    return error;
}



void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    //---Inside mexFunction---
    //Declarations
    double *phiValues, *sigma1Values, *sigma2Values, *xsValues, *dxValues;
    double ***phi, ***sigma1, ***sigma2, ****xs, *dx;
    const int *N;
	int numIter;
    double sigma3,alpha,beta,V1,V2,error,TOL;
    int i,j,k,l, N1,N2,N3;

    //double L = 1;
    double numInfty = 1000;
    
    //Get the input
    phiValues    = mxGetPr(prhs[0]);
    sigma1Values = mxGetPr(prhs[1]);
    sigma2Values = mxGetPr(prhs[2]);
    sigma3      = (double)mxGetScalar(prhs[3]);
    xsValues    = mxGetPr(prhs[4]);
    dxValues    = mxGetPr(prhs[5]);
    alpha       = (double)mxGetScalar(prhs[6]);
    beta        = (double)mxGetScalar(prhs[7]);
    V1          = (double)mxGetScalar(prhs[8]);
    V2          = (double)mxGetScalar(prhs[9]);
    numIter     = (int)mxGetScalar(prhs[10]);
    TOL         = (double)mxGetScalar(prhs[11]);
    
    N           = mxGetDimensions(prhs[0]);
    
    N1 = N[0]; N2 = N[1]; N3 = N[2];
    
    // memory allocation & value assignment
	phi   = (double ***) malloc ( N1 * sizeof(double**));
    sigma1   = (double ***) malloc ( N1 * sizeof(double**));
    sigma2   = (double ***) malloc ( N1 * sizeof(double**));
    dx    = (double *) malloc ( 3 * sizeof(double));
    xs    = (double ****) malloc ( N1 * sizeof(double***));
	for (i=0; i<N1; i++)
    {
		phi[i]   = (double **) malloc ( N2 * sizeof(double*));
        sigma1[i]   = (double **) malloc ( N2 * sizeof(double*));
        sigma2[i]   = (double **) malloc ( N2 * sizeof(double*));
        xs[i]    = (double ***) malloc ( N2 * sizeof(double**));
        for (j=0; j<N2; j++)
        {
            phi[i][j]   = (double *) malloc ( N3 * sizeof(double));
            sigma1[i][j]   = (double *) malloc ( N3 * sizeof(double));
            sigma2[i][j]   = (double *) malloc ( N3 * sizeof(double));
            xs[i][j]    = (double **) malloc ( N3 * sizeof(double*));
            for (k=0; k<N3; k++)
            {
                phi[i][j][k]   = phiValues[(k*N2+j)*N1+i];
                sigma1[i][j][k]   = sigma1Values[(k*N2+j)*N1+i];
                sigma2[i][j][k]   = sigma2Values[(k*N2+j)*N1+i];
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
        error = sweepingLF(phi, N1,N2,N3, sigma1, sigma2, sigma3, xs, dx, alpha, beta, V1, V2);
//         mexPrintf("Error = %g at iteration %i. \n", error, k);
        if (error <= TOL) {
//             mexPrintf("Stopped at iteration %i. \n", k);
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
            free(sigma1[i][j]);
            free(sigma2[i][j]);
            free(xs[i][j]);
        }
        free(phi[i]);
        free(sigma1[i]);
        free(sigma2[i]);
        free(xs[i]);
	}
	free(phi);
    free(sigma1);
    free(sigma2);
    free(xs);
    free(dx);
}
