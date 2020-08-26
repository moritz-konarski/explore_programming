# Looping

## Counter Controlled Looping

```fortran
    do count_var = start, stop, step
        ...
    end do
```
- all values in the loop are integers
- if the step value is omitted, it is assumed 1
- the three values are not recomputed during looping
- if `count` is less than or equal to `stop`, the loop continues
- the `break` statement in fortran is `exit`
- `continue` in fortran is `cycle`

## Conditional Controlled Looping

```fortran
    do while ( condition )
        ...
    end do
```
- another form contains an exit statement somewhere in the loop
```fortran
    do 
        ...
        if ( condition ) exit
        ...
    end do
```
- conditional loops can be used to loop with reals, not supported by counter loops
