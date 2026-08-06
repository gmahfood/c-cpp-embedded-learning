/*
 * line_counter.c
 *
 * Counts the number of lines entered by the user.
 * Builds on char_counter.c — same getchar/EOF pattern,
 * but now we inspect each character and react to it.
 *
 * This is the foundation of parsing in C — reading a stream
 * of bytes and making decisions based on what you see.
 * In embedded, this is exactly how you parse UART commands
 * coming in from a serial terminal or another device.
 */

#include <stdio.h>

int main() {

    int c;      /* c holds the current character being read.
                 * We use int, not char, same reason as before,
                 * EOF (-1) won't fit in a char on all platforms. */
    long nl;    /* nl = number of lines */
    nl = 0;

    while ((c = getchar()) != EOF) {

        /* '\n' is the newline character; every time you press Enter,
         * getchar() sees this character.
         * Single quotes are for characters, double quotes are for strings.
         * 'A' is a char (1 byte). "A" is a string (2 bytes — char + null terminator).
         * This distinction matters a lot in C and embedded. */
        if (c == '\n')
            ++nl;
    }

    printf("Line count: %ld\n", nl);

    return 0;
}

/*
 * COMPILE AND RUN:
 *   clang line_counter.c -o line_counter && ./line_counter
 *
 * HOW TO USE IT:
 *   - Type several lines of text, pressing Enter after each
 *   - Press Ctrl+D to send EOF
 *   - The program prints how many lines you typed
 *
 * THINGS TO TRY:
 *   1. Type 3 lines and verify you get 3
 *   2. Press Enter a few times without typing — blank lines count too
 *   3. Think about how you'd modify this to count words instead of lines
 *      — that's the next example in K&R!
 */