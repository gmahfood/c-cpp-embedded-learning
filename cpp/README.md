# embedded-learning

Personal drills for building embedded C and C++ fundamentals, worked by hand
with no AI assistance. Each file demonstrates one concept and carries a header
comment explaining what it proves.

## Structure

- `basics/` — C fundamentals (K&R exercises)
- `cpp-fundamentals/` — C++ concepts, one topic per numbered folder

## Progress log

### C++ fundamentals

**01 — Memory model**
- `stack-vs-heap-lifetime.cpp` — stack objects destroy at scope exit; heap
  objects only on delete. Construction always precedes destruction.

**02 — Constructors and destructors**
- `ctor-dtor-order.cpp` — forward construction, reverse destruction (stack is LIFO).
- `three-constructor-types.cpp` — default, parameterized, copy. `Widget c = b;`
  is construction (copy constructor), not assignment.

**03 — RAII**
- `raii-scope-guard.cpp` — resource released automatically on scope exit,
  including early return, with no manual cleanup call.
- `raii-heap-ownership.cpp` — RAII guarding real heap memory; the early return
  that leaks with a raw pointer is leak-proof when an object owns the memory.

  **04 — Pointers, references, const**
- Pointer basics: `*p` reads/writes the value at an address; `p = &y`
  re-aims the pointer. Star vs no-star is the whole distinction.
- References as aliases: bound once, never re-seated, never null.
- const with pointers: `const int*` locks the value, `int* const` locks
  the pointer. Read right to left.

  **05 — Polymorphism and vtables**
- `virtual-dispatch.cpp` — base pointer calls the actual object's method,
  resolved at runtime via the vtable. Remove `virtual` and the base version
  runs instead. Chain: object → vptr → vtable → function.

  **06 — Embedded specifics**
- `bit-manipulation.cpp` — set/clear/toggle/test a single bit with masks.
  `(1 << n)` builds the mask; OR sets, AND-NOT clears, XOR toggles, AND tests.
- `volatile-register-wait.cpp` — memory-mapped register access; why a wait
  loop hangs forever without `volatile`. Freshness, not thread-safety.
- `isr-flag-pattern.cpp` — ISR sets a flag, main loop does the real work.
  Shared flag is `volatile`. Keep ISRs short to minimize interrupt latency.

**07 — Cold-handwritten drills**
- `add.cpp`, `max_of.cpp`, `is_even.cpp` — cold-generation reps, written
  by hand with no AI. Focus: return statements, brace matching, `==` vs `=`.