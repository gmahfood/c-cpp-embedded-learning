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