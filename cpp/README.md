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