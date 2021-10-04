#pragma once

/*
Function - This command clears the console screen and then lists out the possible commands.
*/
void printMenuBanner(int& years, double& initialDeposit, double& monthlyDeposit, double& interestRate) {
    system("CLS");
    std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
    std::cout << "AIRGEAD BANK: Service Menu" << std::endl;
    std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
    std::cout << "\nYou plan to deposit $"
        << initialDeposit
        << " and deposit $"
        << monthlyDeposit
        << " every month. You plan to do this for "
        << years
        << " years"
        << " at a "
        << interestRate
        << "% interest rate. What would you like to do?"
        << std::endl;
    std::cout << "\n" << "1. Change your investment plan" << std::endl;
    std::cout << "\n" << "2. View Balance & Interest without Additional Deposits" << std::endl;
    std::cout << "\n" << "3. View Balance & Interest with Additional Deposits" << std::endl;
    std::cout << "\n" << "4. Exit the program" << "\n" << std::endl;
}
