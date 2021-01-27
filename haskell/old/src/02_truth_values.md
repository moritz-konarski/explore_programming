# Truth values

## Equality and other comparisons

- double equal signs are used for comparisons `==`
- `True` and `False` are the representations of the booleans
- other evaluations are `<`, `>`, `>=`, `<=`, `/=`
```hakell
    -- defining operators
    x /= y = not (x == y)
```
- types are important

## Infix operators

- functions that are written between the arguments
```haskell
    4 + 9 == 13
    -- same as
    (==) (4 + 9) 13
```

## Boolean operations

- logical and is `&&`
- logical or is `||`
- logical not is `not`

## Guards

- syntactic sugar for piecewise functions
```haskell
    -- function for the absolute value of x
    absolute x
        | x < 0     = 0 - x     -- -x would also work
        | otherwise = x
```
- the pipe `|` is followed by a predicate (boolean expression)
- `otherwise` is used when none of the preceding values are `True`, it is actually just defined as `True`
- `where` works well with guards
```haskell
    numOfRealSolutions a b c
        | disc > 0 = 2
        | disc == 0 = 1
        | otherwise = 0
            where
            disc = b^2 - 4*a*c      -- discriminant for above
                                    -- descisions
```
