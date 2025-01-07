using doable_danny.src.OopPrinciples.Encapsulation;

BankAccount bankAccount = new BankAccount(100);

Console.WriteLine($"Initial balance: {bankAccount.getBalance()}");

bankAccount.Deposit(50);

Console.WriteLine($"Balance after deposit: {bankAccount.getBalance()}");

bankAccount.Withdraw(100);

Console.WriteLine($"Balance after withdrawal: {bankAccount.getBalance()}");
