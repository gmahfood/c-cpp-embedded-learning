/*
 * word_counter.c
 *
 * Counts lines, words, and characters from user input.
 * This is the most complete example in K&R chapter 1.
 * It brings together everything so far into one program.
 * 
 * Key concept introduced: STATE
 * The program needs to remember whether it's currently 
 * inside a word or outside a word; that's state.
 * State machines are absolutely fundamental in embedded systems.
 * Every protocol parser, button debouncer, and communication
 * handler you'll ever write uses this exact concept.
 */

 #include <stdio.h>

 #define IN  1      // inside a word
 #define OUT 0      // outside a word

 /* define creates a constant, a name that gets replaced
  * by its value at compile time. No memory is used. 
  * In embedded C, #define constants are preferred over variables for fixed 
  * values to save the short supplied RAM of most PCBs */

int main () {
    
    int c;          // current character
    int state;      // are we IN or OUT of a word?
    long nl;        // line count
    long nw;        // word count
    long nc;        // character count

    state = OUT;
    nl = nw = nc = 0;   // multiple assignment, valid in C similarly to C++

    while ((c = getchar()) != EOF) {
        ++nc;       // count every character

        if (c == '\n')
            ++nl;   // count new lines

        /* A word boundary is where we transition from whitespace (OUT)
         * to a non-whitespace character (IN). 
         * \t is a tab, \n is newline, ' ' is space - these are the 
         * three whitespace characters we check for. */
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;   // We just entered a new word.
        }

    }

    printf("Lines: %ld Words: %ld Characters: %ld\n", nl, nw, nc);

    return 0;
}

/*
 * COMPILE AND RUN:
 *   clang word_counter.c -o word_counter && ./word_counter
 *
 * HOW TO USE IT:
 *   - Type a few sentences and press Ctrl+D
 *   - The program prints lines, words, and characters
 *
 * THINGS TO TRY:
 *   1. Type "hello world" — should give 0 lines, 2 words, 12 characters
 *   2. Type multiple lines and verify the counts
 *   3. Try typing with extra spaces between words — does the word count change?
 *      It shouldn't — that's the beauty of the state machine approach.
 *
 * EMBEDDED CONNECTION:
 *   This IN/OUT state machine is the same pattern used to parse
 *   serial commands on a microcontroller. For example, detecting
 *   when a UART message starts and ends uses this exact logic.
 */