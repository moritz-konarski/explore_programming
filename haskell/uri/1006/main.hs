import Text.Printf

main :: IO ()
main = do
    a_in <- getLine
    b_in <- getLine
    c_in <- getLine
    let a = readDouble a_in
    let b = readDouble b_in
    let c = readDouble c_in
    printf "MEDIA = %.1f\n" (avg a b c)

avg :: Double -> Double -> Double -> Double 
avg a b c = (2.0 * a + 3.0 * b + 5.0 * c) / 10.0

readDouble :: [Char] -> Double
readDouble s = read s
