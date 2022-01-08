#include <stdio.h>
#include "csparse.h"

/* Generalized Minimal Residual Method 

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


/* 	Conjugate Gradient
	NOTICE: matrix must be SPD matrix

// algorithm
	initialize x0
	d0 = r0 = b - Ax0
	for n = 0, 1, 2...
		alpha_n	= (r_n, r_n) / (d_n, Ad_n)	
		x_n+1	= x_n + alpha_n * d_n
		r_n+1	= r_n - alpha_n * Ad_n
		beta_n+1= (r_n+1, r_n+1) / (r_n, r_n)
		d_n+1	= r_n+1 + beta_n+1 * d_n

*/
void CG_Solver(double err_thres, int iter_times_thres, double& err, int& iter_times, cs* A, double* b);