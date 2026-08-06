/* 
 * temp_conversion.c
 *
 * Our first real C program; A Fahrenheit to Celcius conversion table.
 * This introduces variables, data types, and printf format specifiers.
 * Coming from C++, notice there's no cout, no std:: - just printf and math.
 */

#include <stdio.h>

/* Print Fahrenheit - Celcius table
    for fahr = 0, 20, ..., 300 */

int main()
{
    /* In C, ALL variabless must be declared at the top of the function.
     * This is strict C80/C90 style, the kind seen in embedded codebases.
     * Unlike C++, you cannot declare a variable in the middle of a function. */
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;      // lower limit of temperature table
    upper = 300;    // upper limit
    step = 20;      // step size

    fahr = lower;

    // A basic while loop - identical to C++. Notice no std::endl, just \n in printf.
    while (fahr <= upper)
    {
        /* Celsius = (5/9) * (Fahrenheit - 32)
         *
         * IMPORTANT: In C, 5/9 using integers = 0 (integer division truncates).
         * This is a classic C gotcha. We write 5 * (fahr - 32) / 9 instead
         * to avoid losing the result. This kind of thinking is critical
         * in embedded where precision and data types really matter. */
        celcius = 5 * (fahr - 32) / 9;

        /* %d is the format specifier for integers.
         * \t is a tab character — used here for alignment.
         * You'll use printf format specifiers constantly in embedded
         * for debugging over UART serial output. */
        printf("%d\t%d\n", fahr, celcius);

        fahr = fahr + step;
    }

    return 0;
}

/*
 * COMPILE AND RUN:
 *   clang temp_conversion.c -o temp_conversion && ./temp_conversion
 *
 * EXPECTED OUTPUT:
 *   0      -17
 *   20     -6
 *   40     4
 *   ...
 *
 * THINGS TO TRY:
 *   1. Change step to 10 and see more rows
 *   2. Change upper to 500
 *   3. Try writing 5/9 * (fahr-32) instead and see what breaks
 *      — this will teach you integer division the hard way
 */