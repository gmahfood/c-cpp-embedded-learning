// Demonstrates: objects construct in forward order, destruct in reverse.
// Last built is first destroyed (stack is LIFO). Parameter n vs member name.

#include <iostream>

struct Widget {
    const char* name;
    Widget(const char* n) : name(n) { std::cout << "ctor " << name << "\n"; }
    ~Widget() { std::cout << "dtor " << name << "\n"; }
};

int main() {
    Widget a("a");
    Widget b("b");
    std::cout << "body\n";
}