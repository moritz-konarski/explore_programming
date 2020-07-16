# OR gate truth table:
#   | Input 1 | Input 2 | Output |
#   |    0    |    0    |   0    |
#   |    0    |    1    |   1    |
#   |    1    |    0    |   1    |
#   |    1    |    1    |   1    |

# perceptron for the or gate:
#   2 inputs, bias of 1, 1 output

# manual example
#   w1 = 0.2, x2 = 0.3, w3 = 0.5
#   i1 = 0, i2 = 1, b = 1
#   o1 = w1 * i1 + w2 * i2 + w3 * b
#   o1 = 0.8
#   sigmoid(0.8) = 0.69
#   we wanted 1
#
#   Error:
#   mse = sum(0.5 (target - output)^2)
#   mse = 0.05
#
#   Gradient Descent
#   x = x - lr * d/dx * f(x)
#       x    - input
#       f(x) - output based on x
#       lr   - learning rate
#   maths
#   d/dx = output - target
#        = -0.31
#
#   ino   = w1 * i1 + w2 * i2 + w3 * b
#   outo  = 1 / (1 + e^(-ino))
#   error = sum( 1/2 ( target output - outo)^2)
#   w     = w - lr * (d E/d outo * d outo / d ino * d ino / d w)
#         = w - lr * ((outo - target output) * outo(1-outo) * (input values))

import numpy as np


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


def sigmoid_derivative(x):
    return sigmoid(x) * (1 - sigmoid(x))


input_features = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])

target_output = np.array([[0], [1], [1], [1]])

weights = np.array([[0.1], [0.2]])

bias = 0.3

learning_rate = 0.05

for epoch in range(10000):
    inputs = input_features

    in_o = np.dot(inputs, weights) + bias

    out_o = sigmoid(in_o)

    error = out_o - target_output

    x = error.sum()
    #print(x)

    derror_douto = error
    douto_dino = sigmoid_derivative(out_o)

    deriv = derror_douto * douto_dino

    inputs = input_features.T
    deriv_final = np.dot(inputs, deriv)

    weights -= learning_rate * deriv_final

    for i in deriv:
        bias -= learning_rate * i

# print(weights)
# print(bias)

# test out 0 and 0
test_point1 = np.array([0, 0])
result1 = np.dot(test_point1, weights) + bias
result2 = sigmoid(result1)
print("Input: [0,0], Output:")
print(result2)

# test out 1 and 0
test_point2 = np.array([1, 0])
result3 = np.dot(test_point2, weights) + bias
result4 = sigmoid(result3)
print("Input: [1,0], Output:")
print(result4)

# test out 1 and 1
test_point3 = np.array([1, 1])
result5 = np.dot(test_point3, weights) + bias
result6 = sigmoid(result5)
print("Input: [1,1], Output:")
print(result6)