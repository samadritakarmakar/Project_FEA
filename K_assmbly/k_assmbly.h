#ifndef K_ASSMBLY_H
#define K_ASSMBLY_H
#include <armadillo>
using namespace arma;

 mat k_spring(double k_stiff, double theta_x, double theta_y, double theta_z, double node1, double node2, double node_t);
 mat k_truss(double A, double E, double L, double theta_x, double theta_y, double theta_z, double node1, double node2, double node_t);

#endif // K_ASSMBLY_H
