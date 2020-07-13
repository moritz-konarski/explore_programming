-- comments work like this
{-
    Multi-line comment
-}

-- import statements
import Data.List
import System.IO

{- Types -}
-- Int 64 bit
maxInt = maxBound :: Int
minInt = minBound :: Int

-- Integer - ubounded Integer

-- Double and Float 
bigFloat = 3.999999999 + 0.000000000005

-- Bool: True or False
-- Char 'a'
-- Tuple (var, var, var)

always5 :: Int
always5 = 5

-- sums

sumOfNums = sum [1..1000]

-- normal mathematical functions are available

-- modulus
modEx = mod 5 4
modEx2 = 5 `mod` 4

-- square root
root = sqrt 9

-- or with ints
num9 = 9 :: Int
root9 = sqrt (fromIntegral num9)

-- maths functions
{- 
pi
exp x
log x
square: x ** y
truncate x
round x
ceiling x
floor x
all the trigs: tan, atan, atanh, tanh
-}

-- logical operators
{- 
and: &&
or : ||
not: not(val)
-}

-- for help use ":t"

-- lists in haskell
primeNumbers = [2,3,5,7,11]
-- append to the end
morePrimes = primeNumbers ++ [13,17,19]
-- add to the front
faveNums = 2 : 7 : 21: 66 : []
-- list of lists
mulList = [[3,5,7],[11,13,17]]
-- access index
firstList = mulList !! 1
-- length of lists
listLen = length mulList
-- reverse lists
revPrimes = reverse primeNumbers
-- is empty
isEmpty = null primeNumbers
-- first
firstPrime = head morePrimes
-- last
lastPrime = last morePrimes
-- all but last
initPrime = init morePrimes
-- first 3 primes
first3Primes = take 3 morePrimes
-- all but 3 primes
allBut3Primes = drop 3 morePrimes
-- is in list
is7InList = 7 `elem` morePrimes
-- max value, min value
maxPrime = maximum primeNumbers
minPrime = minimum primeNumbers
-- product of all elements
prodList = product morePrimes
-- lists with step
evenList = [2,4..200]           -- also works with chars
-- generate infinite lists
infinitePowersOfTen = [10,20..] !! 50
-- fill lists
many2s = take 10 (repeat 2)
-- replicate a value x times
many3x = replicate 10 3
-- cycle repeats a section indefinitely
cycleList = take 30 (cycle [1,3,5,7])
-- list comprehension
listTimes2 = [ x * 2 | x <- morePrimes ]
-- divisible by 9 and 13
divBy9And13 = [ x | x <- [1..1000], x `mod` 9 == 0,  x `mod` 13 == 0 ]
-- sorted lists
sortedList = sort [9,1,345,2,234475,34]

let fac x :: Int = if x == 0 then 1 else x * fac (x-1)