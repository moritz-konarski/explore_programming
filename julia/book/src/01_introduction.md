# The Rationale for Julia

## The scope of Julia

- born out of frustration with existing tools for technical computing
- prototyping needs a easy-to-use language, flexible, high-level language so 
the focus may be on the problem
- actual computation needs maximum performance hence for production things tend to be re-written in C or Fortran
- this lead to prototyping in slow but easy languages and then re-writes in difficult but fast languages
- Julia was designed to bridge this gap -- using LLVM JIT (Just in Time) makes near-C speeds possible while keeping high-level usability

This resulted in:

- open source and liberal license (MIT)
- easy to use and learn, elegant, clear, dynamic, familiar, almost like pseudocode:
`````julia
    x -> 7x^3 + 30x^2 + 5x + 42
`````
- Julia provides the needed speed without the need to switch languages
- metaprogramming to increase capability
- useable for normal computing tasks, not just pure computing
- easy-to-use multicore and parallel capabilities

## Julia's place among the other programming languages

- Julia brings together the two worlds of typed and untyped languages
- Julia does not have a static compilation step but uses a type-inference engine to nonetheless deliver similar speeds
- types can still be used to make compilation easier and to document the code
- _dynamic multiple dispatch_ is the approach to pick the best fitting function out of a pool of functions depending on the data type, it's basically polymorphism with type inference
- Julia does not have static type checking however, runtime errors can occur if data types do not match
- Julia also makes it easy to design pure functions and apply functional programming
- Julia is also suited for general purpose programming similar to Python

## A comparison with other languages for the data scientist

- Julia's speed approaches C and leaves all other normal alternatives behind
- one of Julia's goals is that one never has to step down to C
- Julia is especially good at running MATLAB and R style programs

### MATLAB

- the syntax should be very familiar for MATLAB users, but Julia is more general purpose
- most function names are similar to MATLAB and not R
- Julia is much faster than MATLAB, but it can also interface with it

### R

- until now R has dominated statistics
- Julia has the same level of usability, but is 10 to 1000 times faster
- Julia also has an interface to R

### Python

- Julia is again much faster than Python, reads similar to it, and can interface with it

## Useful Links

- main website: <http://julialang.org>
- documentation: <http://docs.julialang.org>
- packages: <http://pkg.julialang.org>
