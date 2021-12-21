#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "SerialBLAS.h"

void s_axpby(int length, double alpha, double* x, double beta, double* y, double* result){
	// check the validation of input
	if(x == NULL or result == NULL){
		printf("check your input\n");
		exit(-1);
	}

	for(int i = 0; i < length; i++){
		result[i] = alpha * x[i];
	}

	if(y != NULL){
		for(int i = 0; i < length; i++){
			result[i] += beta * y[i];
		}
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

template <typename elemType>
void s_Print_vec(int length, elemType* array){
	printf("length is %d \n", length);
	for(int i = 0; i < length; i++){
		std::cout << array[i] << "\t";
	}
	printf("\n\n");
}
template void s_Print_vec<int>(int length, int* array);
template void s_Print_vec<double>(int length, double* array);