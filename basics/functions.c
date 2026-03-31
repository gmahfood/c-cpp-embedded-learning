/*
 * functions.c
 *
 * Introduces functions in C — how to define them, declare them,
 * and pass data in and out.
 *
 * In embedded systems, almost everything lives in a function:
 *   - GPIO_Init()
 *   - UART_Read()
 *   - ADC_GetValue()
 * Writing clean, focused functions is one of the most important
 * skills you can build as an embedded developer.
 */

#include <stdio.h>

/* FUNCTION DECLARATION (also called a prototype)
 * This tells the compiler the function exists before we define it below.
 * In C, if you call a function before defining it without a prototype,
 * the compiler will complain. In embedded codebases you will see
 * prototypes at the top of every .c file or in a header (.h) file. */
int power(int base, int n);

int main() {

    int i;

     /* Call the power function and print results.
     * Notice we pass values in and get a value back.
     * The function does one job and returns the result. */
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));

    return 0;
}

/* FUNCTION DEFINITION
 * int power(int base, int n) means:
 *   - the function returns an int
 *   - it takes two int parameters: base and n
 *   - base and n are LOCAL to this function, changes here
 *     do not affect anything outside
 *
 * In embedded, keeping functions focused and self-contained
 * like this makes code easier to test and debug on hardware. */
int power(int base, int n) {

    int i;
    int p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;

    return p;
}

/*
 * COMPILE AND RUN:
 *   clang functions.c -o functions && ./functions
 *
 * EXPECTED OUTPUT:
 *   0  1  1
 *   1  2  -3
 *   2  4  9
 *   3  8  -27
 *   ...
 *
 * THINGS TO TRY:
 *   1. Try calling power(2, 0) — what do you expect? Why?
 *   2. Remove the prototype at the top and see what the compiler says
 *   3. Try writing your own function that adds two numbers and returns the result
 */