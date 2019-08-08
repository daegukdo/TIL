from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

import matplotlib.pyplot as plt
import numpy as np

import pandas as pd

import glob

gooddata_files = "good.txt"
baddata_files = "bad.txt"

gooddata_df = pd.read_csv(gooddata_files, header=None)
baddata_df = pd.read_csv(baddata_files, header=None)

gooddata = gooddata_df.values
baddata = baddata_df.values


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

for i in range(40):
    xs = gooddata[i*10][12]
    ys = gooddata[i*10][13]
    zs = gooddata[i*10][14]
    ax.scatter(xs, ys, zs, c='blue', marker='o')

for i in range(40):
    xs = baddata[i*10][12]
    ys = baddata[i*10][13]
    zs = baddata[i*10][14]
    ax.scatter(xs, ys, zs, c='red', marker='^')
    
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()
