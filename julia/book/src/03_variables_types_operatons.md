# Variables, Types, and Operations

- Julia is an optionally typed language -- users can choose to specify the types
- typing in Julia is important for speed, documentation, tooling

## Variables, naming conventions, and comments

- Julia differentiates between strings and characters, strings are denoted by double quotes, while characters are denoted by single quotes
- to see what type a variable or reference is one can use the `typeof(<var>)` function
- variables don't have to be typed, but they have to be initialized
- variables can change type, they can be over-written
- __everything__ is a expression in Julia
- Julia is strongly typed 
- variable names have to begin with a letter, then it can be letter, number, underscore, exclamation point, including unicode characters
- comments begin with `#` and are thus ignored
- multi line comments can be created with `#=` and terminated with `=#`
- colored output can be created with `print_with_color(:red, "I love Julia!")`
- objects are often interacted with in Julia -- actions on objects are written functionally, like `action(object)` and not `object.action()`
- to display objects from code while outside of REPL, use `display(object)`

## Types

- the type system is pretty unique, variables can be bound again to the same name
- if a variable is given a type, it will only accept variables of the same type
- type annotations are generally done as `var::TypeName` -- type annotations make error checking and optimization easier
`````julia
    calculate_position(time::Float64)
`````
- type assertions work in exactly the same way -- an error is raised if the tpes differ
`````julia
    (expression)::TypeName
`````
- to achieve top performance, types of variables have to remain stable
- Julia has a type hierarchy, with `Any` being the top -- any undeclared variable is of this type
- the type `None` is one no object can have, but it is a subtype of all other types
- custom types can be defined -- their named in CamelCase
- `typeof(x)` gives the type of variables, `isa(x, T)` checks if `x` is of type `T`
- data types are all of type `DataType`
- if data types can be converted by using the lower case type name
`````julia
    int64(3.14)
`````

## Integers and Booleans

- available integers are `Int8`, `Int16`, `Int32`, `Int64`, `Int128`
- unsigned integers are defined using `U` in front of the type name, like `UInt32`
- depending on machine architecture, the standard is either 32 or 64 bit
- this is given by the variable `WORD_SIZE`
- `typemin(var)` and `typemax(var)` give the min and max sizes of types
- if `typemax` is exceeded, overflow occurs
- explicit checking for overflow needs to occur
- other ways of writing integers are: `0b` (binary), `0o` (octal), `0x` (hexadecimal)
- in case arbitrary sizes are needed, `BigInt` can be used
`````julia
    BigInt("1234")
`````
- they support the same operations as normal integers, but conversions are not automatic
- divisions of `BigInt` always give floating point results
- `div` gives integer division, `rem` gives the remainder, `^` gives powers
- `true` and `false` are actually 8bit integers, where `0` is `false` and anything else is `true`, `bool(32)` returns true
- other logical operations are `!`, `==`, `!=`, `<`, `>`
- logical expressions can be chained `0 < x < 3`

## Floating point numbers

- follow IEEE 754
- come in `Float16`, `Float32`, `Float64`
- single precision floating point numbers: `2.5f2 == 2.5 * 10^2`
- double precision floating point numbers: `2.5e2 == 2.5 * 10^2`
- `BigFloat` is used for arbitrary precision floats
- `Inf` is infinity, `NaN` is not a number
- floating point numbers do cause errors because of the bad precision

## Elementary mathematical functions and operations

- the bit representation of any number can be seen using the `bits(num)` operation
- `round()` rounds to float
- `iround()` rounds to int
- other functions: `sqrt()`, `cbrt()`, `exp()`, `log()`, `sin()`, `cos()`, `tan()`, `erf()` (error function), `rand()`
- `()` enforce precedence
- chained assignments are allowed `a = b = c = d = 1`
- assignments can be combined `a, b = c, d` means `a = c` and `b = d`
- bool operations have `||` and `&&`, `|` and `&` are used for non-short-circuit operations, those that check all the options even if the result is already found
- bitwise operations are supported <http://docs.julialang.org/en/latest/manual/mathematical-operations/>

## Rational and complex numbers

- $i$ is represented as `im`, `3.2 + 7.1im` has the type `Complex{Float64}`
- all normal maths functions are also implemented for this type
- `abs()` returns the absolute value
- `complex(a, b)` turns a and b into a complex number
- rational numbers are good for exact ratios
- `3//4` is a rational for $\frac{3}{4}$ and has the type `Rational{Int64}`
- `float()` converts to a floating point number, `num()` and `denum()` give the numerator and the denominator

## Characters

- `'a'` is a char with type `Char` -- a 32-bit integer with a unicode code point inside of it
- `int('A')` returns 65, `char(65)` returns A
- unicode can be entered using single quotes around `'\uxxxx'` or `'\Uxxxxxxxx'`
- `is_valid_char()` checks if the entered number is a valid character
- normal escape sequences also exist, `\n`, `\t`,...

## Strings

- strings are always ASCII or UTF8, depending on the contained letters
- strings are immutable and contained in `"string"` or `'''string'''`
- arrays of chars starting at 1, so `s[1]` returns the first letter
- `s[end]` returns the end, `endof(s)` returns the last byte's index, `length()` the length
- iteration through a string is best done in an iteration and not an index
`````julia
    for c in string
        println(c)
    end
`````
- substrings can be obtained by string slices, `s[3:5]` or `s[2:end]`
- string interpolation
`````julia
    a = 3; b = 2;
    s = "$a * $b = $(a * b)"
    # s is "3 * 2 = 6"
`````
- concatenate with
`````julia
    "abd" * "def" == string("abc", "def")
`````
- __Symbols__ are strings prefixed with a colon `:green`
- these more efficient strings are used as IDs or keys, they can't be concatenated
- `methodswith(String)` returns all the functions that use it
- `search(string, char)` -- returns the index of the first char in the string
- `replace(string, str1, str2)` -- replaces `str1` in `string` with `str2`
- `split(string, char or [chars])` -- splits string at char, returns an array of strings -- if there is no char given, split uses whitespace

## Formatting numbers and strings
