#include <math.h>
#include "matrix.h"
#include "mex.h"   //--This one is required
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))


void WENO5(double*** phi, int i, int j, int k, double DxN, double DxP, double DyN, double DyP, double DzN, double DzP, double dx)
{
    double D1, D2, D3, D4, D5;
    double H1, H2, H3;
    double R1, R2, R3;
    double w1, w2, w3;
    double epsilon = 0.000001;
    
    //---------------------------------------------------------------------
    D1 = (phi[i-2][j][k] - phi[i-3][j][k])/dx;
    D2 = (phi[i-1][j][k] - phi[i-2][j][k])/dx;
    D3 = (phi[i][j][k] - phi[i-1][j][k])/dx;
    D4 = (phi[i+1][j][k] - phi[i][j][k])/dx;
    D5 = (phi[i+2][j][k] - phi[i+1][j][k])/dx;
    
    H1 = 13/12*(D1-2*D2+D3)*(D1-2*D2+D3) + 1/4*(D1-4*D2+3*D3)*(D1-4*D2+3*D3);
    H2 = 13/12*(D2-2*D3+D4)*(D2-2*D3+D4) + 1/4*(D2-D4)*(D2-D4);
    H3 = 13/12*(D3-2*D4+D5)*(D3-2*D4+D5) + 1/4*(3*D3-4*D4+D5)*(3*D3-4*D4+D5);
    
    R1 = 1/10*1/((epsilon+H1)*(epsilon+H1));
    R2 = 6/10*1/((epsilon+H2)*(epsilon+H2));
    R3 = 3/10*1/((epsilon+H3)*(epsilon+H3));
    
    w1 = R1/(R1+R2+R3);
    w2 = R2/(R1+R2+R3);
    w3 = R3/(R1+R2+R3);
    
    DxN = w1/3*D1 - (7*w1+w2)/6*D2 + (11*w1+5*w2+2*w3)/6*D3 + (2*w2 + 5*w3)/6*D4 - w3/6*D5;
    
    //---------------------------------------------------------------------
    D1 = (phi[i+3][j][k] - phi[i+2][j][k])/dx;
    D2 = (phi[i+2][j][k] - phi[i+1][j][k])/dx;
    D3 = (phi[i+1][j][k] - phi[i][j][k])/dx;
    D4 = (phi[i][j][k] - phi[i-1][j][k])/dx;
    D5 = (phi[i-1][j][k] - phi[i-2][j][k])/dx;
    
    H1 = 13/12*(D1-2*D2+D3)*(D1-2*D2+D3) + 1/4*(D1-4*D2+3*D3)*(D1-4*D2+3*D3);
    H2 = 13/12*(D2-2*D3+D4)*(D2-2*D3+D4) + 1/4*(D2-D4)*(D2-D4);
    H3 = 13/12*(D3-2*D4+D5)*(D3-2*D4+D5) + 1/4*(3*D3-4*D4+D5)*(3*D3-4*D4+D5);
    
    R1 = 1/10*1/((epsilon+H1)*(epsilon+H1));
    R2 = 6/10*1/((epsilon+H2)*(epsilon+H2));
    R3 = 3/10*1/((epsilon+H3)*(epsilon+H3));
    
    w1 = R1/(R1+R2+R3);
    w2 = R2/(R1+R2+R3);
    w3 = R3/(R1+R2+R3);
    
    DxP = w1/3*D1 - (7*w1+w2)/6*D2 + (11*w1+5*w2+2*w3)/6*D3 + (2*w2 + 5*w3)/6*D4 - w3/6*D5;
    
    //---------------------------------------------------------------------
    D1 = (phi[i][j-2][k] - phi[i][j-3][k])/dx;
    D2 = (phi[i][j-1][k] - phi[i][j-2][k])/dx;
    D3 = (phi[i][j][k] - phi[i][j-1][k])/dx;
    D4 = (phi[i][j+1][k] - phi[i][j][k])/dx;
    D5 = (phi[i][j+2][k] - phi[i][j+1][k])/dx;
    
    H1 = 13/12*(D1-2*D2+D3)*(D1-2*D2+D3) + 1/4*(D1-4*D2+3*D3)*(D1-4*D2+3*D3);
    H2 = 13/12*(D2-2*D3+D4)*(D2-2*D3+D4) + 1/4*(D2-D4)*(D2-D4);
    H3 = 13/12*(D3-2*D4+D5)*(D3-2*D4+D5) + 1/4*(3*D3-4*D4+D5)*(3*D3-4*D4+D5);
    
    R1 = 1/10*1/((epsilon+H1)*(epsilon+H1));
    R2 = 6/10*1/((epsilon+H2)*(epsilon+H2));
    R3 = 3/10*1/((epsilon+H3)*(epsilon+H3));
    
    w1 = R1/(R1+R2+R3);
    w2 = R2/(R1+R2+R3);
    w3 = R3/(R1+R2+R3);
    
    DyN = w1/3*D1 - (7*w1+w2)/6*D2 + (11*w1+5*w2+2*w3)/6*D3 + (2*w2 + 5*w3)/6*D4 - w3/6*D5;
    
    //---------------------------------------------------------------------
    D1 = (phi[i][j+3][k] - phi[i][j+2][k])/dx;
    D2 = (phi[i][j+2][k] - phi[i][j+1][k])/dx;
    D3 = (phi[i][j+1][k] - phi[i][j][k])/dx;
    D4 = (phi[i][j][k] - phi[i][j-1][k])/dx;
    D5 = (phi[i][j-1][k] - phi[i][j-2][k])/dx;
    
    H1 = 13/12*(D1-2*D2+D3)*(D1-2*D2+D3) + 1/4*(D1-4*D2+3*D3)*(D1-4*D2+3*D3);
    H2 = 13/12*(D2-2*D3+D4)*(D2-2*D3+D4) + 1/4*(D2-D4)*(D2-D4);
    H3 = 13/12*(D3-2*D4+D5)*(D3-2*D4+D5) + 1/4*(3*D3-4*D4+D5)*(3*D3-4*D4+D5);
    
    R1 = 1/10*1/((epsilon+H1)*(epsilon+H1));
    R2 = 6/10*1/((epsilon+H2)*(epsilon+H2));
    R3 = 3/10*1/((epsilon+H3)*(epsilon+H3));
    
    w1 = R1/(R1+R2+R3);
    w2 = R2/(R1+R2+R3);
    w3 = R3/(R1+R2+R3);
    
    DyP = w1/3*D1 - (7*w1+w2)/6*D2 + (11*w1+5*w2+2*w3)/6*D3 + (2*w2 + 5*w3)/6*D4 - w3/6*D5;
    
    //---------------------------------------------------------------------
    D1 = (phi[i][j][k-2] - phi[i][j][k-3])/dx;
    D2 = (phi[i][j][k-1] - phi[i][j][k-2])/dx;
    D3 = (phi[i][j][k] - phi[i][j][k-1])/dx;
    D4 = (phi[i][j][k+1] - phi[i][j][k])/dx;
    D5 = (phi[i][j][k+2] - phi[i][j][k+1])/dx;
    
    H1 = 13/12*(D1-2*D2+D3)*(D1-2*D2+D3) + 1/4*(D1-4*D2+3*D3)*(D1-4*D2+3*D3);
    H2 = 13/12*(D2-2*D3+D4)*(D2-2*D3+D4) + 1/4*(D2-D4)*(D2-D4);
    H3 = 13/12*(D3-2*D4+D5)*(D3-2*D4+D5) + 1/4*(3*D3-4*D4+D5)*(3*D3-4*D4+D5);
    
    R1 = 1/10*1/((epsilon+H1)*(epsilon+H1));
    R2 = 6/10*1/((epsilon+H2)*(epsilon+H2));
    R3 = 3/10*1/((epsilon+H3)*(epsilon+H3));
    
    w1 = R1/(R1+R2+R3);
    w2 = R2/(R1+R2+R3);
    w3 = R3/(R1+R2+R3);
    
    DzN = w1/3*D1 - (7*w1+w2)/6*D2 + (11*w1+5*w2+2*w3)/6*D3 + (2*w2 + 5*w3)/6*D4 - w3/6*D5;
    
    //---------------------------------------------------------------------
    D1 = (phi[i][j][k+3] - phi[i][j][k+2])/dx;
    D2 = (phi[i][j][k+2] - phi[i][j][k+1])/dx;
    D3 = (phi[i][j][k+1] - phi[i][j][k])/dx;
    D4 = (phi[i][j][k] - phi[i][j][k-1])/dx;
    D5 = (phi[i][j][k-1] - phi[i][j][k-2])/dx;
    
    H1 = 13/12*(D1-2*D2+D3)*(D1-2*D2+D3) + 1/4*(D1-4*D2+3*D3)*(D1-4*D2+3*D3);
    H2 = 13/12*(D2-2*D3+D4)*(D2-2*D3+D4) + 1/4*(D2-D4)*(D2-D4);
    H3 = 13/12*(D3-2*D4+D5)*(D3-2*D4+D5) + 1/4*(3*D3-4*D4+D5)*(3*D3-4*D4+D5);
    
    R1 = 1/10*1/((epsilon+H1)*(epsilon+H1));
    R2 = 6/10*1/((epsilon+H2)*(epsilon+H2));
    R3 = 3/10*1/((epsilon+H3)*(epsilon+H3));
    
    w1 = R1/(R1+R2+R3);
    w2 = R2/(R1+R2+R3);
    w3 = R3/(R1+R2+R3);
    
    DzP = w1/3*D1 - (7*w1+w2)/6*D2 + (11*w1+5*w2+2*w3)/6*D3 + (2*w2 + 5*w3)/6*D4 - w3/6*D5;
    
    
}

