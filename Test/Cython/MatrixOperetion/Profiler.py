"""profiler"""
import numpy as np
import pyximport; pyximport.install(setup_args={'include_dirs': [np.get_include()]}, inplace=True)
import cython_matrix as cmat
import pstats, cProfile
cProfile.runctx("cmat.para_AdB()", globals(), locals(), "Profile.prof")
s = pstats.Stats("Profile.prof")
s.strip_dirs().sort_stats("time").print_stats()
"""end of profiler"""
