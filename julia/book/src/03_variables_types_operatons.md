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
