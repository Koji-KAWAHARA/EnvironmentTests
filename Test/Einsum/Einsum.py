"""Program to check computation time of dot and cross product."""
import numpy as np
import time
"""
Conclusion : LOOPMETHOD WINS! (when system is bigger.)
result(faster) : d: dotmethod, l : for-loop
            dot     cross
N = 10      l       d
N = 100     d       d
N =1000     l       d
N =5000     l       l
N =10000    l       l
N =20000    l       l
"""


N = 20000
A = np.random.rand(3*N).reshape(N, 3)
B = np.random.rand(3*N).reshape(N, 3)
# C = np.array([1,2,3,4,5,6,7,8]).reshape(2,4)
# C
# array([[1, 2, 3, 4],
#        [5, 6, 7, 8]])
# C[1]
# array([5, 6, 7, 8])


def ndot_time(A, B):
    """Dot product."""
    AdB1 = np.zeros(N)
    start = time.time()
    for i in range(N):
        AdB1[i] = A[i].dot(B[i].T)
    time1 = time.time()-start

    start = time.time()
    AdB1 = np.diag(A.dot(B.T))
    time2 = time.time()-start

    # print(np.sum(AdB1-AdB2))
    print("dot prod (forloop-lin.arg.):  "+str(time1-time2))


def ncross_time(A, B):
    """Cross product."""
    AcB1 = np.zeros(3*N).reshape(N, 3)
    e1 = np.array([[0, 0, 0], [0, 0, 1], [0, -1, 0]])
    e2 = np.array([[0, 0, -1], [0, 0, 0], [1, 0, 0]])
    e3 = np.array([[0, 1, 0], [-1, 0, 0], [0, 0, 0]])

    start = time.time()
    for i in range(N):
        AcB1[i] = np.cross(A[i], B[i])
    time1 = time.time()-start

    start = time.time()
    AcB2 = np.stack([np.diag(A.dot(e1).dot(B.T)), np.diag(A.dot(e2).dot(B.T)), np.diag(A.dot(e3).dot(B.T))]).T
    time2 = time.time()-start

    # print(np.sum(AcB1-AcB2))
    print("cross prod (forloop - lin.arg.):  "+str(time1-time2))


"""mainpart"""
ndot_time(A, B)
ncross_time(A, B)
