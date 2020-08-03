program fortrantut
    implicit none
    
! constant 32 bit float
    real, parameter :: PI = 3.141592
! variable f32
    real :: r_num1 = 0.0, r_num2 = 0.0

! f64
    double precision :: dbl_num = 1.111d+0
! int
    integer :: i_num1 = 0, i_num2 = 0
! bool
    logical :: can_vote = .true.
! char
    character (len = 10) :: month
! complex number
    complex :: com_num = (2.0, 4.0)

! huge returns the max value
    print *, "Biggest Real  ", huge(r_num1)
    print *, "Biggest Int   ", huge(i_num1)
! tiny returns the smallest value
    print *, "Smallest Real ", tiny(r_num1)

! kind returns the storage in bytes a datatype takes up
    print "(a4, i4)", "Int ", kind(i_num1)
    print "(a5, i4)", "Real ", kind(r_num1)
    print "(a7, i4)", "Double ", kind(dbl_num)
    print "(a8, i4)", "Logical ", kind(can_vote)

end program fortrantut
