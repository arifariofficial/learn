#include "Finance_Tracker.h"
#include <iostream>
#include <fstream>
#include <cstdio>   // for `sscanf`
#include <sstream>

Finance_Tracker::Finance_Tracker() = default;

Finance_Tracker::~Finance_Tracker() = default;

void Finance_Tracker::initialize() {
    transactions_record.clear();
}

void Finance_Tracker::write_to_file() const {
    ofstream sFile;
    sFile.open("Finances");

    if (sFile) {
        for (auto t_record: transactions_record) {
            sFile << t_record;
        }

        sFile.close();
    } else {
        std::cout << "Failed to open file to write transanctions." << std::endl;
    }
}

void Finance_Tracker::read_from_file() {
    ifstream sFile;
    sFile.open("Finances");

    // reset previous records
    transactions_record.clear();

    if (sFile) {
        Transaction t_record;
        while (sFile >> t_record) {
            transactions_record.push_back(t_record);
        }

        sFile.close();
    } else {
        std::cout << "Failed to open file to read transactions." << std::endl;
    }
}

void Finance_Tracker::make_transaction(const bool type) {
    Transaction record;
    record.type = type;

    std::cout << "Please enter amount: ";
    std::cin >> record.amount;

    std::cout << "Please enter Description: ";
    std::cin.ignore(); // Ignore leftover newline from previous input
    std::getline(std::cin, record.desc);

    std::cout << "Please enter date (DD.MM.YYYY): ";
    std::string date_input;
    std::getline(std::cin, date_input);

    // Use istringstream to parse the date
    std::istringstream date_stream(date_input);
    char delimiter2; // To capture the '.' between day, month, and year

    if (char delimiter1; !(date_stream >> record.date.dd >> delimiter1 >> record.date.mm >> delimiter2 >> record.date.
                           yyyy) ||
                         delimiter1 != '.' || delimiter2 != '.' ||
                         record.date.dd < 1 || record.date.dd > 31 ||
                         record.date.mm < 1 || record.date.mm > 12 ||
                         record.date.yyyy < 1000 || record.date.yyyy > 9999) {
        std::cout << "Invalid date format or out of range. Please use DD.MM.YYYY and enter valid values." << std::endl;
        return;
    }

    // Push the valid transaction into the records
    transactions_record.push_back(record);
}
void Finance_Tracker::print_report(const int sort_level) const {
    std::cout << "~~~~~~ Transactions Report ~~~~~~" << std::endl;
    std::cout << "Type\tDate      \tAmount    \tDescription\n" << std::endl;

    double total_incomes = 0.0;
    double total_expenses = 0.0;

    for (int i = 0; i <= 1; ++i) {
        for (const auto &record: transactions_record) {
            if (sort_level < 2 && ((static_cast<bool>(i) ^ static_cast<bool>(sort_level)) ^ record.type)) {
                continue;
            }

            printf("%s\t%02d.%02d.%04d\t%-10.2f\t%s\n", record.type ? "EXPENSE" : "INCOME", record.date.dd,
                   record.date.mm, record.date.yyyy, record.amount, record.desc.c_str());

            if (record.type)
                total_expenses += record.amount;
            else
                total_incomes += record.amount;
        }

        if (sort_level > 1)
            break;
    }

    if (sort_level == 3) {
        std::cout << "\n ~~~~~~ Summary ~~~~~~" << std::endl;
        printf(
            "Total Transactions: %lu\nTotal Incomes:      %.2lf\nTotal Expenses:     %.2lf\nNet Amount:         %.2f\n",
            transactions_record.size(),
            total_incomes, total_expenses, (total_incomes - total_expenses));
    }
}