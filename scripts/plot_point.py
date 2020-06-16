import pandas as pd 
import matplotlib.pyplot as plt 
import sys

def read_csv(file_path):
    data = pd.read_csv(file_path, sep=",", header=0).values

    x = data[:, 0]
    y = data[:, 1]
    return x, y

x, y = read_csv(sys.argv[1])
x_r, y_r = read_csv(sys.argv[2])

plt.figure()
plt.scatter(x, y)
plt.scatter(x_r, y_r)
plt.grid()
plt.xlim((-10,10))
plt.ylim((-10,10))
plt.show()
