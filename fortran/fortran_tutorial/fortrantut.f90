program fortrantut
    implicit none
    
! integers: <number of ints to be printed>i<num width>
! stuff is right justified by default
    print *, "A number ", 10

! five spaces per int for 3 times per line
    print "(3i5)", 7, 6, 8

! five spaces per integer, but each on its own line
    print "(i5)", 7, 6, 8

! floats: <repititions>f<width>.<decimals>
! print floats
    print "(2f8.5)", 3.14159265, 2.234345

! print new line with /
! print strings with <reps>a<width>
    print "(/, 2a8)", "Name", "Age"

! use scientific notation: e<shift>.<decimals>
    print "(e10.3)", 123.345

! combine formatted printing with commas
    print "(a5, i2)", "I am ", 44

end program fortrantut
