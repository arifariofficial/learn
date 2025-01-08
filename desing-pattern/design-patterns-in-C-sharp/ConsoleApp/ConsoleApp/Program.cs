using ConsoleApp.OopPrinciples.Encapsulation;

BankAccount bankAccount = new BankAccount(100);

Console.WriteLine($"Initial balance: {bankAccount.getBalance()}");

bankAccount.Deposit(50);

Console.WriteLine($"After depositing 50: {bankAccount.getBalance()}");

bankAccount.Withdraw(100);

Console.WriteLine($"After withdrawing 100: {bankAccount.getBalance()}");