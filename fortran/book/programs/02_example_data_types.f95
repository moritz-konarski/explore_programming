! data type declaration
program data_example
    
implicit none

integer :: test = 15
integer*8 :: large = 32e15
real :: rnum = 3.1415
real(kind=8) :: rlarge = 23.234e32
character(11) :: msg = "Hello world"

    write (*,*) "Greeting: ", msg

end program data_example
