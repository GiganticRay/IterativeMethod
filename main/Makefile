CC		=	gcc
NVCC	=	nvcc	
CPLUSCC	=	g++

# set compile flag
# http://blog.sina.com.cn/s/blog_54f82cc201011op1.html
# I put CSPARSE out of my working directory since it is not my work
CSparseFLAG	=	-static
SMIOFLAG	=	-static
SerialBLASFLAG		=	-static
IterativeSolverFLAG	=	-static
CUFLAG		=	-g -lcudart -lcusparse

# set PATH
CSparsePATH	=	~/Document/CSPARSE
MMIOPATH	=	~/Document/IterativeMethod/tools/MMIO
SerialBLASPATH		=	~/Document/IterativeMethod/tools/SerialBLAS
IterativeSolverPATH	=	~/Document/IterativeMethod/IterativeSolver

# set include path
IncPATH		=	-I ~/Document/IterativeMethod/tools \
				-I ${MMIOPATH} \
				-I ${CSparsePATH} \
				-I ${IterativeSolverPATH} \
				-I ${SerialBLASPATH}

LibIterativeSolverIncPATH = -I ${SerialBLASPATH} \
							-I ${CSparsePATH} \
							-I ${IterativeSolverPATH}

# set library path
LibPATH		=	-L  ~/Document/IterativeMethod/main

# specify which shared object to use
Lib			=	-l MMIO	\
				-l CSparse \
				-l IterativeSolver \
				-l SerialBLAS

# compiling task
main:	main.cpp libCSparse.a libMMIO.a libSerialBLAS.a libIterativeSolver.a
	${CPLUSCC} ${IncPATH} main.cpp ${LibPATH} ${Lib} -o main -g

libIterativeSolver.a: ${IterativeSolverPATH}/IterativeSolver.cpp
	${CPLUSCC} ${LibIterativeSolverIncPATH} ${IterativeSolverFLAG} -c ${IterativeSolverPATH}/IterativeSolver.cpp -o libIterativeSolver.a

libCSparse.a: ${CSparsePATH}/csparse.c
	${CC} ${CSparseFLAG} -c ${CSparsePATH}/csparse.c -o libCSparse.a

libMMIO.a:	${MMIOPATH}/mmio.c
	${CC} ${MMIOFLAG} -c ${MMIOPATH}/mmio.c -o libMMIO.a

libSerialBLAS.a:	${SerialBLASPATH}/SerialBLAS.cpp
	${CPLUSCC} ${SerialBLASFLAG} -c ${SerialBLASPATH}/SerialBLAS.cpp -o libSerialBLAS.a

clean:
	rm *.a main