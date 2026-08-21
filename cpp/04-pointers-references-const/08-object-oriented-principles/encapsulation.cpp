#include <iostream>

class BankAccount {
private:
    double balance_;  // private: only touchable via methods that enforce no-overdraft

public:
    // initializer list: constructs balance_ directly (habit for const/ref members later)
    BankAccount(double initial) : balance_{initial} {}

    bool deposit(double amount) {
        if (amount <= 0) return false;
        balance_ += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) return false;
        if (amount > balance_) return false;  // refuse before mutating: invariant holds
        balance_ -= amount;
        return true;
    }

    double balance() const { return balance_; }  // const AFTER params = "won't modify object"
};

int main() {
    BankAccount acct{100.0};
    acct.deposit(50.0);
    acct.withdraw(30.0);
    bool bad = acct.withdraw(1000.0);  // refused: unchanged

    std::cout << "Balance: " << acct.balance() << "\n";                 // 120
    std::cout << std::boolalpha << "Overdraft ok? " << bad << "\n";     // false
    return 0;
}