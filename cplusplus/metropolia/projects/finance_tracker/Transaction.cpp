#include "Transaction.h"
#include <iostream>
#include <string>

// Default constructor initialization
Transaction::Transaction() {
    type = false;
    amount = 0.0;
    desc = "";
    date.dd = 0;
    date.mm = 0;
    date.yyyy = 0;
}

ostream &operator<<(ostream &output, Transaction &ct) {
    ranges::replace(ct.desc, ' ', '#');
    output << ct.type << std::endl;
    output << ct.desc << std::endl;
    output << ct.amount << std::endl;
    output << ct.date.dd << std::endl;
    output << ct.date.mm << std::endl;
    output << ct.date.yyyy << std::endl;

    //undo the change in original record
    ranges::replace(ct.desc, '#', ' ');

    return output;
}

istream &operator>>(istream &is, Transaction &transactin) {
    std::string data;

    is >> transactin.type;
    is >> transactin.desc;
    is >> transactin.amount;
    is >> transactin.date.dd;
    is >> transactin.date.mm;
    is >> transactin.date.yyyy;

    ranges::replace(transactin.desc, '#', ' ');
    return is;
}