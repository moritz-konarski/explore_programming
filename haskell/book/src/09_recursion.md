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
 TODO: look at the exercises to practice
