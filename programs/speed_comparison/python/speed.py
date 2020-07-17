import timeit

def func():
    pi = 1.0
    sign = -1
    for i in range(1,10000000):
        pi   = pi + sign / (2 * i + 1)
        sign = sign * -1
    return pi

if __name__ == '__main__':
    pi = func();
    for i in range(10):
        print("time: ", timeit.timeit("func()", setup="from __main__ import func", number=1))
    print("result: ", pi * 4)
