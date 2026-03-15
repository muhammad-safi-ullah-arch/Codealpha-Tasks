#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
   Class: Transaction
   Purpose: Store details about each transaction
*/
class Transaction
{
public:
    string type;   // deposit, withdraw, transfer
    double amount;

    // Constructor
    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
};

/*
   Class: Account
   Purpose: Manage account balance and transactions
*/
class Account
{
private:
    int accountNumber;
    double balance;
    vector<Transaction> history; // store transaction history

public:

    // Constructor
    Account(int accNo, double initialBalance)
    {
        accountNumber = accNo;
        balance = initialBalance;
    }

    /*
       Function: deposit
       Adds money into the account
    */
    void deposit(double amount)
    {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));

        cout << "Deposit successful.\n";
    }

    /*
       Function: withdraw
       Withdraw money if balance is sufficient
    */
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance.\n";
            return;
        }

        balance -= amount;
        history.push_back(Transaction("Withdraw", amount));

        cout << "Withdrawal successful.\n";
    }

    /*
       Function: transfer
       Transfer money to another account
    */
    void transfer(Account &receiver, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance for transfer.\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        history.push_back(Transaction("Transfer Sent", amount));
        receiver.history.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer successful.\n";
    }

    /*
       Function: showBalance
       Displays current account balance
    */
    void showBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    /*
       Function: showTransactions
       Displays transaction history
    */
    void showTransactions()
    {
        cout << "\nTransaction History:\n";

        for (int i = 0; i < history.size(); i++)
        {
            cout << history[i].type << " : " << history[i].amount << endl;
        }
    }

    int getAccountNumber()
    {
        return accountNumber;
    }
};

/*
   Class: Customer
   Purpose: Store customer information and their account
*/
class Customer
{
public:
    string name;
    int customerID;
    Account account;

    // Constructor
    Customer(string n, int id, int accNo, double balance)
        : account(accNo, balance)
    {
        name = n;
        customerID = id;
    }

    /*
       Function: displayCustomer
       Shows customer and account details
    */
    void displayCustomer()
    {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Account Number: " << account.getAccountNumber() << endl;

        account.showBalance();
    }
};


/*
   Main Program
*/
int main()
{
    // Creating two customers
    Customer c1("Ali", 101, 1001, 5000);
    Customer c2("Ahmed", 102, 1002, 3000);

    int choice;
    double amount;

    do
    {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Account Info\n";
        cout << "5. Show Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount: ";
            cin >> amount;
            c1.account.deposit(amount);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amount;
            c1.account.withdraw(amount);
            break;

        case 3:
            cout << "Enter amount to transfer to Ahmed: ";
            cin >> amount;
            c1.account.transfer(c2.account, amount);
            break;

        case 4:
            c1.displayCustomer();
            break;

        case 5:
            c1.account.showTransactions();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}