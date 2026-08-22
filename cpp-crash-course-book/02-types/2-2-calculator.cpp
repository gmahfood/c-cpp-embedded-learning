// Create a struct Calculator. It should have a single constructor that takes an operation.
// Then create a method on Calculator called int calculate(int a, int b). Upon invocation, 
// this method should perform addition, subtraction, multiplication, or division based on
// its constructor argument and return the result.


#include <cstdio>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide,
};

struct Calculator {
    Operation op;

    // Constructor that takes enum operation
    Calculator(Operation _op) {
        op = _op;
    }

    // Methods
    int calculate(int x, int y) {
        switch (op) {
            case Operation::Add: return x + y;
            case Operation::Subtract: return x - y;
            case Operation::Multiply: return x * y;
            case Operation::Divide: 
                if (y == 0) {
                    printf("Error: cannot divide by 0!\n");
                    return 0;
                }
                else {
                    return x / y;
                }
                
        };
    };
};