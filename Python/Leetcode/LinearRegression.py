import numpy as np
import matplotlib.pyplot as plt

a = [2,5,7,9,11,16,19,23,22,29,29,35,37,40,46]
b = [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]

plt.plot(a, b, 'ro')

#Convert list to matrix
a = np.array([a]).T
b = np.array([b]).T

#Create 1-valued matrix sizes 1x1
oneVector = np.ones((a.shape[0], 1), dtype=np.int8)

#Concatenate matrix 1 to a
a = np.concatenate((a, oneVector), axis= 1)

#Formula of Linear Regression to find vector x include a, b in f(x) = ax + b
# x = ((A^T.A)^-1).A^T.B
x = np.linalg.inv(a.transpose().dot(a)).dot(a.transpose()).dot(b)

#x0 equal Ox, y0 = y = ax + b
x0 = np.array([[0, 46]]).T
y0 = x[0][0] * x0 + x[1][0]

x1 = 4
y1 = x[0][0] * x1 + x[1][0]
print(y1)
# plt.plot(x0, y0)
# plt.show()