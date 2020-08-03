program fortrantut
    implicit none

! declare a 20 character string
    character*20 :: name
! different way to declare a 20 character string
    character (len = 20) :: f_name, l_name

! print a string
    print *, "What's your name "
! read two elements of input 
    read *, f_name, l_name
! print three strings, trim the strings
    print *, "Hello ", trim(f_name), " ", trim(l_name)

end program fortrantut
