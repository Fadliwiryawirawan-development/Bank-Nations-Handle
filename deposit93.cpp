#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <functional>
using namespace std;

struct Transaction {
    string type;
    double amount;
};

struct Account {
    size_t pinHash;
    double balance;
    vector<Transaction> history;
};

class DebitService {
private:
    map<string, Account> accounts;

    size_t hashPin(int pin) {
        return hash<string>()(to_string(pin));
    }

public:
    void createAccount(string card, int pin, double balance) {
        accounts[card] = {hashPin(pin), balance, {}};
        cout << "Account created for card: " << card << endl;
    }

    bool authenticate(string card, int pin) {
        if (accounts.count(card) &&
            accounts[card].pinHash == hashPin(pin)) {
            return true;
        }
        return false;
    }

    void checkBalance(string card) {
        cout << "Balance: " << accounts[card].balance << endl;
    }

    void withdraw(string card, double amount) {
        if (amount <= 0) return;

        if (accounts[card].balance >= amount) {
            accounts[card].balance -= amount;
            accounts[card].history.push_back({"Withdraw", amount});
            cout << "Withdraw successful\n";
        } else {
            cout << "Insufficient funds\n";
        }
    }

    void deposit(string card, double amount) {
        accounts[card].balance += amount;
        accounts[card].history.push_back({"Deposit", amount});
        cout << "Deposit successful\n";
    }

    void transfer(string from, string to, double amount) {
        if (accounts[from].balance >= amount && accounts.count(to)) {
            accounts[from].balance -= amount;
            accounts[to].balance += amount;

            accounts[from].history.push_back({"Transfer Out", amount});
            accounts[to].history.push_back({"Transfer In", amount});

            cout << "Transfer successful\n";
        } else {
            cout << "Transfer failed\n";
        }
    }

    void showHistory(string card) {
        cout << "\nTransaction History:\n";
        for (auto &t : accounts[card].history) {
            cout << t.type << " - " << t.amount << endl;
        }
    }
};

int main() {
    DebitService bank;

    bank.createAccount("CARD001", 1234, 5000);
    bank.createAccount("CARD002", 4321, 3000);

    if (bank.authenticate("CARD001", 1234)) {
        bank.checkBalance("CARD001");
        bank.withdraw("CARD001", 1000);
        bank.deposit("CARD001", 500);
        bank.transfer("CARD001", "CARD002", 700);
        bank.checkBalance("CARD001");
        bank.showHistory("CARD001");
    } else {
        cout << "Authentication failed\n";
    }

    return 0;
}
