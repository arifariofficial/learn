#include <iostream>
#include "Finance_Tracker.h"

int main() {
    std::cout << "\n >>>>>> Welcome to Personal Finance Tracker <<<<<<" << std::endl;

    Finance_Tracker tracker;
    tracker.initialize();

    int option;

    do {
        std::cout << "\nPlease choose an option from 1-7:" << std::endl;
        std::cout << "1- Initialize" << std::endl;
        std::cout << "2- Write to File" << std::endl;
        std::cout << "3- Read from File" << std::endl;
        std::cout << "4- Add Income" << std::endl;
        std::cout << "5- Add Expense" << std::endl;
        std::cout << "6- Print Report" << std::endl;
        std::cout << "7- Print Sorted Report" << std::endl;
        std::cout << "0- Exit" << std::endl;
        std::cout << "Your choice: ";

        while (!(std::cin >> option) || option < 0 || option > 7) {
            std::cout << "Invalid input! Please enter a number between 0 and 7: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (option) {
            case 1:
                tracker.initialize();
                break;

            case 2:
                tracker.write_to_file();
                break;

            case 3:
                tracker.read_from_file();
                break;

            case 4:
                tracker.make_transaction(false); // Add income
                break;

            case 5:
                tracker.make_transaction(true); // Add expense
                break;

            case 6:
                tracker.print_report(3); // General report
                break;

            case 7: {
                char sub_opt;
                std::cout << "Choose a, b, or c for sorted report listing:\n";
                std::cout << "a - All Transactions\n";
                std::cout << "b - Expense First, then Income\n";
                std::cout << "c - Income First, then Expense\n";
                std::cout << "Your choice: ";

                std::cin >> sub_opt;

                switch (sub_opt) {
                    case 'a':
                        tracker.print_report(2); // All Transactions
                        break;
                    case 'b':
                        tracker.print_report(1); // Expense first
                        break;
                    case 'c':
                        tracker.print_report(0); // Income first
                        break;
                    default:
                        std::cout << "Invalid choice, returning to main menu." << std::endl;
                        break;
                }
                break;
            }

            case 0:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;

            default:
                std::cout << "Unknown error occurred." << std::endl;
                break;
        }
    } while (option != 0);

    return 0;
}