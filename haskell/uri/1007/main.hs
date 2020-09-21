main :: IO ()
main = do
    in_1 <- getLine
    in_2 <- getLine
    in_3 <- getLine
    in_4 <- getLine
    let int_1 = readInt in_1
    let int_2 = readInt in_2
    let int_3 = readInt in_3
    let int_4 = readInt in_4
    putStrLn ("DIFERENCA = " ++ show(dif int_1 int_2 int_3 int_4))


dif :: Int -> Int -> Int -> Int -> Int
dif a b c d = a * b - c * d

readInt :: [Char] -> Int
readInt s = read s
