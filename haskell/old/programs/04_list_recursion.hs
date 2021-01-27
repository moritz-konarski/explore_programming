-- takes a count and an element and returns a list of count elements
my_replicate :: Int -> a -> [a]
my_replicate 0 _ = []
my_replicate 1 a = [a]
my_replicate n a = a : my_replicate (n - 1) a

-- returns an element at the given index
(!!!) :: [a] -> Int -> a
(x:xs) !!! 0 = x
(x:xs) !!! n = xs !!! (n - 1)

-- zips two lists together, like a zipper
my_zip :: [a] -> [b] -> [(a, b)]
my_zip []  []   = []
my_zip [a] []   = []
my_zip []  [b]  = []
my_zip (a:as) (b:bs)    = (a, b) : my_zip as bs
