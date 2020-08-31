factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n - 1)

double_factorial :: Integer -> Integer
double_factorial 1 = 1
double_factorial 2 = 2
double_factorial n = n * double_factorial (n - 2)
