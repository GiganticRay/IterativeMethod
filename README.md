# IterativeMethod
Experiments over Iterative Methods

## directory tree

├── **DATA** <br> 
│   &emsp; └── 1138_bus <br>
│   &emsp; └── 1138_bus.mtx <br>
├── **IterativeSolver** <br>
│   &emsp; └── Solver.cu <br>
├── README.md <br>
├── **TEST** <br>
│   &emsp; ├── testc.c <br>
│   &emsp; ├── testc.h <br>
│   &emsp; ├── testc.o <br>
│   &emsp; ├── testmain <br>
│   &emsp; └── testmain.cu <br>
└── **tools** <br>
    &emsp; ├── CudaCheck.h <br>
    &emsp; └── MMIO <br>
        &emsp;&emsp;&emsp; ├── example_read.c <br>
        &emsp;&emsp;&emsp; ├── example_write.c <br>
        &emsp;&emsp;&emsp; ├── mmio.c <br>
        &emsp;&emsp;&emsp; └── mmio.h <br>
> where **Data** is local [Florida Sparse data set] contains Sparse matrix; **IterativeSolver**  contains implementations of iterative Methods; **TEST** is the debug test directory over CUDA-C-C++. **tools** contains CUDA-HELPER and some other tools. **MMIO** contains IO helper of [Matrix Market].


[Florida Sparse data set]: https://sparse.tamu.edu/
[Matrix Market]: https://math.nist.gov/MatrixMarket/mmio-c.html