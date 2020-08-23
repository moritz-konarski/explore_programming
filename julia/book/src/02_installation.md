# Installing the Julia Platform

- if parallelization (n concurrent processes) is to be used, compile the julia code with
`````bash
    make -j n
`````

## Working with Julia's shell

- use `quit()` or `CTRL + D` to quit the REPL
- after an expression is evaluated, the result will be stored in the variable `ans`, but only in REPL
- assign values like so:
`````julia
    a = 3
`````
- type annotations are not needed, they are inferred
- strings are defined by `"` (double quotes)
- to clear the screen but keep the data or variables, type `CTRL + L`
- to clear the workspace and variables, use `workspace()`
- all previous commands are stored in a `.julia_history` file at `/home/$USER/`
- typing `?` will give access to the docs, specific help is available through `help(<item>)`
- to find all the places a function is defined or used, type `apropos("<name>")`
- mulitple commands on one line are separated by `;`
- multi-line expressions also work and the shell will wait until the expression is complete
`````julia
julia>  if 10 > 0
            println("10 is bigger than 0")
        end
10 is bigger than 0

julia>
`````
- use tab for automatic completion, double tab to show the available functions
- starting a line with `;` makes the rest of the line a shell command
- to exit shell mode, type `backspace`
- the REPL can also execute written programs with 
`````julia
julia>  include("<name>.jl")
`````
- the content of the file will then be executed
- for keybindings see [here](http://docs.julialang.org/en/latest/manual/interacting-with-julia/#key-bindings)

## Startup option and Julia scripts

- commands can be evaluated from the command line without starting the repl
`````bash
    julia -e 'a = 6 * 7; println(a)'
`````
- a script taking arguments can be run like this
`````bash
    julia script.jl arg1 arg2 arg3
`````
- the arguments are then available in the global constant `ARGS`
- files can also execute other files by calling `include("file.jl")` in them

## Packages

- official Julia packages can be found at METADATA.jl at <https://github.com/JuliaLang/METADATA.jl>
- a searchable list can be found at <http://pkg.julialang.org/>
- Julia has a built-in package manager called `Pkg` for installing packages
- to find out which packages are installed, use `Pkg.status()`
- one of the better packages is IJulia, a jupyter mod
`````julia
    using PyPlot
    x = linspace(0, 5)
    y = cos(2x + 5)
    plot(x, y, linewidth=2.0, linestyle="--")
    title("a nice cosine")
    xlabel("x axis")
    ylabel("y axis")
`````

## How Julia works
