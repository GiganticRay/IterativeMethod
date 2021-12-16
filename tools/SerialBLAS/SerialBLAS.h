/*
	execute basic result = alpha*x + beta*y

	parameters:
		length:	dim of vector
		alpha:
		x:
		beta:
		y:
		result:	put the final result into this array
	
	usage: 
		scalar vec multiplication:
			axpby(alpha, x, 0, null, result)
	
	limitation: we will update this function 
*/
void s_axpby(int length, double alpha, double* x, double beta, double* y, double* result);

/*
	return p-norm of array x

	parameters:
		length:	dim of vector
		x: 		pending operating array
		p: 		p-norm
	
	return:
		p-norm of array x
*/
double s_norm(int length, double* x, double p);