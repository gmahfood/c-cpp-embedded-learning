// Demonstrates: default, parameterized, and copy constructors, and when each fires.
// Key: Widget c = b; is construction (copy ctor), NOT assignment, because c is
// being born on that line. Destructors still fire in reverse order: c, b, a.

#include <iostream>

struct Widget {
    int id;

    Widget() : id(0) {
        std::cout << "default ctor, id=" << id << "\n";
    }
    Widget(int n) : id(n) {
        std::cout << "param ctor, id=" << id << "\n";
    }
    Widget(const Widget& other) : id(other.id) {
        std::cout << "copy ctor, id=" << id << "\n";
    }
    ~Widget() {
        std::cout << "dtor, id=" << id << "\n";
    }
};

int main() {
    Widget a;         // which ctor fires?
    Widget b(7);      // which ctor fires?
    Widget c = b;     // which ctor fires?
    std::cout << "body\n";
}