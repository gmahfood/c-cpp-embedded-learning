# C/C++ Embedded Systems Learning Journey 🔧

> Intermediate C++ developer focusing on C and embedded systems — learning bare-metal development with K&R, Jacob Sorber, and real hardware.

---

## 👋 About This Repo

This is my personal learning repository documenting my journey through C and embedded systems development. I have an intermediate C++ background and am now focusing on mastering C and writing real firmware — understanding microcontrollers at the bare-metal level and building toward production-ready embedded projects.

---

## 🗺️ Roadmap

### Phase 1 — C Fundamentals *(current)*
- [x] Variables, data types, operators
- [x] Control flow (if, loops, switch)
- [x] Printf format specifiers and float precision
- [x] Character input, getchar(), EOF, and data type sizing
- [x] If statements, character comparison, newline detection
- [x] State machines, #define constants, word/line/character parsing
- [x] Arrays, for loops, ASCII arithmetic, array initialization
- [x] Functions, prototypes, return values, local scope
- [ ] Arguments and call by value
- [ ] Arrays and strings
- [ ] Pointers and memory
- [ ] Structs, enums, unions
- [ ] File I/O
- [ ] Bitwise operations

### Phase 2 — C++ for Embedded
- [ ] Classes and objects
- [ ] RAII and resource management
- [ ] Templates (basics)
- [ ] What to avoid in embedded C++ (exceptions, dynamic allocation)

### Phase 3 — Microcontroller Fundamentals
- [ ] GPIO
- [ ] Timers and interrupts
- [ ] UART / SPI / I2C communication
- [ ] ADC / DAC
- [ ] First project on STM32 Nucleo

### Phase 4 — RTOS & Systems Concepts
- [ ] FreeRTOS basics (tasks, queues, semaphores)
- [ ] Memory-mapped I/O
- [ ] Linker scripts
- [ ] Bootloaders

### Phase 5 — Real Projects
- [ ] Sensor data logger
- [ ] Motor controller
- [ ] Custom bootloader

---

## 📁 Repo Structure

```
c-cpp-embedded-learning/
├── basics/          # C fundamentals — pointers, memory, bitwise
├── pointers/        # Deep dives into pointer mechanics
├── structs/         # Structs, enums, unions
├── files/           # File I/O
├── cpp/             # Embedded C++ examples
└── projects/        # Small complete programs
```

---

## 🛠️ Tools & Setup

| Tool | Purpose |
|------|---------|
| VS Code | Editor |
| PlatformIO | Embedded dev environment |
| Clang (Xcode CLI Tools) | C/C++ compiler |
| GDB + OpenOCD | Debugging |
| STM32 Nucleo | Target hardware (Phase 3+) |

**macOS setup:**
```bash
xcode-select --install   # installs clang
```

**Compile and run a file:**
```bash
clang filename.c -o filename && ./filename
```

---

## 📚 Resources

**Books**
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) — Kernighan & Ritchie (K&R)

**YouTube**
- [Jacob Sorber](https://www.youtube.com/@JacobSorber) — Best free embedded C content
- [Low Level Learning](https://www.youtube.com/@LowLevelLearning) — C internals and systems thinking
- [Phil's Lab](https://www.youtube.com/@PhilsLab) — STM32 and DSP

**Websites**
- [cppreference.com](https://cppreference.com) — C/C++ language reference
- [Interrupt Blog](https://interrupt.memfault.com) — Advanced embedded topics
- [FreeRTOS.org](https://freertos.org) — RTOS documentation

**Courses**
- [Intro to Embedded Systems — Coursera (CU Boulder)](https://www.coursera.org/learn/introduction-embedded-systems) — Free to audit

---

## 📈 Progress Log

| Date | Milestone |
|------|-----------|
| 2026-03-17 | Repo created, Hello World running |
| 2026-03-17 | Temperature conversion table — K&R Chapter 1 (variables, while loop, printf format specifiers, integer division) |
| 2026-03-17 | Float temperature conversion — K&R Chapter 1 (float vs int, FPU awareness, printf width and precision specifiers) |
| 2026-03-18 | Character counter — K&R Chapter 1 (getchar, EOF, long vs int, byte-by-byte input reading) |
| 2026-03-19 | Line counter — K&R Chapter 1 (if statements, character comparison, char vs int, newline detection) |
| 2026-03-19 | Learned how Git commits and contributions work — committing files separately for granular history |
| 2026-03-23 | Word counter — K&R Chapter 1 (state machines, #define constants, multi-counter input parsing) |
| 2026-03-29 | Renamed repo to c-cpp-embedded-learning, added cpp/ folder, updated README to reflect C++ background |
| 2026-03-29 | Digit counter — K&R Chapter 1 (arrays, for loops, ASCII arithmetic, array initialization) |
| 2026-03-30 | Functions example — K&R Chapter 1 (function definitions, prototypes, return values, local scope) |

---

## 📝 Notes

- All code written and tested on **macOS (Apple Silicon)**
- Intermediate C++ background — focused on C and embedded fundamentals
- Goal: bare-metal embedded firmware development

---

*Learning in public. Mistakes will be made. That's the point.*