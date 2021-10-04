/*
    This program will calculate compound interest.

    Author: Nathaniel Suchy <nathaniel.suchy@snhu.edu>
    Date: October 3rd, 2021
*/

#pragma once
#include <math.h>

/*
* Function: Calculates compound interest. This assumes that interest is compounded monthly.
*
* @param years - The numbers of years since the account was open.
* @param initialDeposit - The initial amount of money deposited when the account was open.
* @param monthlyDeposit - The amount of money deposited every month
* @param interestRate - The interest rate on the account
*
* @return The account balance as a double after interest is compounded based on the number of years.
*/
double calculateCompoundInterest(int years, double initialDeposit, double monthlyDeposit, double interestRate)
{
    double totalAmount = initialDeposit;
    double interest = 0;
    for (int i = 1; i <= (years * 12); ++i) {
        // First make the deposit
        totalAmount += monthlyDeposit;

        // Then calculate  and add interest
        totalAmount = totalAmount * (1+ (interestRate / 100) / 12);
    }

    return totalAmount;
}
