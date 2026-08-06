/*
 * call_by_value.c
 *
 * Demonstrates how C passes arguments to functions by VALUE.
 * This means the function gets its own COPY of the variable.
 * Changes inside the function do not affect the original.
 *
 * This is critical to understand before learning pointers.
 * In embedded, misunderstanding this leads to bugs where you
 * think you modified a sensor reading or buffer but you did not.
 */

#include <stdio.h>

/* A cleaner version of the power function from last time.
 * Notice we use n itself as a local counter instead of a separate i.
 * Because n is a COPY, we can modify it freely without affecting
 * whatever variable was passed in by the caller. */
int power(int base, int n);

int main() {

    int base;
    int exp;
    int result;

    base   = 2;
    exp    = 8;
    result = power(base, exp);

    /* Even though power() modifies n internally, exp is unchanged here.
     * That is call by value in action. The function worked on a copy. */
    printf("base: %d\n", base);
    printf("exponent: %d\n", exp);
    printf("result: %d\n", result);

    return 0;
}

int power(int base, int n) {

    int p;

    /* We use n as our loop counter directly.
     * This is safe because n is a local copy of whatever was passed in.
     * Modifying n here has zero effect on the caller's variable.
     *
     * Coming from C++, this is the same default behavior.
     * The difference is that in C, to modify the original you MUST
     * use pointers. In C++ you can use references. C has no references.
     * Pointers are coming up next and this is exactly why they exist. */
    for (p = 1; n > 0; --n)
        p = p * base;

    return p;
}

/*
 * COMPILE AND RUN:
 *   clang call_by_value.c -o call_by_value && ./call_by_value
 *
 * EXPECTED OUTPUT:
 *   base: 2
 *   exponent: 8
 *   result: 256
 *
 * THINGS TO TRY:
 *   1. Add a printf inside power() that prints n as it counts down
 *      then verify exp is still 8 back in main after the call
 *   2. Think about this: if you wanted power() to modify exp directly,
 *      how would you do it? You would need a pointer. That is next.
 */