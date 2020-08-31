# Building vocabulary

## Function composition

- means applying one function to a value and then applying another function to the result
```haskell
    -- defining functions
    f x = x + 3
    square x = x ^ 2
    square (f 1)        -- returns 16
    f (square 2)        -- returns 7
```
- the parentheses are necessary because otherwise the function would try to take another function as input -- an error
- we can make one function of multiple commonly used ones
```haskell
    squareOfF x = square (f x)
    fOfSquare x = f (square x)
```
- another way to do it is with `(.)`, the function composition operator
```haskell
    -- functions are applied from right to left
    squareOfF x = (square . f) x
    fOfsquare x = (f . square) x
```
- one can also leave out the `x`, giving
```haskell
    squareOfF = square . f
```

## Prelude and the libraries

- the standard library in Haskell is called the prelude
- it provides the types and general functions
- you can import modules into your program
```haskell
    import Data.List
```
- in GHCi use `:m +<name>`
- using the standard library can make programs much shorter
```haskell
    -- program that reverses the order of strings
    revWords :: String -> String
    revWords input = (unwords . reverse . words) input
```
