#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cmath>
#include <iostream>


#include "SerialBLAS.h"
#include "mmio.h"
#include "csparse.h"
#include "IterativeSolver.h"
#include "BasicTools.h"
#include "CycleTimer.h"

using namespace std;

#define RES_THRES 1e-3
#define ITER_TIMES_THRES 3000

int main(){
	// *********************************** load sparse matrix ***************************************
	 
	std::string filePath = "/public/home/LeiChao/Document/IterativeMethod/DATA/Muu/Muu.mtx";

	// filePath = "/public/home/LeiChao/Document/IterativeMethod/DATA/test_data/test_matrx.mtx";

	// filePath = "/public/home/LeiChao/Document/IterativeMethod/DATA/af_shell7/af_shell7.mtx";

	filePath = "/public/home/LeiChao/Document/IterativeMethod/DATA/generated_data.mtx";

	FILE 	*f;
	MM_typecode matcode;
	int 	M, N, nz;
	int 	i, *I, *J;
	double 	*val;
	int 	ret_code;

	if ((f = fopen(filePath.c_str(), "r")) == NULL) 
        exit(1);
	
	// determine the type of matrix being represented in a Matrix Market file
    if (mm_read_banner(f, &matcode) != 0)
    {
        printf("Could not process Matrix Market banner.\n");
        exit(1);
    }

	// get the basic info of sparse matrix
	if ((ret_code = mm_read_mtx_crd_size(f, &M, &N, &nz)) !=0)
        exit(1);

	I = 	(int *) malloc(nz * sizeof(int));
    J = 	(int *) malloc(nz * sizeof(int));
    val = 	(double *) malloc(nz * sizeof(double));

	double start_read_data_time = CycleTimer::currentSeconds();
	for (i=0; i<nz; i++){
        fscanf(f, "%d %d %lg\n", &I[i], &J[i], &val[i]);
        I[i]--;  /* adjust from 1-based to 0-based */
        J[i]--;
    }
    if (f !=stdin) fclose(f);

	// construct csparse data struct
	cs* A 	= (cs*)cs_calloc(1, sizeof(cs));
	A->m	= M;
	A->n	= N;
	A->nzmax= M*N;
	A->p	= J;
	A->i	= I;
	A->x	= val;
	A->nz	= nz;

	tool_Complement_CS(A);
	A = cs_triplet(A);
	double end_read_data_time = CycleTimer::currentSeconds();
	printf("Read data consumes %lf s\n", end_read_data_time - start_read_data_time);

	double *b = (double*) malloc (sizeof(double) * N);
	tool_Generate_Random_vec(N, b);

	double res;
	int iter_times;

	/*
	printf("coeficient matrix is :\n");
	cs_print(A, 1);
	printf("b is: \n");
	s_Print_vec(N, b);
	*/
	
	// cs_print(A, 1);

	GMRES_Solver(RES_THRES, ITER_TIMES_THRES, res, iter_times, A, b);
	double start_GS_time 	= CycleTimer::currentSeconds();
	CG_Solver(RES_THRES, ITER_TIMES_THRES, res, iter_times, A, b);
	double end_GS_time		= CycleTimer::currentSeconds();
	printf("GS Solver consumes %lf s\n", end_GS_time - start_GS_time);

	return 0;
}