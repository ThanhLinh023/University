import matplotlib.pyplot as plt
import numpy
from sklearn.cluster import KMeans

img = plt.imread("a.jpg") # Read an image (image in the same folder with code file)
#'shape()' function return a tuple with 3 elements like: (a, b, c)
wid = img.shape[0]
hei = img.shape[1]

img = img.reshape(wid * hei, 3) # Convert image into list to fit with KMeans Algorithm

# KMeans algorithm
kmeans = KMeans(n_clusters=25).fit(img)
labels = kmeans.predict(img)
clusters = kmeans.cluster_centers_

#Method 1: Vary pixel matrix using library
# imgTemp = numpy.zeros_like(img)
# for i in range(len(imgTemp)):
#     imgTemp[i] = clusters[labels[i]]
# imgTemp = imgTemp.reshape(wid, hei, 3)

#Method 2: No library
imgTemp = numpy.zeros((wid, hei, 3), dtype=numpy.uint8)
index = 0
for i in range(wid):
    for j in range(hei):
        imgTemp[i][j] = clusters[labels[index]]
        index += 1

plt.imshow(imgTemp)
plt.show()