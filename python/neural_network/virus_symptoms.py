import numpy as np

input_features = np.array([[1, 0, 0, 1], [1, 0, 0, 0], [0, 0, 1, 1], [0, 1, 0, 0], [
                          1, 1, 0, 0], [0, 0, 1, 1], [0, 0, 0, 1], [0, 0, 1, 0]])

target_output = np.array([1, 1, 0, 0, 1, 1, 0, 0])
target_output = target_output.reshape(8, 1)

weights = np.array([[0.1], [0.2], [0.3], [0.4]])

bias = 0.3

lr = 0.05


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


def sigmoid_derivative(x):
    return sigmoid(x) * (1 - sigmoid(x))


for epoch in range(10000):
    inputs = input_features

    pred_in = np.dot(inputs, weights) + bias

    pred_out = sigmoid(pred_in)

    error = pred_out - target_output
    #print(error.sum())

    dcost_dpred = error

    dpred_dz = sigmoid_derivative(pred_out)

    z_delta = dcost_dpred * dpred_dz

    inputs = input_features.T
    weights -= lr * np.dot(inputs, z_delta)

    for i in z_delta:
        bias -= lr * i


# tests positive for the virus
test_point1 = np.array([1, 0, 0, 1])
result1 = np.dot(test_point1, weights) + bias
result2 = sigmoid(result1)
print(result2)

# tests negative for the virus
test_point2 = np.array([0, 0, 1, 0])
result3 = np.dot(test_point2, weights) + bias
result4 = sigmoid(result3)
print(result4)