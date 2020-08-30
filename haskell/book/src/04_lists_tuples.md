# Lists and tuples

## Lists

- denoted by `[` and `]`, elements are separated by commas
- all elements must be of the same type
```haskell
    numbers = [1,2,3,4]
    bools   = [True, False, False]
```
- to add elements to the start of a list, use `:` (cons), evaluated from right to left
```haskell
    [1,2,3,4] == 1:2:3:4:[]
```
- you can only cons elements to a list, not vice versa
- strings are also just lists of characters
- lists can also contain lists -- a useful feature

## Tuples

- store multiple values in a single value
- tuples will always have a set length, you cannot increase their size -- good if you know the amoung of needed data
- elements of a tuple do not need to be of the same type
```haskell
    (True, 1)
    ("hello", 'c', 123.23)
```
- tuples can also contain other tuples
- `fst` and `snd` return the first and second elements of a 2-tuple or pair
- `head` and `tail` for lists return the first element and the list minus the first element
- head and tail are pretty bad though, they will fail if passed an empty list
- functions can use polymorphic types, they can represent a bunch of different types with certain similarities
- type variables allow any type to take their place, they are useful for writing functions that can work on many types
- mathematically that's called polymorphism
```haskell
    f :: a -> a
    -- takes type a and returns same type a
    f :: a -> b
    -- takes a and may or may not return the same type
```
- for example `fst` and `snd` work like this
```haskell
    -- return first of pair
    fst :: (a, b) -> a
    -- return second of pair
    snd :: (a, b) -> b
```
