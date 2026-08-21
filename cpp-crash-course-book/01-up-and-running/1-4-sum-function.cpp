// Write another function called sum that takes two int arguments and returns their sum.
// How can you modify the template to test your new function?


#include <cstdio>

int absolute_value(int x) {
    if (x >= 0) {
        return x;
    }
    else {
        return x * -1; 
    }
}

int sum(int z, int y) {
    return z + y;
}

int main () {
    int result = sum(2, -54);
    printf("The absolute value of %d is %d.\n", result, absolute_value(result));
}