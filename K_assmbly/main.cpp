#include <armadillo>
#include "k_assmbly.h"
//#include <istream>
using namespace arma;
int main()
{
    mat elem_t, node_t, node1, node2, type, theta_x, theta_y, theta_z, A, E, L, k_stiff, K;
    elem_t.load("input/elem_t");
    node_t.load("input/node_t");
    node1.load("input/node1");
    node2.load("input/node2");
    type.load("input/type");
    theta_x.load("input/theta_x");
    theta_y.load("input/theta_y");
    theta_z.load ("input/theta_z");
    A.load ("input/A");
    E.load ("input/E");
    L.load ("input/L");
    k_stiff.load ("input/k_stiff");

    K = zeros<mat>(3*node_t(0),3*node_t(0)) ;
    for (int i=1; i<=elem_t(0); i++)
    {
        if(type(i-1)==1)
        {
            K=K+k_spring(k_stiff(i-1),theta_x(i-1),theta_y(i-1),theta_z(i-1),node1(i-1),node2(i-1),node_t(0));
            //cout<<"\nSpring\n"<<k_spring(k_stiff(i-1),theta_x(i-1),theta_y(i-1),theta_z(i-1),node1(i-1),node2(i-1),node_t(0));
        }
        else if (type(i-1)==2)
        {
            K=K+k_truss(A(i-1),E(i-1),L(i-1),theta_x(i-1),theta_y(i-1),theta_z(i-1),node1(i-1),node2(i-1),node_t(0));
            //cout<<"\nTruss\n"<<k_truss(A(i-1),E(i-1),L(i-1),theta_x(i-1),theta_y(i-1),theta_z(i-1),node1(i-1),node2(i-1),node_t(0));
        }
    }

    K.save("boundary/K", raw_ascii);
}
