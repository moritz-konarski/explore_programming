# Type basics

- all types in haskell have to begin with a capital letter
- types are useful because they define what you can and can't do with them 
- `:type` or `:t` checks the type of any expression
- `::` means 'is of type', it indicates the _type signature_
- `True` and `False` are of type `Bool`
- characters are of type char
```haskell
    :t 'H'
    'H' :: Char
```
- strings are of type list of char
```haskell
    :t "hello"
    "hello" :: [Char]
```
- type synonyms are different words for the same types
```haskell
    [Char] == String
```

## Functional types

- functions have types too
- type signature for `not`
```haskell 
    :t not
    not :: Bool -> Bool
    -- function from bool to bool
```
- `chr :: Int -> Char` converts int to char ASCII
- `ord :: Char -> Int` converts ASCII to int
- to use these functions you have to use the module `Data.Char` with `:module Data.Char` or `:m Data.Char`
- finding the type signatures of function works by listing all types of the input values in order and then the result value, all separated by `->`
```haskell
    xor p q = (p || q) && not (p && q)
    :t xor
    xor :: Bool -> Bool -> Bool
```

## Type signatures in code

- type annotations look exactly like the function signatures
```haskell
    xor :: Bool -> Bool -> Bool
    xor p q = (p || q) && not (p && q)
```
- this clarifies the function to the compiler and the programmer
- when types are not provided, the compiler infers the types by what data is there
- also, type signatures can help the compiler spot errors for you
- by separating functions with commas we can put multiple ones on the same signature line
- if one writes `+` instead of `++` for concatenation, the compiler will let you know
