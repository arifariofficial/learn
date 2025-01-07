using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace doable_danny.src.OopPrinciples.Encapsulation
{
    public class BankAccount
    {
        private decimal balance;

        public decimal getBalance()
        {
            return this.balance;
        }

        public BankAccount(decimal balance)
        {
            Deposit(balance);
        }

        public void Deposit(decimal amount)
        {
            if (amount <= 0)
            {
                throw new ArgumentOutOfRangeException("Deposit amount must be greater than 0");
            }

            this.balance += amount;
        }

        public void Withdraw(decimal amount)
        {
            if (amount <= 0)
            {
                throw new ArgumentOutOfRangeException("Withdrawal amount must be greater than 0");
            }

            if (amount > this.balance)
            {
                throw new InvalidOperationException("Insufficient funds");
            }

            this.balance -= amount;
        }
    }
}
