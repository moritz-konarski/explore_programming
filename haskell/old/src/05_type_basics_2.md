# Type basics II

- in maths you can add any type of number together -- for computers that does not work too well
- floats and integers are the least types you need
- this means Haskell needs types for at least those two
- still, the `(+)` works on any type of number
```haskell
    (+) :: (Num a) => a -> a -> a
```
- here `Num` is a typeclass -- a restriction on the types that a function can accept
- the most important numeric types are `Int`, `Integer`, `Float`, and `Double`
- `Int` is 32 bit, `Integer` is arbitrarily long, the others are floating point numbers
- a number in a Haskell program is of type number and is only restricted when it is changed, like `7` is anything, `3.12` is restricted to double and then they are added on the lowest denominator
- monomorphic trouble comes when returned types are incompatible
- using a function that returns `Int` with a function expecting `Double` will blow up, it requires conversion
```haskell
    -- converts an int into a polymorphic number
    fromIntegral(num)
```

## Classes beyond numbers

- there is a typeclass for equations `Eq`
- length is a function that takes a `Foldable`, a type that includes lists and more
