What is working:

x_solve.cpp : Solves [F]=[K][x] equation. Solves for unknown elements of matrix [F] (filename boundary/F) and [x] (filename boundary/x). It needs [K] matrix (filename boundary/K) and location of known elements of [F] matrix (from filename boundary/F_locatn). It is assumed correspoding to the values of unknown elements of matrix [x] are known elements of matrix [F] and vise versa.

Files within directory K_assmbly: Assembles global matrix [K] based on assuming truss situation only and output is file boundary/K. It takes Input from folder boundary/F. Does not take into account bending or torsion as of now.

What needs to be done next:

Lots to be done to even get to a basic FEA Project.
1. We need a 3D Modelling program to generate Input files in a human readable format.
2. We need to build the Process Control program to control the sequence of Programs running.
3. We need to add support for bending and torsion of elements.
4. We need to build easy to understand Qt based GUI interfaces.
5. Post processing has not been even touched yet.
