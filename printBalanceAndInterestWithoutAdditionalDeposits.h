#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdlib.h>

void printBalanceAndInterestWithoutAdditionalDeposits(int& years, double& initialDeposit, double& monthlyDeposit, double& interestRate)
{
    system("CLS");

    std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
    std::cout << "AIRGEAD BANK: Customer Report" << std::endl;
    std::cout << std::setw(40) << std::setfill('=') << "\n" << std::endl;
    std::cout << "Balance & Interest without Additional Deposits" << std::endl;
    std::cout << std::setw(40) << std::setfill('-') << "\n" << std::endl;
    std::cout << "Year" << "\t\t" << "Balance" << "\t\t" << "Interest" << std::endl;
    std::cout << std::setw(40) << std::setfill('-') << "\n" << std::endl;

    // Print out report data for each year
    double prevYearInterest = 0;

    for (int i = 1; i <= years; ++i) {

        // To calculate interest I use the general compounding interest function which
        // returns the total. To work around this I subtract the initial deposit to get just the interest.
        // To get just the years interest, I subtract the previous years interest.

        double interest = ((calculateCompoundInterest(i, initialDeposit, 0, interestRate)
            - (initialDeposit + ((monthlyDeposit * 0) * i)))) - prevYearInterest;

        prevYearInterest = (calculateCompoundInterest(i, initialDeposit, 0, interestRate)
            - (initialDeposit + ((monthlyDeposit * 0) * i)));


        // Set formatting options for number output
        std::cout << std::setprecision(2) << std::fixed;

        // Output the result
        std::cout << i << "\t\t$" << calculateCompoundInterest(i, initialDeposit, 0, interestRate) << "\t\t$" << interest << std::endl;
    }

    // Report finished let the user read it then give them a prompt to return to the main menu
    std::cout << "\nPress enter to return to the menu" << std::endl;
    std::string tmp; // input buffer for new line
    std::getline(std::cin, tmp);
}