// =============================================================
//  bit-manipulation.cpp
//  Demonstrates: set / clear / toggle / test a single bit without
//  disturbing the others. Built from one tool: the mask (1 << n),
//  which is all zeros except a single 1 at position n.
//
//  Panel answer: "I build a mask with (1 << n), then OR to set,
//  AND with the inverted mask to clear, XOR to toggle, AND to test.
//  OR/XOR with 0 is a no-op, so the other bits are never touched."
//
//  Modifiers take the value by reference (&) so the change sticks
//  in the caller's variable. test_bit takes by value: it only reads.
// =============================================================

#include <cstdint>

// Set bit n to 1. OR forces the target bit high, leaves the rest alone.
void set_bit(uint8_t& x, uint8_t n) {
    x |= (1 << n);
}

// Clear bit n to 0. ~(1 << n) is all 1s except a 0 at n;
// AND forces only that bit to 0, everything else survives.
void clear_bit(uint8_t& x, uint8_t n) {
    x &= ~(1 << n);
}

// Flip bit n. XOR with 1 flips a bit, XOR with 0 leaves it.
void toggle_bit(uint8_t& x, uint8_t n) {
    x ^= (1 << n);
}

// Return true if bit n is set. AND isolates the bit; nonzero means it was 1.
// != 0 makes the result an explicit bool.
bool test_bit(uint8_t x, uint8_t n) {
    return (x & (1 << n)) != 0;
}

// Note: setting bit n gives value 2^n, not n.
// set_bit(flags, 3) turns 0 into 8, because bit 3 is worth 8.