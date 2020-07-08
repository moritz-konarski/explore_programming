-- funcions always return something
doubleMe x = x + x

-- function arguments are separated by spaces`
doubleUs x y = doubleMe x + doubleMe y

-- functions start with lower case letters
-- if statements are expressions, they return something
doubleSmallNumber x = if x > 100
                        then x
                        else x*2

-- functions without arguments are just statements
myName = "My name is Moritz"

-- lists are super useful in Haskell
-- these data structures are homogenous, they have all the same datat type
lostNumbers = [4,8,15,16,23,42]

-- strings are just lists of characters
stringEqualsList = "hello" == ['h','e','l','l','o']

-- we can concatenate lists with ++
concatTest = [1,2,3,4] ++ [9,10,11,12]
-- take care though, with ++ haskell walks through all elements of the list on the left

-- putting number at the begging with : is instantaneous
addToStart = 5:[1,2,3,4,5]

-- list are syntactic sugar, they can contain each other
-- lists can be compared if their types can be compared
-- they are compared starting at the start, one by one until they are different
addTest = 1:2:3:[] == [1,2,3]

-- indices work like this
getLetter x = "getLetter" !! x

-- head: l[0]; tail: all but l[0]; last: last element; init: all but last
-- length; null: returns True if empty; reverse; take x: returns the first x elements
-- drop x: drops the first x elements; maximum, minimum; sum, product; x `elem` l: True or False

-- ranges: all between x..y
alphabet = ['a'..'z']

-- with a step: give the first two elements, then last
threes = [0,3..30]

-- backwards ranges need two first elements by default
-- we can also ask for the first elements of an infinite list
semiInfinite = take 24 [13,26..]

-- cycle creates an infinite list from some list; repeat takes one element and turns it into an infinite list
-- replicate x y gives x of y

-- list comprehensions or filtering
tenEvenNums = [x*2 | x <- [1..10]]

-- filtering of numbers with if statements
booms xs = [if x < 10 then "Boom!" else "Bang!" | x <- xs, odd x]

-- general form: [ results come here, can be altered | assigned values, boolean predicate, more predicates]
-- if multiple lists are used, comma separated, they produce all possible combinations

-- they also work with strings
nouns = ["hobo","frog","pope"]  
adjectives = ["lazy","grouchy","scheming"]  
funnyWords = [adjective ++ " " ++ noun | adjective <- adjectives, noun <- nouns]  

-- own version of length
-- _ is placeholder for a variable; it returns 1 for each list element and then sums it up
length' xs = sum [1 | _ <- xs]

-- only return uppper case
returnUpperCase st = [ c | c <- st, c `elem` ['A'..'Z']]

-- spreading list comprehensions over multiple lines is a good idea 


-- Tuples