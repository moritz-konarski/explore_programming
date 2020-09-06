-- function that returns the first m elements of a list
takeInt :: Int -> [Int] -> [Int]
takeInt _ []        = []
takeInt 0  _        = []
takeInt m (n:ns)    = n : takeInt (m - 1) ns

-- dropInt drops the first m elements from a list and returns the list
dropInt :: Int -> [Int] -> [Int]
dropInt 0 (n:ns)    = n : dropInt 0 ns
dropInt _ []        = []
dropInt m (n:ns)    = dropInt (m - 1) ns

-- sumInt returns the sum of all list items
sumInt :: [Int] -> Int
sumInt []           = 0
sumInt (n:ns)       = n + sumInt ns

-- scanSum sums up all elements and returns a running total
scanSum :: [Int] -> [Int]
scanSum []          = []
scanSum (n:[])      = n : []
scanSum (n1:n2:ns)  = n1 : scanSum ((n1+n2):ns)

-- diffs list of differences between adjacent elements
myDiff
