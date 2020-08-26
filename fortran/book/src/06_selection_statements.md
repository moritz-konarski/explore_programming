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
```fortran
    select case ( var )
        case ( selector )
            ...
        case default
            ...
    end select
```
- selectors can be
```fortran
    ! only 1 value
    ( value )
    ! from val1 to val2 inclusive
    ( val1 : val2 )
    ! greater or equal val1
    ( val1 : )
    ! less or equal val2
    ( : val2 )
```
- there can also be lists of numbers in the selector
```fortran
    case (1,3,4,5,6,7)
        ...
```
