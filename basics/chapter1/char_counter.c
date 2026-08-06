/*
 * char_counter.c
 *
 * This program counts the number of characters entered by the user.
 * It introduces two huge concepts in C:
 *   1. getchar() / putchar() - the most basic form of I/O in C
 *   2. EOF - End Of File, a signal that input has ended
 *
 * In embedded systems, you'll often read data one byte at a time
 * from a UART serial buffer, this is exactly that pattern.
 */

#include <stdio.h>

int main() 
{
    /* We use a long to count characters, it can hold a larger number than int.
     * In C, long is guaranteed to be at least 32 bits.
     * On most modern systems it's 64 bits.
     * In embedded, always think about the size of your types, memory is tight. */
    long nc;
    nc = 0;

    /* getchar() reads one character at a time from standard input.
     * EOF is a special constant (usually -1) that signals end of input.
     * Notice getchar() returns an int, not a char, this is intentional,
     * because EOF (-1) cannot fit in a char on some platforms. */
    while (getchar() != EOF)
    {
        ++nc;   // ++ is the increment operator (same as in C++), ++nc = nc + 1
    }

    /* %ld is the format specifier for a long integer.
     * Always match your format specifier to your data type 
     * a mismatch is undefined behavior in C, a common source of bugs. */
    printf("Character count: %ld\n", nc);

    return 0;
}

/*
 * COMPILE AND RUN:
 *   clang char_counter.c -o char_counter && ./char_counter
 *
 * HOW TO USE IT:
 *   - After running, type some text and press Enter
 *   - To send EOF on Mac, press Ctrl+D
 *   - The program will print how many characters you typed
 *
 * THINGS TO TRY:
 *   1. Type "hello" and press Ctrl+D, should count 5 characters
 *   2. Press Enter a few times, newlines count as characters too!
 *   3. Try changing long to int and %ld to %d — still works,
 *      but now you're limited to ~2 billion characters max
 */

