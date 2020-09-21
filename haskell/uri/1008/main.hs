import Text.Printf

main :: IO ()
main = do
    n_in <- getLine
    h_in <- getLine
    s_in <- getLine
    let n = readInt n_in
    let h = readInt h_in
    let s = readDouble s_in
    printf "NUMBER = %d\nSALARY = U$ %.2f\n" n (fromIntegral(h) * s)


readInt :: [Char] -> Int
readInt s = read s

readDouble :: [Char] -> Double
readDouble s = read s
