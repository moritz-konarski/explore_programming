# Lists II

## Rebuilding lists

- function that doubles all elements in a list
```haskell
    doubleList :: [Integer] -> [Integer]
    doubleList [] = []
    doubleList (n:ns) = (2 * n) : doubleList ns
```
- to create a multiply list function, we add another factor
```haskell
    multiplyList :: [Integer] -> [Integer]
    multiplyList _ [] = []
    multiplyList m (n:ns) = (m * n) : multiplyList m ns
```
- 
