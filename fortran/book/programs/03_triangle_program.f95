! program taking two sides of a right triangle as input 
! and returning the length of the hypotenuse and the perimeter

program triangle_sides

implicit none
real :: a, b, c, perimeter

    print *, "== Right-angle Triangle Calculator =="
    print *, "Finds length of hypotenuse and perimeter."
    print *, "See https://en.wikipedia.org/wiki/Right_triangle"
    write (*,*)

    print *, "Enter the length of the two legs (catheti) a &
        and b as decimal numbers"

    read (*,*) a, b

    c = sqrt(a ** 2 + b ** 2)
    perimeter = a + b + c

    print *, "Hypotenuse c = ", c
    print *, "perimeter = ", perimeter

end program triangle_sides
