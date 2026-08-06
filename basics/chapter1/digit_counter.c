/*
 * digit_counter.c
 *
 * Counts occurrences of digits, whitespace, and other characters.
 * This introduces one of the most fundamental concepts in C: ARRAYS.
 *
 * In embedded systems, arrays are everywhere:
 *   - Buffers for storing incoming UART data
 *   - Lookup tables for sensor calibration values
 *   - PWM duty cycle tables for motor control
 * Understanding how arrays work in memory is critical for embedded work.
 */

 #include <stdio.h>

 int main() {

    int c;
    int i;
    int nwhite;     // whitespace counter
    int nother;     // other characters counter

    /* An array of 10 integers, one slot for each digit 0-9.
     * In memory this is 10 consecutive integers laid out in a row.
     * ndigit[0] counts zeros, ndigit[1] counts ones, and so on.
     *
     * IMPORTANT: In C, arrays are NOT initialized to zero automatically
     * unless they are global or static. Always initialize your arrays
     * explicitly. In embedded, uninitialized memory can contain
     * anything and cause very hard to find bugs. */
    int ndigit[10];

    nwhite = nother = 0;        /* Initialize every slot in the array to 0.
                                 * This is the standard C pattern for initializing an array. */

    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {

        /* '0' is the ASCII value of the character zero (48).
         * So c - '0' gives us the numeric value of whichever digit we read.
         * '0' - '0' = 0, '1' - '0' = 1, '9' - '0' = 9.
         * This maps directly to our array index with no if/else chain needed.
         *
         * In embedded this kind of ASCII arithmetic is used constantly
         * when parsing serial commands and converting sensor readings. */

        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    // Print each digit and its count
    printf("Digits:\n");
    for (i = 0; i < 10; ++i)
        printf("  %d: %d\n", i, ndigit[i]);

    printf("WHitespace: %d\n", nwhite);
    printf("Other: %d\n", nother);

    return 0;
}

/*
 * COMPILE AND RUN:
 *   clang digit_counter.c -o digit_counter && ./digit_counter
 *
 * THINGS TO TRY:
 *   1. Type "hello 123 world 456" and hit Ctrl+D
 *      should show 1,2,3,4,5,6 each appearing once
 *   2. Type "1111" and should show digit 1 appearing 4 times
 *   3. Think about what ndigit[c - '0'] is actually doing in memory.
 *      You are using a character's ASCII value as an array index,
 *      which is pointer arithmetic in disguise.
 */