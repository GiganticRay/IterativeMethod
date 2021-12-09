#include "CudaCheck.h"
#include <cusparse.h>
#include <stdio.h>
#include <stdlib.h>
#include "mmio.h"
#include <string>

int main(){
	// load sparse matrix 
	std::string filePath = "/public/home/LeiChao/Document/IterativeMethod/DATA/1138_bus/1138_bus.mtx";
	FILE *f;
	MM_typecode matcode;
	int M, N, nz;
	int i, *I, *J;
	double *val;
	int ret_code;

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

	I = (int *) malloc(nz * sizeof(int));
    J = (int *) malloc(nz * sizeof(int));
    val = (double *) malloc(nz * sizeof(double));

	for (i=0; i<nz; i++){
        fscanf(f, "%d %d %lg\n", &I[i], &J[i], &val[i]);
        I[i]--;  /* adjust from 1-based to 0-based */
        J[i]--;
    }

    if (f !=stdin) fclose(f);

	return 0;
}