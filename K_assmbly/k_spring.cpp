#include <math.h>
#include <armadillo>
#include "k_assmbly.h"
#include <iostream>
using namespace arma ;

mat k_spring(double k_stiff, double theta_x, double theta_y, double theta_z, double node1, double node2, double node_t)
{
  mat  k, lambda;
  int n1, n2;
  double Cx, Cy, Cz;
  Cx = cos(theta_x/180.0*M_PI) ;
  Cy = cos(theta_y/180.0*M_PI) ;
  Cz = cos(theta_z/180.0*M_PI) ;
  k = zeros<mat>(3*node_t,3*node_t) ;
  n1 = 3*node1-1 ;
  n2 = 3*node2-1 ;
  lambda ={{pow(Cx,2), Cx*Cy, Cx*Cz}, {Cy*Cx, pow(Cy,2), Cy*Cz}, {Cz*Cx, Cz*Cy, pow(Cz, 2)}};
  lambda =k_stiff*lambda;
  k(span(n1-2,n1), span(n1-2,n1)) = lambda ;
  k(span(n1-2,n1), span(n2-2,n2)) = -lambda ;
  k(span(n2-2,n2), span(n1-2,n1)) = -lambda ;
  k(span(n2-2,n2), span(n2-2,n2)) = lambda ;
  return k ;
}
