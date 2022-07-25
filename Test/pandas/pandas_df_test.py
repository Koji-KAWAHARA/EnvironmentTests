#%%
import numpy as np
import pandas as pd

"""read dataframe from file,(with 1st raw being index)"""
#df = pd.read_csv("./testdata/testrun_main/detail/t_0.txt",header=[1],sep=" ")

"""dummy dataframe"""
df = pd.DataFrame({'C1': [1, 1, 1],
                   'C2': [1, 1.57, 1],
                   'C3': [1, 1, 1],
                   'C4': [1, 1, 1],
                   'C5': [1, 1, 1]})
df
# %%
"""create empty dataframe"""
dphase = pd.DataFrame(columns=['D1', 'D2', 'D3'])
# %%
"""coefficient wise numeric operation"""
dphase['D1']=df['C1']*np.sin(df['C2'])
dphase['D2']=df['C3']*np.sin(df['C4'])
dphase['D3']=df['C5']*2
dphase
# %%
