-- finds factorial of a number
factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n - 1)

-- finds factorial of either only even or only add numbers
double_factorial :: Integer -> Integer
double_factorial 1 = 1
double_factorial 2 = 2
double_factorial n = n * double_factorial (n - 2)

-- raises x to the yth power
power :: Integer -> Integer -> Integer
power 0 _ = 0
power _ 0 = 1
power n 1 = n
power 1 _ = 1
power x y = x * power x (y - 1)

-- finds integer log2 of number
integer_log2 :: Integer -> Integer
integer_log2 1 = 0
integer_log2 2 = 1
integer_log2 n = 1 + integer_log2 (n `div` 2)
