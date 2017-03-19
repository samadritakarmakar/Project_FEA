#include <iostream>
#include <armadillo>
using namespace arma ;

int main()
{
    mat x, F_locatn, K, F;
    x.load("boundary/x");
    //cout<<"x\n"<<x;
    F_locatn.load("boundary/F_locatn");
    //cout<<"F_locatn'n"<<F_locatn;
    K.load("boundary/K");
    //cout<<"K\n"<<K;
    F.load("boundary/F");
    //cout<<"F\n"<<F;
    mat F_stub, K_stub, x_stub ;
    int i, j, l;
    l = F_locatn.n_elem ;
    F = F-K*x ;
    K_stub = arma::zeros<mat>(l,l) ;
    F_stub = arma::zeros<mat>(l,1) ;
    x_stub = arma::zeros<mat>(l,1) ;
    for (i=0; i<=l-1; i++)
    {
        F_stub(i, 0) = F(F_locatn(i)-1) ;
        for (j=0; j<=l-1; j++)
        {
            K_stub(i, j) = K(F_locatn(i)-1, F_locatn(j)-1) ;
            x_stub = solve(K_stub,F_stub) ;
        }
    }
    //cout<<"K_stub\n"<<K_stub;
    //cout<<"F_stub\n"<<F_stub;
    for (i=0; i<=l-1; i++)
    {
        x(F_locatn(i)-1) = x_stub(i) ;
    }
    F=K*x;
    F.save("output/F_solved", raw_ascii);
    x.save("output/x_solved", raw_ascii);
  return 0 ;
}
