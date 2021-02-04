# What is functional programming?

- method of programming emphasizing functions and their applications, not commands and their execution
- clear, mathematical notation
- mathematical basis supporing reasoning about the program

## Functions and types

Haskell notation

```haskell
f :: X -> Y
```

says that `f` is a function taking type `X` and returning type `Y`, see

```haskell
sin :: Float -> Float
age :: Person -> Int
add :: (Integer, Integer) -> Integer 
logBase :: Float -> (Float, Float)
```

- `Int` is $-2^{29}$ to $2^{29}$, `Integer` is unlimited
- to apply functions in Haskell, we can write, all are equivalent

```haskell
f x
f(x) 
f (x)
logBase 2 10
(logBase 2) 10
(logBase 2)(10)
```

- association in Haskell is to the left and also most binding

```haskell
-- this is wrong
log sin x == (log sin) x
-- this is correct
log (sin x)
```

- this math $\sin\, 2 \theta = 2\,\sin\,\theta\,\cos\,\theta$ equals

```haskell
sin (2*theta) = 2 sin theta cos theta
```

## Functional composition
- we can have composite functions, we combine them

```haskell
f :: Y -> Z
g :: X -> Y
f . g :: X -> Z
(f . g) x = f (g x)
```

- this is the same as saying $f(g(x))$ or $f \circ g$
- this composition is right to left, like in maths

## Example: common words

- program to find the most common words
- a text (list of characters)
- characters are `Char` (denoted by `'`), strings are `[Char]` (denoted by `"`)
- we want to define a function like this

```haskell
commonWords :: Int -> [Char] -> [Char]
```

- takes text, returns list of `n` most common words
- order of association is from right to left, so you have to write
- how exactly this program should be implemented is of course not clear
- we do have to make a list of the most common words at some point
- words = sequences of chars without space or newline
- we assume we have the function (actually is stdlib)

```haskell
-- extracts words from test
words :: [Char] -> [[Char]]
```

- we can use type synonyms to make this more readable

```haskell
type Text = [Char]
type Word = [Char]
-- extracts words from test
words :: Text -> [Word]
```

- we will make all characters lowercase

```haskell
toLower :: Char -> Char
```

- to apply this to all elements in the text we need `map`

```haskell
map :: (a -> b) -> [a] -> [b]
```

- `map f [list]` applies `f` to every element of the list
- converting all text to lower case is

```haskell
map toLower :: Text -> Text
```

- our function thus far is `words . map toLower`
- to count the words we could sort them into alphabetical order and then count runs of identical words
- we need a function to sort them

```haskell
sortWords :: [Word] -> [Word]
```

- and then we need a function to count it

```haskell
countRuns :: [Word] -> [(Int, Word)]
```

- the we coult have a function that sorts our runs descending to find the longest

```haskell
sortRuns :: [(Int,Word)] -> [(Int,Word)]
```

- then we simply need `take :: Int -> [a] -> [a]` that returns the first `n` elements of a list
- then we need a function to display our results

```haskell
showRuns :: [(Int,Word)] -> [String]
```

- at the very end we need to concatenate our string
- we now need concat `concat :: [[a]] -> [a]`
- this finally leads to 

```haskell
commonWords :: Int -> Text -> String
commonWords n = concat . map showRun . take n . sortRuns . 
                    countRuns . sortWords . words . 
                    map toLower
```

- this cannot always be done, but when it can, it's great
- _Lesson 1_: functional composition is important
- _Lesson 2_: deciding the type of a function is the first step in defining it
- we created a script (list of definitions)

## Example: numbers into words

- we want a program that converts a number into its corresponding string

```haskell
convert 308000 = "three hundred and eight thousand"
```

- the function will have the signature `convert :: Int -> String`
- it takes a positive integer < 1 million
- we can create the following lists


```haskell
units = ["zero","one","two","three","four","five","six","seven",
            "eight","nine"] 
teens = ["ten","eleven","twelve","thirteen","fourteen","fifteen",
            "sixteen","seventeen","eighteen","nineteen"] 
tens = ["twenty","thirty","forty","fifty","sixty","seventy",
            "eighty","ninety"]
```

- we can first solve a simpler task, for $0 \le n < 10$


```haskell
convert1 :: Int -> String
convert1 n = units!!n

convert1 9
convert1 2
```


    "nine"



    "two"


- the operator `!!` returns the `n`th element starting from 0
- we can now step up our program to 2 digits $0 \le n < 100$
- first we need a function that splits tens into 1s and 10s


```haskell
digits2 :: Int -> (Int, Int)
digits2 n = (div n 10, mod n 10)

digits2 34
```


    (3,4)


- we can now define the next define 


```haskell
-- combines two strings to one string
combine2 :: (Int,Int) -> String
combine2 (t,u)
    | t == 0           = units!!u
    | t == 1           = teens!!u
    | t >= 2 && u == 0 = tens!!(t-2)
    | t >= 2 && u /= 0 = tens!!(t-2) ++ "-" ++ units!!u

convert2 :: Int -> String
convert2 = combine2 . digits2

convert2 69
convert2 99
convert2 13
```


    "sixty-nine"



    "ninety-nine"



    "thirteen"


- we can also write the `combine2` function in two other ways

```haskell
combine2 :: (Int,Int) -> String 
combine2 (t,u) 
    | t==0 = units!!u 
    | t==1 = teens!!u 
    | u==0 = tens!!(t-2) 
    | otherwise = tens!!(t-2) ++ "-" ++ units!!u
```

or

```haskell
convert2 :: Int -> String
convert2 n 
    | t==0 = units!!u 
    | t==1 = teens!!u 
    | u==0 = tens!!(t-2) 
    | otherwise = tens!!(t-2) ++ "-" ++ units!!u 
        where (t,u) = (n `div` 10, n `mod` 10)
```

- here the `where` clause eliminates the need for a definition of `digits2`
- now lets do `convert3` for 3 digits

```haskell
convert3 :: Int -> String
convert3 n
    | h == 0 = convert2 t
    | n == 0 = units!!h ++ " hundred"
    | otherwise = units!!h ++ " hundred and " ++ convert2 t
        where (h,t) = (n `div` 100, n `mod` 100)
```
