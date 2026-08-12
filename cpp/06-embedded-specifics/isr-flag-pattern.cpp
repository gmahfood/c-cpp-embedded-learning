// =============================================================
//  isr-flag-pattern.cpp
//  Demonstrates: the standard ISR pattern. The interrupt does the
//  minimum (set a flag, get out); the main loop does the real work.
//
//  Why: an ISR freezes the whole system while it runs, and other
//  interrupts wait behind it (interrupt latency). So keep it short.
//  processData() might be slow, so it does NOT belong in the ISR.
//  The ISR just signals "this happened"; main handles "what to do."
//
//  dataReady is volatile because the ISR writes it and the main loop
//  reads it — shared between two contexts, so reads must be fresh.
//  A single bool is one byte, so it can't be torn; larger shared data
//  would need interrupts briefly disabled around access (atomicity).
// =============================================================

// Shared between ISR and main loop -> must be volatile.
volatile bool dataReady = false;

// The ISR: runs when the hardware event fires. Does one thing, fast.
void onDataReceived() {
    dataReady = true;   // raise the flag and return immediately
}

// Main loop: notices the flag, clears it, does the real (slow) work here.
void loop() {
    if (dataReady) {
        dataReady = false;   // clear before handling
        // processData();    // the actual work happens safely in main context
    }
}