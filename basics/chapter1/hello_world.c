/*
 * HelloWorld.c
 *
 * My first C program.
 * If you're coming from C++, C will feel familiar but more raw.
 * There's no standard library magic here, what you see is what you get.
 * That rawness is exactly what makes C the language of embedded systems.
 */

#include <stdio.h>   /* stdio.h is C's standard I/O library.
                      * Unlike C++, there's no <iostream> here.
                      * printf() lives here — it's one of the most
                      * widely used functions in all of systems programming. */

/* In C, program execution always starts at main().
 * It returns an int — this is the exit code sent back to the OS.
 * 0 means success. Anything else signals an error.
 * In embedded systems, main() often runs an infinite loop and never returns. */

int main() {

    /* printf() — "print formatted"
     * The \n is an escape sequence for a newline character.
     * Unlike C++ std::cout, printf uses format specifiers like %d, %f, %s
     * to insert variables into strings — you'll use these constantly. */
    printf("Hello, World!\n");

    /* return 0 tells the OS the program ran successfully.
     * In bare-metal embedded code, you rarely return from main —
     * instead you'll see: for(;;) {} or while(1) {} to loop forever,
     * keeping the microcontroller alive and running. */
    return 0;
}

/*
 * HOW TO COMPILE AND RUN THIS FILE:
 *
 *   clang HelloWorld.c -o HelloWorld && ./HelloWorld
 *
 * What that command does:
 *   clang          — the C compiler (installed via Xcode CLI tools)
 *   HelloWorld.c   — your source file
 *   -o HelloWorld  — name the output binary "HelloWorld"
 *   &&             — if compile succeeds, then...
 *   ./HelloWorld   — run the binary
 *
 * Expected output:
 *   Hello, World!
 *
 * WHAT TO TRY NEXT:
 *   1. Change the message inside printf() and recompile
 *   2. Add a second printf() line below the first
 *   3. Try removing the \n and see what changes in the output
 *   4. Try returning 1 instead of 0 — the program still runs,
 *      but signals a failure exit code to the OS
 */
