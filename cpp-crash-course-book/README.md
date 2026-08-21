# cpp-crash-course-book

Drills worked through *C++ Crash Course* (Josh Lospinoso), one `.cpp` file
per exercise, grouped by chapter folder. Compiled binaries sit next to
their source (gitignored — see `.vscode/tasks.json` for the build task
that produces them).

## Structure

- `01-up-and-running/` — Chapter 1 drills: functions, control flow, the
  compile/run loop
- `02-types/` — Chapter 2 drills (in progress)

## Progress log

### 01 — Up and running

- `1-1-absolute-value.cpp` — `absolute_value(int)` returns `x` if `x >= 0`,
  otherwise `x * -1`.
- `1-4-sum-function.cpp` — adds a `sum(int, int)` function alongside
  `absolute_value` and wires both into `main` to test the new function.

### 02 — Types

- `2-1-enum.cpp` — `enum Operation` with `Add`, `Subtract`, `Multiply`,
  `Divide` values.
