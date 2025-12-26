#include <iostream>
#include <vector>
#include <iomainip>
#include <string>

using namespace std; 

class Account {
    private:
    string accountType;
    double balance;

    public:
    Account(string type, double initialDeposit)
    {
        accountType = type;
        balance = initialDeposit;
    };

    void deposit(double amount) {
        balance += amount;
        cout << "₵" << amount << "Deposited Successfully.\n";
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Funds.\n";
            return false;
        }
        balance -= amount;
        cout << "₵" << amount << "Withdrawn Successfully.\n";
        return true;
    }

    double getBalance() const {
        return balance;
    }

    string getType() const {
        return accountType;
    }

}

class Customer {
    private:
    string name, phone, address, id;
    Account* account;

    public:
    Customer(string cname, string cphone, string caddress, string cid,
    string accountType, double initialDeposit) 
    {
        name = cname;
        phone = cphone;
        address = caddress;
        id  = cid;
        account = new Account(accountType, initialDesposit);
    }

    ~Customer() {
        delete account;
    }

    string getId() const {
        return id;
    }

    void showDetails() const {
        cout << "----------------------------------------\n";
        cout << "Customer Name: " << name << "/n";
        cout << "Phone Number: " << phone << "/n";
        cout << "Address: " << address << "/n";
        cout << "ID: " << id < "/n";
        cout << "Account Type: " << account << "/n";
        cout << fixed << setprecision(2);
        cout << "Current Balance: ?" << account ->getBalance() <<"\n";
        cout << "----------------------------------------\n";
    }
}