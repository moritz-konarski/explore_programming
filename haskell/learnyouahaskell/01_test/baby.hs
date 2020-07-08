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
doesItWork = "hello" == ['h','e','l','l','o']

-- we can concatenate lists with ++
test = [1,2,3,4] ++ [9,10,11,12]

-- A common task is putting two lists together. This is 