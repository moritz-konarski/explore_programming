main :: IO ()
main = do
    a_in <- getLine
    let a = readInt a_in
    b_in <- getLine
    let b = readInt b_in
    putStrLn ("X = " ++ (show(a + b)))

readInt :: [Char] -> Int
readInt s = read s
