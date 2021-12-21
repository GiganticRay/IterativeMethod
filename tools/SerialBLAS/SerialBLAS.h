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

/*
	execute basic result = <x, y>

	parameters:
		length:	dim of vector
		x:
		y:
	return:
		result:	result of <x, y>
*/
double s_inner_prod(int length, double* x, double* y);

/*
	Print vector
	how to seperate definition and declaration of template method: 
	http://www.cs.technion.ac.il/users/yechiel/c++-faq/separate-template-fn-defn-from-decl.html

	what does compilier do when coping with template method: 
	http://www.cs.technion.ac.il/users/yechiel/c++-faq/templates-defn-vs-decl.html
*/
template <typename elemType>
void s_Print_vec(int length, elemType* array);

