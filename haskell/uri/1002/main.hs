import Text.Printf

main :: IO ()
main = do
    let pi = 3.14159
    r_in <- getLine
    let r = readFloat r_in
    printf "A=%.4f\n" (r**2 * pi)

readFloat :: [Char] -> Double
readFloat s = read s
