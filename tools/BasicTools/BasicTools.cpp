#include "BasicTools.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include <iostream>	// needed to use std::cout
using namespace std;

template <typename elemType>
void tool_Print_vec(int length, elemType* array){
	printf("length is %d \n", length);
	for(int i = 0; i < length; i++){
		std::cout << array[i] << "\t";
	}
	printf("\n\n");
}
template void tool_Print_vec<int>(int length, int* array);
template void tool_Print_vec<double>(int length, double* array);

void tool_Generate_Random_vec(int length, double* b){
	if(b == NULL){
		exit(-1);
	}
	for(int n = 0; n < length; n++){
		b[n] = rand() % 1000 ;
	}
}

void tool_Complement_CS(cs* s){
	int add_nz	= 0;	// add is additional
	int* add_p	= (int*) malloc (sizeof(int) * s->nz); 
	int* add_i 	= (int*) malloc (sizeof(int) * s->nz);
	double* add_x	= (double*) malloc (sizeof(double) * s->nz);

	for(int i = 0; i < s->nz; i++){
		if(s->p[i] != s->i[i]){
			add_p[add_nz] 	= s->i[i];
			add_i[add_nz] 	= s->p[i];
			add_x[add_nz]	= s->x[i];		 
			add_nz 		+= 1;
		}
	}

	int  total_nz	= s->nz + add_nz;
	int* total_p 	= (int*) malloc (sizeof(int) * total_nz);
	int* total_i 	= (int*) malloc (sizeof(int) * total_nz);
	double* total_x = (double*) malloc (sizeof(double) * total_nz);

	memcpy(total_p, 		s->p, 	sizeof(int) * s->nz);
	memcpy(total_p + s->nz, add_p, 	sizeof(int) * add_nz);	

	memcpy(total_i, 		s->i, 	sizeof(int) * s->nz);
	memcpy(total_i + s->nz, add_i, 	sizeof(int) * add_nz);	

	memcpy(total_x, 		s->x, 	sizeof(double) * s->nz);
	memcpy(total_x + s->nz, add_x, 	sizeof(double) * add_nz);	

	s->p 	= total_p;
	s->i 	= total_i;
	s->x 	= total_x;
	s->nz 	= total_nz;
}