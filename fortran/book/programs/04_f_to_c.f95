! program converting fahrenheit to celsius

program f_to_c
    
implicit none
real, parameter :: multiplicative_const = 5.0 / 9.0,        &
                   subtractive_const = 32.0
real :: celsius
integer :: fahrenheit

    write (*,*) "Please enter degrees Fahrenheit for conversion: "
    read (*,*) fahrenheit

    select case ( fahrenheit )
        case ( -50 : 150 )
            celsius = multiplicative_const *                &
                        (real(fahrenheit) - subtractive_const)
            write (*,*) "Fahrenheit ", fahrenheit,          & 
                        " = Celsius ", celsius

        case default
            write (*,*) "Please enter a value between -50 and 150"
    end select

end program f_to_c
