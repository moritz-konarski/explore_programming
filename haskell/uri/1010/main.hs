import Text.Printf

main :: IO ()
main = do
    l_in <- getLine
    printf "%s\n" l_in
    let new = split l_in
    printf "%s\n" new


parse3 :: [Char] -> 

ri :: [Char] -> Int
ri s = read s

rd :: [Char] -> Double
rd s = read s
