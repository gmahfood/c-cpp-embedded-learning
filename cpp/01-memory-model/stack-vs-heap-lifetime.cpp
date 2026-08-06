// Demonstrates: stack objects destroy at scope exit, heap objects
// only destroy on delete. Construction always precedes destruction.

#include <iostream>

struct Widget {
    Widget()  { std::cout << "ctor\n"; }
    ~Widget() { std::cout << "dtor\n"; }
};

int main() {
    std::cout << "start\n";
    {
        Widget a;                 // where does this live?
        Widget* p = new Widget;   // where does this live?
        std::cout << "inside\n";
        delete p;
    }                             // what happens here?
    std::cout << "end\n";
}