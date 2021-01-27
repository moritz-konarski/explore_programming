# Recursion

- a function that has the ability to invoke itself
- a recursive function calls itself in certain circumstances and stops in others

## Numeric recursion

- see factorials
```haskell
    factorial 0 = 1
    factorial n = n * factorial (n - 1)
```
- always write the most restrictive type first
- `go` can be used to translate loops from other languages into Haskell
- many functions have recursive versions -- multiplication for example

## List-based recursion

- lists make extensive use of recursion, e.g. for length
```haskell
    length :: [a] -> Int
    length []       = 0
    length (x:xs)   = 1 + length xs
```
- recursion is the only way to implement control structures if one only has
immutable types
- the list concatenate function is defined recursively too
```haskell
    (++) :: [a] -> [a] -> [a]
    [] ++ ys        = ys
    (x:xs) ++ ys    = x : xs ++ ys
    -- basically turns [1,2,3] ++ [4,5,6] into 1:2:3:[4,5,6]
```
- list recursion generally involves an empty list case and then one where the
tail is passed to the function again
