/*
 * external_variables.c
 *
 * Demonstrates external (global) variables and scope in C.
 * External variables are defined outside of any function and
 * are accessible by any function in the program.
 *
 * In embedded systems, global variables are used constantly for:
 *   - Shared state between interrupt handlers and main code
 *   - Hardware register mappings
 *   - System-wide flags and counters
 *
 * That said, globals should be used carefully. Overusing them
 * makes code hard to debug and maintain.
 */

#include <stdio.h>

#define MAXLINE 1000

/* These are EXTERNAL variables — defined outside any function.
 * They are automatically initialized to zero.
 * Any function in this file can read and write them directly.
 * In embedded you will see this pattern for interrupt flags:
 *   volatile int uart_data_ready = 0;
 * The volatile keyword tells the compiler not to optimize
 * away reads/writes — critical when hardware can change the value. */
int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main() {

    int len;
    extern int max;           /* declaring we use the external max */
    extern char longest[];    /* declaring we use the external longest */

    max = 0;

    while ((len = get_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }

    if (max > 0)
        printf("Longest line (%d chars): %s", max, longest);

    return 0;
}

/* Notice get_line and copy no longer need parameters.
 * They read and write the external variables directly.
 * This is convenient but comes at a cost — these functions
 * are now tightly coupled to those globals. They cannot be
 * reused in another program without bringing the globals along. */
int get_line(void) {

    int c;
    int i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy(void) {

    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}

/*
 * COMPILE AND RUN:
 *   clang external_variables.c -o external_variables && ./external_variables
 *
 * THINGS TO TRY:
 *   1. Type a few lines and verify the longest is printed
 *   2. Compare this to char_arrays.c — same program, different approach
 *   3. Notice how removing parameters makes the functions less reusable
 *      that tradeoff is worth understanding before using globals in embedded
 */