CC		=	gcc
NVCC	=	nvcc	
CPLUSCC	=	g++

# set compile flag
# http://blog.sina.com.cn/s/blog_54f82cc201011op1.html
# I put CSPARSE out of my working directory since it is not my work
CSparseFLAG	=	-static
SMIOFLAG	=	-static
serialBLASFLAG	=	-static
CUFLAG		=	-g -lcudart -lcusparse

# set PATH
CSparsePATH	=	~/Document/CSPARSE
MMIOPATH	=	~/Document/IterativeMethod/tools/MMIO
SerialBLASPATH	=	~/Document/IterativeMethod/tools/SerialBLAS

# set include path
IncPATH		=	-I /public/home/LeiChao/Document/IterativeMethod/tools \
				-I ${MMIOPATH} \
				-I ${SerialBLASPATH} \
				-I ${CSparsePATH}

# set library path
LibPATH		=	-L  /public/home/LeiChao/Document/IterativeMethod/IterativeSolver

# specify which shared object to use
Lib			=	-l mmio	\
				-l serialBLAS \
				-l csparse

# compiling task
Solver:	Solver.cpp libcsparse.a libmmio.a libserialBLAS.a
	${CPLUSCC} ${IncPATH} Solver.cpp ${LibPATH} ${Lib} -o Solver -g

libcsparse.a: ${CSparsePATH}/csparse.c
	${CC} ${CSparseFLAG} -c ${CSparsePATH}/csparse.c -o libcsparse.a

libmmio.a:	${MMIOPATH}/mmio.c
	${CC} ${MMIOFLAG} -c ${MMIOPATH}/mmio.c -o libmmio.a

libserialBLAS.a:	${SerialBLASPATH}/SerialBLAS.cpp
	${CPLUSCC} ${SerialBLASFLAG} -c ${SerialBLASPATH}/SerialBLAS.cpp -o libserialBLAS.a

clean:
	rm *.a Solver
