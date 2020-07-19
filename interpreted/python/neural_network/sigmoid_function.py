# required imports
import numpy as np
import matplotlib.pyplot as plt

# input dataset, (min, max, count)
input = np.linspace(-10,10,100)

# sigmoid function
def sigmoid(X):
    val = 1/(1 + np.exp(-X))
    return val

# output data set
output = sigmoid(input)

# graph data
plt.plot(input, output)
plt.xlabel("Input")
plt.ylabel("Output")
plt.title("Sigmoid Function")
plt.show()
