#include <iostream>
#include <map>
using namespace std;

class BankService {
private:
    map<int, double> accounts;

public:
    void createAccount(int accNo) {
        accounts[accNo] = 0.0;
        cout << "Account created: " << accNo << endl;
    }

    void deposit(int accNo, double amount) {
        if (accounts.find(accNo) != accounts.end()) {
            accounts[accNo] += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Account not found\n";
        }
    }

    void withdraw(int accNo, double amount) {
        if (accounts.find(accNo) != accounts.end()) {
            if (accounts[accNo] >= amount) {
                accounts[accNo] -= amount;
                cout << "Withdrawn: " << amount << endl;
            } else {
                cout << "Insufficient balance\n";
            }
        } else {
            cout << "Account not found\n";
        }
    }

    void checkBalance(int accNo) {
        if (accounts.find(accNo) != accounts.end()) {
            cout << "Balance: " << accounts[accNo] << endl;
        } else {
            cout << "Account not found\n";
        }
    }
};

int main() {
    BankService bank;
    
    bank.createAccount(101);
    bank.deposit(101, 5000);
    bank.withdraw(101, 1200);
    bank.checkBalance(101);

    return 0;
}
```

---
