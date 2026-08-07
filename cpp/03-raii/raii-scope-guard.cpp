// Demonstrates: RAII. Resource released automatically when the object leaves
// scope, even on an early return (no manual cleanup call). Release runs in
// reverse order of acquisition.

#include <iostream>

class Guard {
    const char* name;
public:
    Guard(const char* n) : name(n) {
        std::cout << "acquire " << name << "\n";
    }
    ~Guard() {
        std::cout << "release " << name << "\n";
    }
};

void run(bool fail) {
    Guard a("A");
    if (fail) {
        std::cout << "early exit\n";
        return;
    }
    Guard b("B");
    std::cout << "normal path\n";
}

int main() {
    std::cout << "-- fail case --\n";
    run(true);
    std::cout << "-- normal case --\n";
    run(false);
}