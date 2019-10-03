function phi = CompBoundary(phi,N,dim)


for j = 1:N(2)
    phi(3,j) = min(max(2*phi(3,j) - phi(5,j), phi(5,j)), phi(3,j));
    phi(2,j) = min(max(2*phi(3,j) - phi(4,j), phi(4,j)), phi(2,j)); 
    phi(1,j) = min(max(2*phi(2,j) - phi(3,j), phi(3,j)), phi(1,j)); 
    phi(N(1)-2,j) = min(max(2*phi(N(1)-3,j) - phi(N(1)-4,j), phi(N(1)-4,j)), phi(N(1)-2,j)); 
    phi(N(1)-1,j) = min(max(2*phi(N(1)-2,j) - phi(N(1)-3,j), phi(N(1)-3,j)), phi(N(1)-1,j)); 
    phi(N(1),j) = min(max(2*phi(N(1)-1,j) - phi(N(1)-2,j), phi(N(1)-2,j)), phi(N(1),j)); 
end

for i = 1:N(1)
   phi(i,3) = min(max(2*phi(j,4) - phi(j,5), phi(j,5)), phi(j,3)); 
   phi(i,2) = min(max(2*phi(j,3) - phi(j,4), phi(j,4)), phi(j,2)); 
   phi(i,1) = min(max(2*phi(j,2) - phi(j,3), phi(j,3)), phi(j,1)); 
   phi(i,N(2)-2) = min(max(2*phi(i,N(2)-3) - phi(i,N(2)-4), phi(i,N(2)-4)), phi(i,N(1)-2)); 
   phi(i,N(2)-1) = min(max(2*phi(i,N(2)-2) - phi(i,N(2)-3), phi(i,N(2)-3)), phi(i,N(1)-1)); 
   phi(i,N(2)) = min(max(2*phi(i,N(2)-1) - phi(i,N(2)-2), phi(i,N(2)-2)), phi(i,N(1))); 
end

