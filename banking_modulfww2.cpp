#include <iostream>
#include <map>
using namespace std;

struct Account {
    int pin;
    double balance;
};

class DebitCardService {
private:
    map<int, Account> accounts; // cardNumber → Account

public:
    void addAccount(int cardNumber, int pin, double balance) {
        accounts[cardNumber] = {pin, balance};
    }

    bool authenticate(int cardNumber, int pin) {
        if (accounts.count(cardNumber) && accounts[cardNumber].pin == pin) {
            return true;
        }
        return false;
    }

    void checkBalance(int cardNumber) {
        cout << "Balance: " << accounts[cardNumber].balance << endl;
    }

    void withdraw(int cardNumber, double amount) {
        if (amount <= accounts[cardNumber].balance) {
            accounts[cardNumber].balance -= amount;
            cout << "Withdraw successful\n";
        } else {
            cout << "Insufficient funds\n";
        }
    }

    void transfer(int fromCard, int toCard, double amount) {
        if (accounts[fromCard].balance >= amount) {
            accounts[fromCard].balance -= amount;
            accounts[toCard].balance += amount;
            cout << "Transfer successful\n";
        } else {
            cout << "Transfer failed\n";
        }
    }
};

int main() {
    DebitCardService bank;

    bank.addAccount(123456, 1111, 5000);
    bank.addAccount(654321, 2222, 3000);

    if (bank.authenticate(123456, 1111)) {
        bank.checkBalance(123456);
        bank.withdraw(123456, 1000);
        bank.transfer(123456, 654321, 500);
        bank.checkBalance(123456);
    } else {
        cout << "Authentication failed\n";
    }

    return 0;
}
