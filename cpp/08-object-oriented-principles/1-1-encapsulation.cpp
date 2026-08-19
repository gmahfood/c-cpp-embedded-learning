// ============================================================================
// Drill 1.1 — Encapsulation, construction, and state-mutating methods
// OOP cold drills / c-cpp-learning
//
// Concepts exercised:
//   - Encapsulation: data is private; the only way to touch it is through
//     methods that enforce the class's rules (invariants).
//   - Member initializer list construction.
//   - const member functions (read-only promise).
//   - The "guard clauses -> mutate state -> report outcome" method shape.
// ============================================================================

#include <iostream>

class BankAccount {
private:
    // Private data member. Nothing outside the class can read or write this
    // directly — that's the whole point of encapsulation. Callers must go
    // through deposit/withdraw, which lets us GUARANTEE an invariant:
    // the balance can never go negative, because withdraw refuses to overdraw.
    double balance_;

public:
    // Member initializer list: the `: balance_{initial}` part.
    //
    // WHY it matters (this is the Drill 1.2 lesson, previewed here):
    // the initializer list constructs balance_ DIRECTLY with `initial`.
    // If we instead wrote `BankAccount(double initial) { balance_ = initial; }`
    // the member would first be default-initialized and THEN assigned — two
    // steps instead of one. For a double the difference is cosmetic, but for
    // const members, reference members, and members with no default constructor
    // the initializer list is the ONLY option. Build the habit now.
    BankAccount(double initial) : balance_{initial} {}

    // Returns bool = "did the operation succeed?"
    //
    // Shape to internalize (used by both deposit and withdraw):
    //   1. guard clauses reject bad input and return early
    //   2. the actual state change happens
    //   3. return whether it worked
    // The bool is the SECONDARY job. Mutating balance_ is the primary job —
    // an operation that returns true but doesn't move money did nothing.
    bool deposit(double amount) {
        if (amount <= 0) return false;  // reject nonsense (0 or negative deposits)
        balance_ += amount;             // the actual work
        return true;                    // report success
    }

    bool withdraw(double amount) {
        if (amount <= 0) return false;        // reject nonsense amounts
        if (amount > balance_) return false;  // enforce the invariant: no overdraft.
                                              // note we return BEFORE touching balance_,
                                              // so a refused withdrawal leaves state intact.
        balance_ -= amount;                   // the actual work — only reached when valid
        return true;                          // report success
    }

    // const member function: the `const` AFTER the parameter list is a promise
    // that calling balance() will not modify the object. Position matters —
    // `const double balance()` (const before the type) would instead mean
    // "returns a const double", a completely different and unrelated thing.
    // A getter that only reads should always be const: it lets this method be
    // called on const BankAccount objects, and documents intent.
    double balance() const {
        return balance_;
    }
};

// ----------------------------------------------------------------------------
// Quick manual exercise. Try to PREDICT each printed line before running —
// tracing your own object by hand is a different (and harder) skill than
// writing it.
// ----------------------------------------------------------------------------
int main() {
    BankAccount acct{100.0};

    acct.deposit(50.0);      // 100 -> 150, returns true
    acct.withdraw(30.0);     // 150 -> 120, returns true
    bool bad = acct.withdraw(1000.0);  // refused (overdraft): balance unchanged, returns false

    std::cout << "Balance: " << acct.balance() << "\n";   // expect 120
    std::cout << "Overdraft attempt succeeded? " << std::boolalpha << bad << "\n"; // expect false

    return 0;
}