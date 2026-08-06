/*
 * temp_conversion_float.c
 *
 * An improved version of the temperature conversion table.
 * This time using floating point numbers for more precise results.
 *
 * Key concept: the difference between int and float arithmetic in C
 * is something you'll deal with constantly in embedded systems,
 * especially when working with ADC readings, sensor data, and unit conversions.
 */

#include <stdio.h>

int main() 
{
   /* float is a 32-bit floating point number.
    * In embedded systems, float is common but be careful,
    * some microcontrollers lack an FPU (Floating Point Unit)
    * meaning float math is done in software and is much slower.
    * Always check your target hardware before using float heavily. */
   float fahr, celcius;
   float lower, upper, step;

   lower = 0.0;
   upper = 300.0;
   step = 20.0;

   fahr = lower;

   while (fahr <= upper)
   {
        /* Now we can write the formula naturally without the integer division trick.
         * 5.0/9.0 produces a float result — no truncation, no gotcha. */
        celcius = (5.0 / 9.0) * (fahr - 32.0);

         /* %3.0f — print a float with 3 characters wide, 0 decimal places
         * %6.1f — print a float with 6 characters wide, 1 decimal place
         *
         * These width and precision specifiers are extremely useful in embedded
         * for formatting clean debug output over UART serial. */
        printf("%3.0f\t%6.1f\n", fahr, celcius);

        fahr = fahr + step;
   }

   return 0;
}

/*
 * COMPILE AND RUN:
 *   clang temp_conversion_float.c -o temp_conversion_float && ./temp_conversion_float
 *
 * EXPECTED OUTPUT:
 *   0      -17.8
 *   20      -6.7
 *   40       4.4
 *   ...
 *
 * NOTICE: The output is now right-aligned and more precise than the integer version.
 * That's the power of format specifiers — clean, readable debug output.
 *
 * THINGS TO TRY:
 *   1. Change %6.1f to %6.2f for 2 decimal places
 *   2. Change %6.1f to %6.4f for 4 decimal places
 *   3. Try declaring fahr as int and celsius as float — what breaks?
 *      This teaches you implicit type conversion in C.
 */