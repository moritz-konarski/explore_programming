import Text.Printf

main :: IO ()
main = do
    getLine
    f_in <- getLine
    s_in <- getLine
    let f = readDouble f_in
    let s = readDouble s_in
    printf "TOTAL = R$ %.2f\n" (salary f s)

salary :: Double -> Double -> Double
salary f s = f + 0.15 * s

readDouble :: [Char] -> Double
readDouble s = read s
