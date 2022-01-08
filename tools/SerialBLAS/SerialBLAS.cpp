#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "string.h"
#include "SerialBLAS.h"

void s_axpby(int length, double alpha, double* x, double beta, double* y, double* result){
	// check the validation of input
	// we can not modify each of parameter during the calculating.
	// Auxiliary parameters
	// alpha_mul_x
	// beta_mul_y
	double* alpha_m_x	= (double*) malloc (sizeof(double) * length);
	double* beta_m_y	= (double*) malloc (sizeof(double) * length);

	if(x == NULL or result == NULL){
		printf("check your input\n");
		exit(-1);
	}

	for(int i = 0; i < length; i++){
		alpha_m_x[i] = alpha * x[i];
	}

	if(y != NULL){
		for(int i = 0; i < length; i++){
			beta_m_y[i]	= beta * y[i];
			result[i] = alpha_m_x[i] + beta_m_y[i];
		}
	}else{
		memcpy(result, alpha_m_x, sizeof(double) * length);
	}
}

double s_norm(int length, double* x, double p){
	// check the validation of input
	if(x == NULL){
		printf("check your input\n");
		exit(-1);
	}
	double norm_result = 0;
	for(int i = 0; i < length; i++){
		norm_result += std::pow(x[i], p);
	}

	return std::pow(norm_result, 1/p);
}


double s_inner_prod(int length, double* x, double* y){
	double d_res = 0;
	for(int i = 0; i < length; i++){
		d_res += x[i] * y[i];
	}
	return d_res;
}
