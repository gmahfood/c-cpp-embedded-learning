/*
 * char_arrays.c
 *
 * Introduces character arrays — how strings work in C.
 * In C there is no string type. A string is just an array
 * of chars with a null terminator '\0' at the end.
 *
 * In embedded this matters a lot. When your microcontroller
 * receives a command over UART, it arrives as a raw array
 * of bytes. Knowing how to read, store, and process that
 * array is fundamental to embedded communication.
 */

 #include <stdio.h>

 #define MAXLINE 1000       // maximum input line length

 // Function prototypes
 int get_line(char line[], int maxline);
 void copy(char to[], char from[]);

 int main() {

    int  len;               // current line length 
    int  max;               // maximum length seen so far 
    char line[MAXLINE];     // current input line 
    char longest[MAXLINE];  // longest line saved here 

    max = 0;

    // Read lines until EOF, keep track of the longest one
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    // Print the longest line if there was any input 
    if (max > 0)
        printf("Longest line (%d chars): %s", max, longest);

    return 0;
}

/* get_line reads a line into the array s and returns its length.
 * Notice the array is passed by reference automatically in C.
 * Arrays are ALWAYS passed as pointers — this is your first
 * hint at how pointers and arrays are deeply connected in C. */
int get_line(char s[], int lim) {

    int c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;   /* store the newline */
        ++i;
    }

    /* The null terminator '\0' marks the end of the string.
     * Every C string ends with this character.
     * Without it, printf and other functions would keep reading
     * memory past the end of your array — a classic embedded bug
     * that can corrupt memory or crash your system. */
    s[i] = '\0';

    return i;
}

/* copy copies the string from[] into to[].
 * It relies on the null terminator to know when to stop.
 * Notice no length is needed — the '\0' is the sentinel. */
void copy(char to[], char from[]) {

    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/*
 * COMPILE AND RUN:
 *   clang char_arrays.c -o char_arrays && ./char_arrays
 *
 * HOW TO USE IT:
 *   Type several lines of different lengths and hit Ctrl+D.
 *   The program prints the longest line you typed.
 *
 * THINGS TO TRY:
 *   1. Type a few lines of varying length and verify the right one prints
 *   2. Think about what happens if you forget the '\0' at the end
 *   3. Notice copy() stops at '\0' with no length needed; that is
 *      the entire reason null terminators exist in C strings
 */