// Write a function: int max_off(int a, int b)
// It returns the larger of the two values.
// If they're equal return either.

#include <iostream>

int max_of(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main () {
    std::cout << max_of(120, 30) << "\n";
    return 0;
}