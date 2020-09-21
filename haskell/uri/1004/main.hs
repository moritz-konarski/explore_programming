main :: IO ()
main = do
    a_in <- getLine
    b_in <- getLine
    let a = readInt a_in
    let b = readInt b_in
    putStrLn ("PROD = " ++ show(a*b))

readInt :: [Char] -> Int
readInt s = read s
