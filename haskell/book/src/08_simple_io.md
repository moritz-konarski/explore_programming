# Simple input and output

- program have to interact with the world around them
```haskell
    putStrLn "Hello, world!"
```
- `putStr` just misses the new line `putStrLn` has
- these functions are of type `IO ()`, that is `IO` action with type `()` -- unit type, tuple with 0 elements -- basically nothing
- `IO` occurs in print, read, write

## Sequencing actions with `do`

- `do` lets you put actions in order of execution
```haskell
    main = do
        putStrLn "Please enter your name:"
        name <- getLine
        putStrLn ("Hello, " ++ name ++ ", how are you")
```
- the final action defines the type of the whole `do` block -- here the whole program has type `IO ()`
- the `<-` notation assigns the result of `getLine` to the variable -- omitting it will just take the input but don't act on it
- `<-` cannot be the last action
- use `read` to convert string to text, show to convert number to string
```haskell
    double = read "123.3"

    string_of_double = show double
```
- `<-` can be used to get any result value, just some of them are not worth saving
- the two branches of if/then/else statements must all have the same type
- for all sequenced commands we need to start a new `do` block
- for action to return what they say they will, you require the `<-`
