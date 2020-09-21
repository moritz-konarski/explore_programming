import Text.Printf

main :: IO ()
main = do
    a_in <- getLine
    b_in <- getLine
    let a = readDouble a_in
    let b = readDouble b_in
    printf "MEDIA = %.5f\n" (avg a b)

avg :: Double -> Double -> Double 
avg a b = (3.5 * a + 7.5 * b) / 11.0

readDouble :: [Char] -> Double
readDouble s = read s
