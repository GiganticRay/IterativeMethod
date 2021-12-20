// #include "CudaCheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "mmio.h"
#include "SerialBLAS.h"
#include "csparse.h"

#define MIN_VALUE 1e-8
#define IS_DOUBLE_ZERO(d)  (abs(d) < MIN_VALUE)

int main(){
	// *********************************** load sparse matrix ***************************************
	 
	std::string filePath = "/public/home/LeiChao/Document/IterativeMethod/DATA/1138_bus/1138_bus.mtx";

	filePath = "/public/home/LeiChao/Document/IterativeMethod/DATA/arc130/arc130.mtx";
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

	for (i=0; i<nz; i++){
        fscanf(f, "%d %d %lg\n", &I[i], &J[i], &val[i]);
        I[i]--;  /* adjust from 1-based to 0-based */
        J[i]--;
    }
    if (f !=stdin) fclose(f);

	// construct csparse data struct
	

	// bais vector
	#pragma region define_b
	// generation web: https://www.calculatorsoup.com/calculators/statistics/number-generator.php
	// double b[] = {862, 309, 654, 473, 267, 832, 175, 23, 181, 859, 247, 754, 107, 719, 893, 134, 914, 444, 799, 879, 789, 32, 306, 290, 336, 646, 34, 223, 336, 495, 595, 557, 46, 53, 74, 53, 577, 379, 153, 100, 65, 59, 942, 980, 897, 367, 306, 395, 778, 296, 351, 335, 527, 178, 195, 225, 968, 367, 467, 27, 288, 543, 129, 284, 481, 727, 251, 305, 112, 500, 501, 108, 566, 138, 862, 492, 467, 161, 34, 664, 76, 722, 872, 914, 584, 931, 752, 875, 197, 355, 785, 938, 934, 865, 527, 593, 918, 997, 197, 477, 780, 229, 744, 271, 440, 850, 352, 759, 802, 356, 83, 520, 581, 422, 213, 289, 558, 645, 223, 93, 592, 448, 611, 463, 357, 104, 596, 619, 709, 714, 384, 26, 452, 994, 547, 466, 302, 884, 165, 298, 237, 666, 911, 699, 789, 731, 870, 96, 61, 244, 678, 367, 780, 783, 761, 451, 238, 330, 787, 841, 487, 558, 251, 831, 82, 126, 656, 83, 846, 10, 508, 880, 846, 758, 154, 179, 21, 716, 864, 54, 7, 810, 593, 345, 528, 269, 768, 338, 601, 282, 957, 209, 905, 805, 199, 459, 621, 755, 416, 591, 89, 180, 285, 692, 588, 519, 532, 705, 392, 647, 615, 617, 510, 70, 955, 773, 531, 998, 901, 72, 200, 526, 631, 816, 587, 487, 674, 903, 621, 984, 933, 22, 661, 404, 28, 716, 74, 203, 122, 193, 205, 5, 254, 1000, 403, 668, 868, 390, 461, 353, 387, 652, 627, 333, 201, 580, 905, 895, 467, 766, 222, 185, 996, 827, 270, 763, 132, 378, 187, 912, 789, 754, 160, 210, 413, 867, 626, 191, 660, 8, 954, 176, 175, 883, 336, 318, 42, 797, 335, 674, 378, 160, 900, 825, 47, 756, 886, 562, 480, 507, 734, 193, 703, 704, 871, 631, 142, 119, 768, 330, 771, 599, 650, 802, 503, 72, 277, 689, 768, 358, 243, 321, 487, 748, 526, 640, 618, 437, 22, 978, 993, 735, 113, 759, 801, 556, 127, 880, 545, 304, 868, 407, 798, 799, 640, 541, 576, 590, 352, 713, 875, 534, 891, 935, 563, 365, 853, 993, 340, 929, 329, 509, 590, 928, 584, 956, 511, 378, 504, 384, 882, 765, 239, 870, 654, 608, 207, 307, 714, 364, 862, 255, 863, 743, 905, 990, 307, 555, 80, 735, 681, 917, 61, 733, 435, 841, 265, 338, 785, 281, 437, 670, 696, 842, 63, 122, 611, 14, 926, 538, 497, 146, 375, 735, 699, 286, 885, 287, 764, 416, 219, 474, 554, 75, 266, 256, 16, 951, 456, 857, 321, 293, 679, 261, 604, 900, 362, 823, 909, 490, 931, 688, 899, 532, 48, 925, 199, 906, 448, 541, 208, 152, 493, 231, 659, 718, 666, 714, 849, 72, 120, 424, 346, 185, 530, 87, 560, 367, 985, 43, 365, 134, 341, 701, 619, 519, 301, 209, 50, 943, 83, 146, 378, 359, 685, 226, 547, 903, 200, 825, 412, 474, 113, 519, 307, 101, 124, 537, 81, 601, 511, 160, 74, 928, 553, 593, 827, 939, 662, 605, 313, 499, 975, 19, 204, 632, 201, 454, 778, 144, 561, 439, 410, 971, 372, 247, 973, 695, 592, 782, 197, 812, 113, 730, 695, 11, 170, 463, 491, 854, 643, 752, 610, 863, 450, 93, 892, 344, 952, 872, 760, 541, 530, 253, 87, 622, 190, 936, 102, 122, 538, 203, 6, 72, 627, 219, 529, 32, 317, 459, 13, 508, 862, 45, 262, 998, 795, 852, 832, 900, 154, 552, 409, 750, 734, 326, 216, 587, 930, 571, 659, 226, 103, 389, 340, 429, 531, 388, 258, 973, 606, 724, 748, 673, 504, 311, 313, 947, 127, 644, 555, 761, 847, 996, 642, 310, 959, 880, 287, 952, 994, 71, 980, 696, 790, 891, 208, 404, 463, 118, 678, 999, 747, 785, 28, 462, 689, 697, 161, 96, 639, 794, 630, 397, 255, 600, 395, 389, 581, 116, 180, 560, 812, 243, 301, 142, 86, 172, 23, 854, 672, 325, 584, 903, 956, 179, 125, 764, 146, 777, 872, 101, 364, 169, 613, 77, 738, 445, 296, 73, 783, 821, 166, 377, 654, 675, 453, 10, 435, 678, 843, 405, 807, 625, 327, 287, 865, 469, 306, 816, 414, 154, 362, 510, 120, 441, 333, 707, 384, 243, 113, 891, 298, 748, 791, 278, 79, 52, 689, 889, 432, 468, 990, 736, 637, 66, 831, 255, 911, 81, 272, 642, 248, 397, 573, 632, 820, 213, 733, 121, 207, 888, 451, 966, 611, 700, 967, 193, 304, 7, 57, 861, 197, 263, 148, 362, 635, 358, 134, 145, 165, 202, 990, 665, 302, 164, 32, 569, 935, 378, 958, 905, 204, 429, 567, 292, 51, 390, 973, 5, 669, 413, 820, 611, 118, 427, 404, 714, 54, 376, 710, 942, 476, 495, 674, 691, 673, 220, 912, 508, 123, 28, 516, 341, 406, 511, 637, 276, 374, 559, 922, 122, 252, 487, 274, 414, 990, 970, 860, 777, 92, 888, 548, 260, 248, 206, 9, 738, 35, 670, 54, 588, 156, 14, 24, 577, 986, 615, 752, 663, 351, 813, 219, 643, 402, 249, 558, 376, 145, 559, 988, 422, 738, 832, 781, 979, 965, 39, 616, 926, 833, 853, 490, 266, 866, 41, 585, 231, 70, 997, 737, 853, 425, 304, 534, 145, 117, 25, 600, 726, 237, 199, 269, 702, 795, 220, 315, 23, 838, 341, 363, 622, 120, 744, 185, 99, 430, 42, 412, 183, 688, 598, 580, 838, 299, 170, 949, 941, 546, 228, 487, 908, 860, 563, 81, 766, 481, 412, 626, 43, 626, 401, 229, 301, 67, 77, 175, 585, 737, 567, 196, 170, 821, 995, 693, 548, 942, 749, 680, 160, 70, 832, 469, 51, 465, 432, 666, 791, 477, 398, 189, 336, 637, 532, 58, 389, 466, 96, 510, 508, 78, 592, 912, 601, 888, 992, 793, 909, 30, 981, 955, 664, 665, 257, 576, 726, 171, 925, 26, 5, 552, 755, 846, 51, 136, 635, 724, 446, 432, 941, 345, 982, 356, 429, 4, 383, 152, 594, 777, 671, 105, 795, 700, 257, 566, 502, 292, 791, 137, 244, 680, 413, 293, 234, 554, 230, 58, 576, 638, 910, 641, 200, 555, 493, 723, 530, 149, 316, 242, 561, 430, 483, 655, 99, 957, 631, 542, 238, 897, 453, 344, 720, 401, 213, 78, 297, 970, 699, 217, 416, 682, 906, 329, 677, 654, 823, 576, 804, 301, 693, 118, 273, 879, 119, 767, 971, 69, 577, 944, 854, 803, 544, 275, 499, 196, 984, 76, 191, 62, 184, 711, 530, 934, 505, 663, 383, 999, 322, 519, 36, 158, 598, 196, 463, 148, 782, 795, 53, 871, 8, 309, 105, 968, 258, 587, 494, 173, 680, 790, 600, 545, 245, 703, 464, 325, 10, 560, 611, 541, 926, 79, 307, 568, 247, 236, 527, 822, 544, 743, 468, 676, 179, 429, 517, 433, 264, 683, 449} ;
	double b[] = {30, 962, 870, 391, 49, 462, 827, 116, 64, 738, 671, 867, 976, 354, 660, 677, 214, 235, 192, 36, 858, 766, 130, 777, 442, 37, 362, 903, 387, 392, 655, 205, 422, 87, 947, 151, 399, 529, 153, 413, 249, 860, 794, 661, 344, 987, 909, 427, 238, 468, 369, 196, 988, 146, 792, 76, 697, 359, 53, 516, 852, 586, 254, 370, 284, 405, 327, 24, 185, 143, 388, 451, 335, 154, 325, 94, 284, 334, 409, 265, 581, 120, 567, 452, 307, 533, 858, 25, 970, 739, 961, 754, 797, 35, 906, 755, 622, 778, 759, 342, 418, 294, 86, 257, 10, 275, 615, 507, 204, 540, 424, 84, 499, 567, 716, 148, 341, 283, 815, 572, 369, 445, 7, 961, 772, 502, 798, 699, 809, 30};
	#pragma endregion define_b
	

	/* GMRES 

	// algorithm
	q1 = b/norm(b);		// s_axpy, s_norm
	for n = 1, 2, 3...
		// step n of Arnoldi Iteration, Algorithm 33.1
		// updata Hn and Qn
		v = Aqn;		// cuda_mv
		for j = 1 to n
			h_jn 	= q_j • v			// s_vv
			v 		= v - h_jn • qj		// axpy
		
		h_n+1, n 	= norm(v)
		q_n+1		= v/h_n+1, n		

		// find y to minimize norm(r_n), which is equivalant to solve a triagonal problem
		x_n 		= Q_n • y			// s_mv
	*/

	return 0;
}