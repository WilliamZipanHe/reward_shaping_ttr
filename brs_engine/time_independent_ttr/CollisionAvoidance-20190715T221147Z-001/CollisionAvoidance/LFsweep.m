function phi = LFsweep(phi,N,sigma,xs,dx,dim)

global alpha; global beta;


diff = 1e7;
iter = 0;



while(diff > 1e-10)
    phi0 = phi;
    %LB->RT
    for i = 4:N(1)-3
        for j = 4:N(2)-3
            phiOld = phi(i,j);
            c = sum(sigma)/dx;
            
            [DxN,DxP,DyN,DyP] = WENO5(phi,i,j,dx);
            
            p = (DxN + DxP)/2;
            q = (DyN + DyP)/2;
            H = (-alpha + beta) * sqrt(p^2 + q^2) - 1;
            phiTemp = 1/c*(-H - sigma(1)*(DxN - DxP)/2 - sigma(2)*(DyN - DyP)/2) + phiOld;
            phi(i,j) = min(phiTemp, phiOld);

        end
    end
    %computational boundary
    phi = CompBoundary(phi,N);
    
    %RB->LT
    for i = N(1)-3:-1:4
        for j = 4:N(2)-3

           phiOld = phi(i,j);
            c = sum(sigma)/dx;
            
            [DxN,DxP,DyN,DyP] = WENO5(phi,i,j,dx);
            
            p = (DxN + DxP)/2;
            q = (DyN + DyP)/2;
            H = (-alpha + beta) * sqrt(p^2 + q^2) - 1;
            phiTemp = 1/c*(-H - sigma(1)*(DxN - DxP)/2 - sigma(2)*(DyN - DyP)/2) + phiOld;
            phi(i,j) = min(phiTemp, phiOld);

        end
    end
    %computational boundary
    phi = CompBoundary(phi,N);
    
    %LT->RB
    for i = 4:N(1)-3
        for j = N(2)-3:-1:4

            phiOld = phi(i,j);
            c = sum(sigma)/dx;
            
            [DxN,DxP,DyN,DyP] = WENO5(phi,i,j,dx);
            
            p = (DxN + DxP)/2;
            q = (DyN + DyP)/2;
            H = (-alpha + beta) * sqrt(p^2 + q^2) - 1;
            phiTemp = 1/c*(-H - sigma(1)*(DxN - DxP)/2 - sigma(2)*(DyN - DyP)/2) + phiOld;
            phi(i,j) = min(phiTemp, phiOld);
            
        end
    end
    %computational boundary
    phi = CompBoundary(phi,N);
    
    %RT->LB
    for i = N(1)-3:-1:4
        for j = N(2)-3:-1:4

            phiOld = phi(i,j);
            c = sum(sigma)/dx;
            
            [DxN,DxP,DyN,DyP] = WENO5(phi,i,j,dx);
            
            p = (DxN + DxP)/2;
            q = (DyN + DyP)/2;
            H = (-alpha + beta) * sqrt(p^2 + q^2) - 1;
            phiTemp = 1/c*(-H - sigma(1)*(DxN - DxP)/2 - sigma(2)*(DyN - DyP)/2) + phiOld;
            phi(i,j) = min(phiTemp, phiOld);
            
        end
    end
    %computational boundary
    phi = CompBoundary(phi,N);

    diff = sum(sum(abs(phi0-phi)));

end



 