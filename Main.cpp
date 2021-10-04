/*
    This program will calculate compound interest.

    Author: Nathaniel Suchy <nathaniel.suchy@snhu.edu>
    Date: October 3rd, 2021
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#ifdef _WIN32 // Make sure to use ifdef guards or the program could have compilation errors on macOS and Linux
    #include <Windows.h>
#endif
#include "Interest.h"
#include "getInvestmentPlanFromUserInput.h"
#include "printMenuBanner.h"
#include "printBalanceAndInterestWithAdditionalDeposits.h"
#include "printBalanceAndInterestWithoutAdditionalDeposits.h"

/*
    Function: Primary entry point for the program.

    @params None
    @return Returns 0 on successful exit, or a non-zero exit code if an unhandled exception occurs
*/
int main()
{
    // Declare variables to store the number of years, initial deposit, monthly deposit, and the interest rate
    int years;
    double initialDeposit;
    double monthlyDeposit;
    double interestRate;

    // Ask the user to input data for their investment plan
    getInvestmentPlanFromUserInput(years, initialDeposit, monthlyDeposit, interestRate);
    
    // Primary event-loop
    while (1) {
        std::string tmp; // Input buffer
        char* endPtr; // Pointer storage for string to double, int, long, etc functions
        int commandChoice = 0;

        printMenuBanner(years, initialDeposit, monthlyDeposit, interestRate);

        std::cout << "Enter a choice: ";
        getline(std::cin, tmp);
        commandChoice = std::strtod(tmp.c_str(), &endPtr);

        switch (commandChoice) {
            case 1:
                getInvestmentPlanFromUserInput(years, initialDeposit, monthlyDeposit, interestRate);
                break;
            case 2:
                printBalanceAndInterestWithoutAdditionalDeposits(years, initialDeposit, monthlyDeposit, interestRate);
                break;
            case 3:
                printBalanceAndInterestWithAdditionalDeposits(years, initialDeposit, monthlyDeposit, interestRate);
                break;
            case 4:
                std::cout << "All done. Exiting the program!" << std::endl;
                exit(0);
            default:
                // Visual Studio includes the headers for Windows Applications so you can use Windows.h
                // to make pretty popup boxes for error handling.
                // Any other OS will just get standard text output.
                #ifdef _WIN32
                    MessageBox(nullptr, TEXT("You entered an invalid command!"), TEXT("Error"), MB_OK);
                #elif
                    std::cout << "Invalid command choice!" << std::endl;
                    sleep(5); // Pauses the program for 5 seconds so the user has time to see the error message
                #endif
        }
    }
    return 0;
}