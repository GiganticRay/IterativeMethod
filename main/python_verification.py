from typing import IO
import numpy as np
import numpy.linalg as lin
from numpy.matrixlib import mat
import scipy
import sklearn.datasets as sk_ds
from scipy import sparse


# verificate 4x4 matrix

def test_data_verify():
	A = np.matrix([[1, 1, 1, 1], [1, 2, 3, 4], [1, 3, 6, 10], [1, 4, 10, 20]])

	x = np.matrix([108.991, -95.978, 110.982, -40.9949]).T

	print(A * x)

	q0 		= np.array([0.219476, 0.438951, 0.570637, 0.658427])
	q1 = np.array([0.615624, 0.399627, 0.203499, -0.647992])
	q2 = np.array([-0.747012, 0.339436, 0.443018, -0.361235])
	q3 = np.array([-0.121696, 0.72966, -0.660831, 0.126845])

	Q = np.array([q0, q1, q2, q3])
	Q = np.matrix(Q)

	h0 = np.array([24.0597, 0.263913, 0, 0])
	h1 = np.array([0.18196, -0.649195, 0.276927, 0])
	h2 = np.array([0.00414149, 0.281146, 0.465795, 0.0826907])
	h3 = np.array([-0.024276, 0.039266, 0.148455, 0.373343])

	H = np.array([h0, h1, h2, h3])
	H = np.matrix(H)

def scipy_generate_spd_m(m):
	# https://docs.scipy.org/doc/scipy/reference/sparse.html
	# https://scikit-learn.org/stable/modules/generated/sklearn.datasets.make_sparse_spd_matrix.html
	a = sk_ds.make_sparse_spd_matrix(m, alpha = 0.99)
	# a = sk_ds.make_spd_matrix(m)
	sa = sparse.coo_matrix(a)

	# https://docs.scipy.org/doc/scipy/reference/generated/scipy.io.mmwrite.html
	scipy.io.mmwrite("/public/home/LeiChao/Document/IterativeMethod/DATA/generated_data.mtx", sa)

def self_generate_spd_m(m):
	f = open("/public/home/LeiChao/Document/IterativeMethod/DATA/generated_data.mtx", "w")
	f.write("%%MatrixMarket matrix coordinate real symmetric\n")
	f.write("{}\t{}\t{}\n".format(m, m, m))
	for i in range(1, m+1):
		f.write("{}\t{}\t{}\n".format(i, i, i))
	f.close()



def verify_spd(m):
	print(np.linalg.eigvals(m))
	return np.all(np.linalg.eigvals(m) > 0)

if __name__ == "__main__":
	scipy_generate_spd_m(1000)
	# self_generate_spd_m(1000)
	# a = scipy.io.mmread("/public/home/LeiChao/Document/IterativeMethod/DATA/generated_data.mtx").todense()
	# print(verify_spd(a))