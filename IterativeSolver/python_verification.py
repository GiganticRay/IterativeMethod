import numpy as np
import numpy.linalg as lin

# verificate 4x4 matrix

A = np.matrix([[1, 2, 3, 4], [2, 5, 6, 7], [3, 6, 8, 9], [4, 7, 9, 10]])

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

print(Q.T * H * Q)