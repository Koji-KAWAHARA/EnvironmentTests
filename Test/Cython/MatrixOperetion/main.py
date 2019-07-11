import numpy as np
import pyximport
pyximport.install(setup_args={'include_dirs':[np.get_include()]}, inplace=True)
import cython_matrix as cmat

print(cmat.para_AdB())
