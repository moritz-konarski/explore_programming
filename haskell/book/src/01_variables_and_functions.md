# Variables and functions

## Variables

- variables are useful
```haskell
    a = 3.141592
    a^3
```
- code is more readable and modifiable


## Haskell source files

- file extension is `.hs`
- to load a file in GHCi type `:l`, to reload type `:r`

## Comments

- comments are done like this
```haskell
    x = 5       -- a comment
```
- block comments work like this
```haskell
    x = 5
    {-
        multi-line comment
    -}
    y = {- inline comment -} 12
```

## Variables in imperative languages

- in Haskell, variables can only be declared once and they are immutable
- they must begin with a letter and then can contain letters, numbers, underscores and ticks

## Functions

- functions take an argument (or parameter) and gives a resulting value
- they are defined as follows
```haskell
    area r = pi * r ^ 2
```
- functions don't use parentheses but they can be used to group expressions and to make code easier to read
- haskell functions can also take multiple arguments 
```haskell
    areaTriangle b h = (b * h) / 2
```
- functions can also be passed as arguments
- arguments are applied in the order they are given
- functions can be used to defined some new functions

## Local definitions

- when functions have values local to them, they are declared using `where` -- see Heron's formula $A = \sqrt{s(s-a)(s-b)(s-c)}$
```haskell
    heron a b c = sqrt (s * (s - a) * (s - b) * (s - c))
        where
        s = (a + b + c) / 2
```
- the `where` and local variables are indented by 4 spaces -- there can be multiple such statement
