#include <stdio.h>
#include "csparse.h"

/* GMRES 

// algorithm
q1 = b/norm(b);		// s_axpy, s_norm
for n = 1, 2, 3...
	// step n of Arnoldi Iteration, Algorithm 33.1
	// updata Hn and Qn
	v = Aqn;		// cuda_mv
	for j = 1 to n
		h_jn 	= q_j • v			// s_vv
		v 		= v - h_jn • qj		// axpy
	
	h_n+1, n 	= norm(v)			// s_norm
	q_n+1		= v/h_n+1, n		// s_axpy

	// find y to minimize norm(r_n), which is equivalant to solve a triagonal problem
	x_n 		= Q_n • y			// s_mv
*/
void GMRES_Solver(double res_thres, int iter_times_thres, double& res, int & iter_times, cs* A, double* b);