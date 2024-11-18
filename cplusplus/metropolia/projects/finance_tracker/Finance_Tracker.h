#ifndef FINANCE_TRACKER_H
#define FINANCE_TRACKER_H

#pragma once
#include "Transaction.h"
#include <vector>

class Finance_Tracker {
public:
    Finance_Tracker();
    ~Finance_Tracker();

    void initialize();
    void make_transaction(bool);
    void write_to_file() const;
    void read_from_file();
    void print_report(int sort_level) const;
public:
    std::vector<Transaction> transactions_record;
};

#endif //FINANCE_TRACKER_H