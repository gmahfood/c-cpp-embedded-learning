# C/C++ Embedded Systems Learning Journey 🔧

> Learning C/C++ from the ground up with embedded systems as the goal — following K&R, Jacob Sorber, and building toward bare-metal development.

---

## 👋 About This Repo

This is my personal learning repository documenting my journey from little C knowledge to embedded systems development. I'm working toward writing firmware, understanding microcontrollers at the bare-metal level, and eventually developing real embedded projects.

---

## 🗺️ Roadmap

### Phase 1 — C Fundamentals *(current)*
- [x] Variables, data types, operators
- [x] Control flow (if, loops, switch)
- [x] Printf format specifiers and float precision
- [x] Character input, getchar(), EOF, and data type sizing
- [x] If statements, character comparison, newline detection
- [ ] Functions and scope
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
c-embedded-learning/
├── basics/          # Variables, loops, functions, control flow
├── pointers/        # Pointers, arrays, memory management
├── structs/         # Structs, enums, unions
├── files/           # File I/O
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

---

## 📝 Notes

- All code written and tested on **macOS (Apple Silicon)**
- Starting from **zero C knowledge**
- Goal: bare-metal embedded firmware development

---

*Learning in public. Mistakes will be made. That's the point.*