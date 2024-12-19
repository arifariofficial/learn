#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma once
#include<string>

typedef struct {
    int dd;
    int mm;
    int yyyy;
} date_t;

using namespace std;
class Transaction {
public:
    Transaction();
    Transaction(bool t_type, string t_desc, int t_amount, date_t t_date);
    friend ostream &operator<<(ostream &output, Transaction &ct);
    friend istream &operator>>(istream &input, Transaction &ct);

    //private:
    bool type; //0 INCOME, 1 EXPENSE
    string desc;
    double amount;
    date_t date{};
};

#endif //TRANSACTION_H