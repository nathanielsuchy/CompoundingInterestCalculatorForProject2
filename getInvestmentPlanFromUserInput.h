/*
    This program will calculate compound interest.

    Author: Nathaniel Suchy <nathaniel.suchy@snhu.edu>
    Date: October 3rd, 2021
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdlib.h>

/*
Function: Asks the user a series of question about their investment

@param (passed by reference) years - The numbers of years since the account was open.
@param (passed by reference) initialDeposit - The initial amount of money deposited when the account was open.
@param (passed by reference) monthlyDeposit - The amount of money deposited every month
@param (passed by reference) interestRate - The interest rate on the account
*/
void getInvestmentPlanFromUserInput(int& years, double& initialDeposit, double& monthlyDeposit, double& interestRate) {
    std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
    std::cout << "AIRGEAD BANK: Customer Investment Plan" << std::endl;
    std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;

    std::cout << "\nThank you for choosing our services."
        << "To get started we have to ask a few questions "
        << "to create a plan for your investments. Please answer each question with only a decimal number. "
        << "Please do not enter any symbols or other non-number characters "
        << "(a period is okay) or you'll be asked to enter the number again.\n"
        << std::endl;

    // Ask user to enter the initial investment amount, infinently loop until a number is input
    while (1) {
        std::string tmp; // Input buffer
        char* endPtr; // Pointer storage for string to double, int, long, etc functions
        std::cout << "Initial investment amount: ";
        getline(std::cin, tmp);
        initialDeposit = std::strtod(tmp.c_str(), &endPtr);

        if (initialDeposit == NULL) {
            std::cout << "Not a number!" << std::endl;
        }
        else {
            break;
        }
    }

    // Ask user to enter the monthly deposit, infinently loop until a number is input
    while (1) {
        std::string tmp; // Input buffer
        char* endPtr; // Pointer storage for string to double, int, long, etc functions
        std::cout << "Monthly deposit: ";
        getline(std::cin, tmp);
        monthlyDeposit = std::strtod(tmp.c_str(), &endPtr);

        if (monthlyDeposit == NULL) {
            std::cout << "Not a number!" << std::endl;
        }
        else {
            break;
        }
    }

    // Ask user to enter the interest rate, infinently loop until a number is input
    while (1) {
        std::string tmp; // Input buffer
        char* endPtr; // Pointer storage for string to double, int, long, etc functions
        std::cout << "Interest Rate (5% should be typed as 5, not 0.05, or the program will calculate 0.05%): ";
        getline(std::cin, tmp);
        interestRate = std::strtod(tmp.c_str(), &endPtr);

        if (interestRate == NULL) {
            std::cout << "Not a number!" << std::endl;
        }
        else {
            break;
        }
    }

    // Ask user to enter the years to invest, infinently loop until a number is input
    while (1) {
        std::string tmp; // Input buffer
        char* endPtr; // Pointer storage for string to double, int, long, etc functions
        std::cout << "Years: ";
        getline(std::cin, tmp);
        years = std::strtod(tmp.c_str(), &endPtr);

        if (years == NULL) {
            std::cout << "Not a number!" << std::endl;
        }
        else {
            break;
        }
    }

}
