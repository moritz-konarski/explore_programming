! program calculating the range of a shot given angle and velocity

program shot_range

implicit none
real, parameter ::  g = 9.81,                                   &
                    pi = 3.14159265,                            & 
                    degrees_to_radians = pi / 180.0
real :: range, phi_in_radians
integer :: phi, v_zero

    write (*,*) "Range of a shot"
    write (*,*) "   Enter angle (degrees) and &
                    velocity (meters per second)"
    read (*,*) phi, v_zero

    phi_in_radians = degrees_to_radians * real(phi)

    range = 2 * real(v_zero) ** 2 / g                           &
            * cos(phi_in_radians) * sin(phi_in_radians)

    write (*,*) "The range of this shot is "
    write (*,*) range, " meters"

end program shot_range
