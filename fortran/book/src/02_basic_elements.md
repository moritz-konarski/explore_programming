# Basic Elements

- variables must be declared at the start of the program
- variable names are 32 chars long at most, start with a letter, and can contain letters, characters, and underscores -- capitalization does not matter
- data can either be represented as a literal or as a variable
- the data types are
    - integer: whole number, integer division shenanigans 
    - real: floating point numbers
    - complex: a complex number $a + ib$ where a and b are reals
    - character: ASCII characters or strings
    - logical: `.true.` and `.false.` booleans
- `implicit none` at the start of the program will turn off implicit typing which is bad practice anyways

## Declarations

- variables must all be declared before executable statements in the program
```fortran
    <type> :: <list of var names>
    ! for example
    integer :: age, points
    real :: area
    complex :: root
    logical :: is_true
    character :: ans_char
```
- type mismatch is bad and the compiler might actually implicitly convert some things, but that is not best practice
- initializations are done using equal sings
```fortran
    integer :: age = 21, points = 10
```
- constants are defined using the `parameter` keyword
```fortran
    real, parameter :: pi = 3.14159265
```
- comments should contain useful and reference information about the program
- if a line is to be continued on the next one, an ampersand can be used
```fortran
    A = 174.5 * year            &
        + count / 100.0
```
- to declare a string, use 
```fortran
    character(11) :: msg = "Hello World"
```
- larger variables of int and float can be declared by giving the byte amounts
```fortran
    integer :: num                  ! 32 bit
    integer*8 :: bignum             ! 64 bit
    integer(kind=8) :: biggernum    ! 64 bit

    real :: rnum                    ! 32 bit
    real*8 :: bigrnum               ! 64 bit
    real(kind=8) :: biggerrnum      ! 64 bit
```
