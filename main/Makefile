CC		=	gcc
NVCC	=	nvcc	
CPLUSCC	=	g++

# set compile flag
# http://blog.sina.com.cn/s/blog_54f82cc201011op1.html
# I put CSPARSE out of my working directory since it is not my work
CSparseFLAG	=	-static
SMIOFLAG	=	-static
serialBLASFLAG	=	-static
BasicToolsFLAG	=	-static
CUFLAG		=	-g -lcudart -lcusparse

# set PATH
CSparsePATH	=	~/Document/CSPARSE
MMIOPATH	=	~/Document/IterativeMethod/tools/MMIO
SerialBLASPATH	=	~/Document/IterativeMethod/tools/SerialBLAS
IterativeSolverPATH	=	~/Document/IterativeMethod/IterativeSolver
BasicToolsPATH	=	~/Document/IterativeMethod/tools/BasicTools

# set include path
IncPATH		=	-I /public/home/LeiChao/Document/IterativeMethod/tools \
				-I ${MMIOPATH} \
				-I ${SerialBLASPATH} \
				-I ${CSparsePATH} \
				-I ${IterativeSolverPATH} \
				-I ${BasicToolsPATH}

# compiling task
main:	main.cpp ${CSparsePATH}/csparse.c ${MMIOPATH}/mmio.c ${SerialBLASPATH}/SerialBLAS.cpp ${IterativeSolverPATH}/IterativeSolver.cpp ${BasicToolsPATH}/BasicTools.cpp
	${CPLUSCC} ${IncPATH} main.cpp ${CSparsePATH}/csparse.c ${MMIOPATH}/mmio.c ${SerialBLASPATH}/SerialBLAS.cpp ${IterativeSolverPATH}/IterativeSolver.cpp ${BasicToolsPATH}/BasicTools.cpp -o main -g -fpermissive

clean:
	rm *.a main
