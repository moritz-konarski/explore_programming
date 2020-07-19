# variables do not need types

name = "Moritz"
number = 42
num = 3.1415926535

#%%
println(name)
println(number)
println(num)
#%%

# mathematical operations
a = 2
b = 3
sum = a + b
difference = a - b
product = a * b
quotient = b / a
power = a^3
modulus = b % a

# rational numbers
rational = 1//3

# types of variables can be found with the typeof function
typeof(42)

# convert converts types
a = 2
b = convert(Float64, a)