double sweepingLF(double*** phi, int N1, int N2, int N3, double* sigma, double**** xs, double dx, double alpha, double beta, double V1, double V2)
{
    int i,j,k,s1,s2,s3;
    double c, p, q, r, H, phiTemp, phiOld, error;
    double DxN, DxP, DyN, DyP, DzN, DzP;
    
    error = 0;
//     N1 = N[0]; N2 = N[1]; N3 = N[2];
    
    
    for (s1=1; s1>=-1; s1-=2 )
    for (s2=1; s2>=-1; s2-=2 )
    for (s3=1; s3>=-1; s3-=2 )
    {
        // LF sweeping module
        for ( i=(s1<0 ? (N1-2):1); (s1<0 ? i>=1:i<=(N1-2)); i+=s1 )
        for ( j=(s2<0 ? (N2-2):1); (s2<0 ? j>=1:j<=(N2-2)); j+=s2 ) 
        for ( k=(s3<0 ? (N3-2):1); (s3<0 ? k>=1:k<=(N3-2)); k+=s3 ) 
        {
            phiOld = phi[i][j][k];
            c = (sigma[0] + sigma[1] + sigma[2])/dx;
            
            DxN = 0; DxP = 0; DyN = 0; DyP = 0; DzN = 0; DzP = 0; 
            
            WENO5(phi, i, j, k, DxN, DxP, DyN, DyP, DzN, DzP, dx);
            
            p = (DxN + DxP)/2;
            q = (DyN + DyP)/2;
            r = (DzN + DzP)/2;
            
            H = (-V1 + V2*cos(xs[i][j][k][2]))*p + V2*sin(xs[i][j][k][2])*q + alpha*abs(xs[i][j][k][1]*p - xs[i][j][k][0]*q - r) - beta*abs(r);

            phiTemp = 1 - H + sigma[0]*(DxN - DxP)/(2) - sigma[1]*(DyN - DyP)/(2) - sigma[2]*(DzN - DzP)/(2);

            phi[i][j][k] = min(phiTemp/c+phiOld , phiOld);

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

        for ( i = 0; i <= (N1-1); i++)
        for ( j = 0; j <= (N2-1); j++)
        {
            phiOld = phi[i][j][0]; 
            phi[i][j][0] = min(max(2*phi[i][j][1] - phi[i][j][2], phi[i][j][2]), phiOld); 
            error = max(error, phiOld - phi[i][j][0]);
            
            phiOld = phi[i][j][N3-1];
            phi[i][j][N3-1] = min(max(2*phi[i][j][N3-2] - phi[i][j][N3-3], phi[i][j][N3-3]), phiOld); 
            error = max(error, phiOld - phi[i][j][N3-1]);
        }
    }
    return error;
}



void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    //---Inside mexFunction---
    //Declarations
    double *phiValues, *sigmaValues, *xsValues;
    double ***phi, *sigma, ****xs;
    const int *N;
	int numIter;
    double dx,alpha,beta,V1,V2,error,TOL;
    int i,j,k,l, N1,N2,N3;

    //double L = 1;
    double numInfty = 1000;
    
    //Get the input
    phiValues   = mxGetPr(prhs[0]);
    sigmaValues = mxGetPr(prhs[1]);
    xsValues    = mxGetPr(prhs[2]);
    dx          = (double)mxGetScalar(prhs[3]);
    alpha       = (double)mxGetScalar(prhs[4]);
    beta        = (double)mxGetScalar(prhs[5]);
    V1          = (double)mxGetScalar(prhs[6]);
    V2          = (double)mxGetScalar(prhs[7]);
    numIter     = (int)mxGetScalar(prhs[8]);
    TOL         = (double)mxGetScalar(prhs[9]);
    
    N           = mxGetDimensions(prhs[0]);
    
    N1 = N[0]; N2 = N[1]; N3 = N[2];
    
    // memory allocation & value assignment
	phi   = (double ***) malloc ( N1 * sizeof(double**));
    sigma = (double *) malloc ( 3 * sizeof(double));
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
        sigma[i] = sigmaValues[i];
    }
    
   
    
    // run LF sweeping algorithm
    for(k=0; k<numIter; k++) 
    {
        error = sweepingLF(phi, N1,N2,N3, sigma, xs, dx, alpha, beta, V1, V2);
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
    free(sigma);
}
