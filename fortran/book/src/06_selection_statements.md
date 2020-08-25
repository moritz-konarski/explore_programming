# Selection Statements

- relational operators in fortran

| Operation | normal operator | alternate operator |
|:---------:|:---------------:|:------------------:|
| greater   | `>`             | `.gt.`             |
| greater or equal | `>=`     | `.ge.`             |
| less      | `<`             | `.lt.`             |
| less or equal    | `<=`     | `.le.`             |
| equal     | `==`            | `.eq.`             |
| not equal | `/=`            | `.ne.`             |

- conditional expressions are enclosed in brackets
```fortran
    (weight > 0)
```
- logical operators in fortran
```fortran
    .and.       ! and statement
    .or.        ! or statement
    .not.       ! not statement
```
- with these operators logical statements can be combined
```fortran
    ( (weight > 0) .and. (weight < 120) )
```
- if then statement
```fortran
    if ( <condition> ) then
        <do stuff>
    end if
```
- simple if then statement
```fortran
    if ( <condition> ) <single statement>
```
- if then else statement
```fortran
    if ( <condition> ) then
        <stuff>
    else
        <stuff>
    end if
```
- else if statement
```fortran
    if ( <condition> ) then
        <stuff>
    else if ( <condition> ) then
        <stuff>
    else
        <stuff>
    end if
```
- select case statement
