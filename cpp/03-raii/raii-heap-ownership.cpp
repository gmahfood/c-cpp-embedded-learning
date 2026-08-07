// Demonstrates: RAII guarding real heap memory. Same early return that leaked
// with a raw pointer (Day 1) is leak-proof here, because the object's
// destructor frees the buffer automatically on every exit path.

#include <iostream>

class IntArray {
    int* data;      // holds the address of heap memory
    int  size;
public:
    IntArray(int n) : size(n) {
        data = new int[n];              // ACQUIRE: grab heap memory
        std::cout << "allocated " << n << " ints\n";
    }
    ~IntArray() {
        delete[] data;                  // RELEASE: free that memory
        std::cout << "freed\n";
    }
    void set(int i, int value) {
        data[i] = value;                // write into the buffer
    }
    int get(int i) {
        return data[i];                 // read from the buffer
    }
};

void useArray(bool fail) {
    IntArray arr(5);        // heap memory acquired here
    arr.set(0, 42);
    if (fail) {
        std::cout << "bailing early\n";
        return;             // no manual cleanup... but watch
    }
    std::cout << "value at 0: " << arr.get(0) << "\n";
}

int main() {
    std::cout << "-- normal --\n";
    useArray(false);
    std::cout << "-- fail --\n";
    useArray(true);
}