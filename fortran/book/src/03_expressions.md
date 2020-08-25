# Expressions

- e-notation can be used in upper and lower case 
```fortran
    2.74E5
    2.34345e-13
```
- complex literals are written in parentheses
```fortran
    (3.2, 4)
    (1, 14)
```
- character literals are normal, escaping double quotes is done by doubling them
```fortran
    "this is ""wow"" in fortran"
    ! turns into "this is "wow" in fortran"
```
- assignment is done by the equal sign `var = expr`
- only one variable can be assigned on each sign
- operations:
    - `+` as addition
    - `-` as subtraction
    - `*` as multiplication
    - `/` as division
    - `**` as exponentiation
- order of operations: unary -, exponentiation, multiplication & division, addition & subtraction

## Intrinsic functions

- `cos(pi)` and other trigonometric functions
- conversion is done with 
    - `real(<int>)`
    - `int(<real>)` truncates real
    - `nint(<real>)` rounds real
- `sin`, `cos`, `tan`, `mod(r1, r2)` (r1 divided by r2), `sqrt`
- when ints and reals are being mixed, it's called mixed mode -- it is unintuitive and sometimes weird, explicit conversion should be done
- 
