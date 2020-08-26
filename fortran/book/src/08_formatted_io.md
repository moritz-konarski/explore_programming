# Formatted Input/Output

- the second `*` in read and write statements can be replaced by format instructions
```fortran 
    read  (*, '( formatting )') <vars>
    write (*, '( formatting )') <vars / expressions>
```
- convention of symbols to be used
    - `w` -- number of used positions
    - `m` -- minimum number of positions
    - `d` -- digits to the right of the decimal point
    - `n` -- number or count
    - `c` -- column number
    - `r` -- repeat count
- basic table of common formats

|  Description      |  Specifier        |
|:------------------|:-----------------:|
| Integers          | `rIw` or `rIw.m`  |
| Reals             | `rFw.d`           |
| Logicals          | `rlw`             |
| Characters        | `rA` or `rAw`     |
| Hor. pos. space   | `nX`              |
| Hor. pos. column  | `Tc`              |
| Vertical Space    | `n/`              |

## Integer formatting

- use `i` instead of `I` and otherwise it's ok
```fortran
    write (*,'(i5.6)') 1234
    ! > 001234
```

## Real formatting

- `w` here is the total number of places, including the decimal point, `f` instead of `F`
```fortran
    write (*,'(f9.4)') 234.34556
    ! > " 234.3455"
```

## Horizontal Positioning

- `nX` inserts `n` spaces, `Tc` goes to column `c`

## Logical Formatting

- `L` is `l` here, the variables are printed as `T` or `F`
- we can specify how many places should be displayed

## Character Formatting

- if no length is given, the full length is used
- if the given length is too short, the string is cut off
- the `trim()` function remove excess white space

## Advance Clause

- if one does not want a new line after `write`
```fortran
    write(*, '(a)', advance=no) "Enter number: "
```
- options are `yes` and `no`
