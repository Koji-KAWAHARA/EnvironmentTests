#cython: profile=True
#cython: boundscheck=False
#cython: wraparound=False
#cython: noncheck=False
#cython: language_level=3
import numpy as np
cimport numpy as np

INT = np.int
DTYPE = np.float64
ctypedef np.float64_t DTYPE_t
ctypedef np.int_t INT_t

cdef:
  unsigned int N = 10000


"""main func"""
def para_AdB():
  cdef:
    np.ndarray[DTYPE_t, ndim=2] A = np.stack([np.zeros(N, dtype=DTYPE), np.ones(N, dtype=DTYPE), np.zeros(N, dtype=DTYPE)]).T
    np.ndarray[DTYPE_t, ndim=2] B = 2.0*A
    np.ndarray[DTYPE_t, ndim=1] c1, c2, c3, c4
    unsigned int i

  c1 = np.zeros(N, dtype = DTYPE)
  c2 = c1; c3 = c1; c4 = c1

  for i in range(100):
    c1 = onsite_ddot(A,B)
    c2 = onsite_ddot(A,B)
    c3 = onsite_ddot(A,B)
    c4 = onsite_ddot(A,B)


"""Dot product"""
cdef np.ndarray[DTYPE_t, ndim=1] onsite_ddot(np.ndarray[DTYPE_t, ndim=2] F, np.ndarray[DTYPE_t, ndim=2] H):
  """return C[i] = A[i].B[i]"""
  # A,B = size [N * 3]
  cdef np.ndarray[DTYPE_t, ndim=1] ret= np.zeros(N)
  cdef unsigned int i
  for i in range(N):
    ret[i] = np.dot(F[i],H[i])
    ret[i] = np.dot(F[i],H[i])
    ret[i] = np.dot(F[i],H[i])
  return ret
