// =============================================================
//  volatile-register-wait.cpp
//  Demonstrates: why memory-mapped register access needs volatile.
//
//  volatile means: "never cache this, read it fresh from memory on
//  every access, because something outside my code (hardware, an ISR)
//  can change it."
//
//  The * appears in two roles (same rule as pointers):
//    - in a declaration  (volatile uint8_t*)  -> "this is a pointer"
//    - in an expression  (*reg)               -> "read the value there"
//
//  IMPORTANT: volatile guarantees FRESHNESS, not thread-safety.
//  It does NOT make access atomic. A multi-byte read can still be
//  torn by an interrupt firing mid-read.
// =============================================================

#include <cstdint>

// A pointer to a volatile 8-bit hardware register at a fixed address.
// The address comes from the chip datasheet / vendor headers, not guesswork.
// (0x40000000 is just an example address here.)
volatile uint8_t* STATUS_REGISTER = (volatile uint8_t*)0x40000000;

// Wait until the hardware sets the register nonzero, then return.
// The empty loop body is intentional: the "work" is re-reading *reg.
//
// Without volatile, the compiler sees nothing in this loop changing
// *reg, assumes it can't change, reads it once, and loops forever
// even after the hardware makes it nonzero. volatile forces a fresh
// read every pass, so the loop exits when the hardware is ready.
void waitForReady(volatile uint8_t* reg) {
    while (*reg == 0) {
        // spin: re-read *reg each pass until hardware sets it nonzero
    }
    return;
}