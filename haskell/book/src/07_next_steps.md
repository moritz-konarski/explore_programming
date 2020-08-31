# Next steps

## If then else

- works like in other languages
```haskell
    signum x =
        if x < 0
            then -1
            else if x > 0
                then 1
                else 0
```
- there _has_ to be an `else` statement because there always has to be a result
- `if - then - else` can also be translated to guards
```haskell
    signu x =
        | x < 0     = -1
        | x > 0     =  1
        | otherwise =  0
```
- both options work the same, sometimes one is more readable than the other

## Introducing pattern matching

- long `if-else` statements are convoluted
- defining piece-wise functions is much better and more readable
```haskell
    pts :: Int -> Int
    pts 1 = 10
    pts 2 = 6
    pts 3 = 4
    pts 4 = 3
    pts 5 = 2
    pts 6 = 1
    pts _ = 0
```
- the `_` is a wildcard -- matching anything of the functions type
- using some logic, we can make `pts` even shorter
```haskell
    pts :: Int -> Int
    pts 1 = 10
    pts 2 = 6
    pts x
        | s <= 6    = 7 - x
        | otherwise = 0
```
- pattern matching can be overlapped and thus inefficient
- patterns should always match all possible cases

## Tuple and list patterns

- the patterns work the same, they are more useful actually
```haskell
    head        :: [a] -> a
    head (x:_)  = x
    head []     = error "Prelude.head: empty list"

    tail        :: [a] -> [a]
    tail (_:xs) = xs
    tail []     = error "Prelude.head: empty list"
```

## `Let` bindings

- similar to `where`, different formatting
- can help make functions more readable
```haskell
    roots a b c =
        ((-b + sqrt(b * b - 4 * a * c)) / (2 * a),
         (-b - sqrt(b * b - 4 * a * c)) / (2 * a))
    -- can be transformed to
    short_roots a b c = 
        let d = sqrt (b ^ 2 - 4 * a * c)
            two_a = 2 * a
        in ((-b + d) / two_a,
            (-b - d) / two_a)
```
