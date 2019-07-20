#cython: profile=True
#cython: boundscheck=False
#cython: wraparound=False
#cython: noncheck=False
#cython: language_level=3
import numpy as np
cimport numpy as np
import asyncio
import time
from cython.parallel import prange

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
  dict = {1:c1, 2:c2, 3:c3, 4:c4}
  begin = time.time()

  """Simple execute"""
  """
  c1 = onsite_ddot(A,B)
  c2 = onsite_ddot(A,B)
  c3 = onsite_ddot(A,B)
  c4 = onsite_ddot(A,B)
  """

  """asyncio"""
  async def async_process(A,B):
    for i in range(1,5):
      dict[i] = onsite_ddot(A,B)
    return True
  bigloop=asyncio.get_event_loop()
  bigloop.run_until_complete(async_process(A,B))


  end = time.time()
  print(end-begin)
  return c1


"""Dot product"""
cdef np.ndarray[DTYPE_t, ndim=1] onsite_ddot(np.ndarray[DTYPE_t, ndim=2] F, np.ndarray[DTYPE_t, ndim=2] H):
  """return C[i] = A[i].B[i]"""
  # A,B = size [N * 3]
  cdef np.ndarray[DTYPE_t, ndim=1] ret= np.zeros(N)
  cdef size_t i,j

  """
  Async : 3.4065349102020264
  No async:3.268634080886841
  Prange : 0.016139984130859375
  """
  """asyncio mode"""
  """
  async def async_dot(ret, F, H):
    global ret, F, H
    for i in range(N):
      ret[i] = np.dot(F[i],H[i])
    return True
  loop=asyncio.get_event_loop()
  loop.run_until_complete(async_dot(ret, F, H))
  """

  """no parallelization mode"""
  """
  for i in range(N):
    ret[i] = np.dot(F[i],H[i])
  """

  """Prange parallelization"""
  for i in prange(N, nogil=True):
    for j in prange(3):
      ret[i] += F[i,j]*H[i,j]

  return ret
