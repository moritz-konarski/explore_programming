! program for an amortization schedule
! --------------------------------------------
! Input: 
!   loan_amount :: integer <= 250,000 usd
!   annual_interest_rate :: real
!   loan_term :: integer <= 360 monts
! Output:
!   payment_number :: integer
!   monthly_payment :: real == principal payment + interest payment
!   principal_paid :: real
!   interest_paid :: real
!   outstanding_balance :: real
! sum of all columns at the end: 
!   payment_count :: integer
!   monthly_payment_sum :: real
!   principal_payment_sum :: real

program amortization_schedule

implicit none
integer :: loan_amount, loan_term, payment_number, payment_count
real :: annual_interest_rate, principal_paid, interest_paid,    &
        outstanding_balance, monthly_payment_sum,               &
        rincipal_payment_sum, numerator, denomenator

    ! greet user and ask for input
    write (*,*) "Amortization schedule"
    write (*,*) "   Enter: loan amount   annual interest rate  ",&
                " loan term (months)"

    ! read input
    read (*,*) loan_amount, annual_interest_rate, loan_term

    ! convert values
    annual_interest_rate = annual_interest_rate / 1200.0 

    ! set initial variables
    outstanding_balance = real(loan_amount)

    do while ( outstanding_balance > 0.0 )
        
        !payment

    end do



end program amortization_schedule
