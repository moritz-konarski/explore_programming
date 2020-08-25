# Introduction

- knowing how computers work is good to know
- problem solving and analytical skills are very important
- fortran (FORmula TRANslation) was specifically designed for scientific and engineering applications
- complete fortran reference can be found at <https://gcc.gnu.org/wiki/GFortran>

## Basic Programming

- a fortran program starts with `program <name>` and ends with `end program <name>`, name being an appropriate name
- the name has to start with a letter and can then contain letters, numbers and underscores, at most 32 characters
- capitalization does not make a difference
- comments are designated by exclamation points, everything following them is ignored
```fortran
    program hello

    ! some code

    end program hello
```
- simple output is done with `write`
```fortran
    ! Hello World Program
    program hello_world

        write(*,*) "Hello, world!"

    end program hello_world
```
- after compiling the code using `gfortran hello_world.f95` the program can be executed
- one useful option is to compile with bounds checking `gfortran -fcheck=bounds ...`

