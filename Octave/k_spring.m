#Used to put values of k in the global Stiffness matrix K.
#Takes spring stiffness, angle with x axis, node number 1, node number 2 and 
#total number of nodes as argument.
function k=k_spring(k_stiff,theta,node1,node2,node_t)
C=cosd(theta); 
S=sind(theta);
k=zeros(2*node_t);
#The right positions of k generally ranges from 2n-1 to 2n where n is node number.
n1=2*node1;
n2=2*node2;
lambda=k_stiff*[C^2,C*S;C*S,S^2];
#Puts the values in the right positions.
k(n1-1:n1,n1-1:n1)=lambda; 
k(n1-1:n1,n2-1:n2)=-lambda;
k(n2-1:n2,n1-1:n1)=-lambda;
k(n2-1:n2,n2-1:n2)=lambda;
endfunction
