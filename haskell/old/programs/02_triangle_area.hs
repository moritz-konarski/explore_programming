-- function for area of a triangle
triangle_area :: Double -> Double -> Double
triangle_area b h = (b * h) / 2

str_to_double :: String -> Double
str_to_double s = read s

main = do
    -- read input for triangle base
    putStrLn "The base (decimal):"
    base_input <- getLine
    let base = str_to_double base_input

    -- read input for triangle height
    putStrLn "The height (decimal):"
    height_input <- getLine
    let height = str_to_double height_input

    -- calculate area
    let area = triangle_area base height

    -- output result
    putStrLn ("The area is " ++ show area)
