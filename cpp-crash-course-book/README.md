# cpp-crash-course-book

Drills worked through *C++ Crash Course* (Josh Lospinoso), one exercise per
numbered folder. Each folder holds the drill's source next to the binary it
compiles to (binary is gitignored — see `.vscode/tasks.json` for the build
task that produces it).

## Structure

- `01-up-and-running/` — Chapter 1 drills: functions, control flow, the
  compile/run loop
- `02-types/` — Chapter 2 drills (in progress)

## Progress log

### 01 — Up and running

- `1-1-absolute-value/` — `absolute_value(int)` returns `x` if `x >= 0`,
  otherwise `x * -1`.
- `1-4-sum-function/` — adds a `sum(int, int)` function alongside
  `absolute_value` and wires both into `main` to test the new function.
