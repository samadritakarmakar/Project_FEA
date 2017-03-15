function x=x_solve(x,F_locatn,K,F)
 l=length(F_locatn)
 F=F-K*x;
 K_stub=zeros(l);
 F_stub=zeros(l,1);
 x_stub=zeros(l,1);
 for i=1:l
 F_stub(i,1)=F(F_locatn(i));
  for j=1:l
   K_stub(i,j)=K(F_locatn(i),F_locatn(j));
  endfor
 endfor
 x_stub=K_stub\F_stub;
 
 for i=1:l
  x(F_locatn(i))=x_stub(i);
 endfor

   