/*  K_assmbly assembles the global stiffness matrix [K] together.
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
#ifndef K_ASSMBLY_H
#define K_ASSMBLY_H
#include <armadillo>
using namespace arma;

 mat k_spring(double k_stiff, double theta_x, double theta_y, double theta_z, double node1, double node2, double node_t);
 mat k_truss(double A, double E, double L, double theta_x, double theta_y, double theta_z, double node1, double node2, double node_t);

#endif // K_ASSMBLY_H
