// Demonstrates: virtual dispatch. A base pointer (Animal*) calls the actual
// object's version (Dog/Cat), decided at RUNTIME via the vtable, not the
// pointer's declared type. Remove 'virtual' and it prints the base version
// twice. Chain: object -> vptr -> vtable -> function.

#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "some sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Meow\n";
    }
};

int main() {
    Dog d;
    Cat c;

    Animal* a = &d;    // base pointer aimed at a Dog
    a->speak();        // call 1

    a = &c;            // now aimed at a Cat
    a->speak();        // call 2
}