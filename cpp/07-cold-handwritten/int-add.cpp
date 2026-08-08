#include <iostream>

int add(int a, int b) {
    return a + b;          // compute and hand back the sum
}                          // add closes here

int main() {
    std::cout << add(2, 3) << "\n";   // call it, print the result
    return 0;              // optional, but explicit is fine
}