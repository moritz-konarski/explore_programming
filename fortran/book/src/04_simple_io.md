# Simple Input and Output

## Write

- write is the simplest form of output
```fortran
    write (*,*) "Hello World"
```
- `(*,*)` refers to send to screen in free format
- it can also show the value of declared variables
```fortran
    integer :: num1 = 12
    write (*,*) num1
```
- if write is supplied no arguments it prints a new line
- multiple item can be chained by commas to be printed
```fortran
    integer :: num1 = 12, num2 = 2
    write (*,*) "Number 1 = ", num1, "Number 2 = ", num2
```


## Print

- the print statement is more restrictive than write, it only sends output to the screen
```fortran
    integer :: num1 = 12, num2 = 2
    print *,"Number 1 = ", num1, "Number 2 = ", num2
```

## Read

- read retrieves information from the user
```fortran
    ! reads one input
    read (*,*) ans1
    ! reads two inputs
    read (*,*) ans1, ans2
```
- if the input values are not of the appropriate type, an error occurs


