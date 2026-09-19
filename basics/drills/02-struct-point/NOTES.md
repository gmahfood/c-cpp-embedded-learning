# Struct Point2D drill — progress notes (2026-09-19)

## Done and verified
- `struct Point2D { double x; double y; };` — correct.
- `Point2D make_point(double x, double y)` — correct. Declares a local
  `Point2D`, sets `.x`/`.y` via the dot operator, returns it.
- `double distance(Point2D a, Point2D b)` — correct. Verified against the
  3-4-5 triangle: `distance((0,0), (3,4)) == 5`.

## Mistakes made along the way (things to watch for next time)
- Forgot the `;` after the `struct { ... }` definition — classic C/C++ gotcha,
  caused a confusing "cannot be defined in the result type of a function"
  error pointing at the wrong-looking line.
- Wrote function declarations that didn't match the spec's signature
  (wrong return type and/or wrong parameters) — happened on both
  `make_point` and `midpoint`. Habit to build: before typing a signature,
  reread the one-line spec comment for that function.
- `distance` took several passes to get right — kept mixing up which
  coordinates to combine (multiplying instead of subtracting, pairing
  `a.y` with `a.x` instead of `a.x` with `b.x`, calling `sqrt` twice
  separately instead of once on the summed squares, forgetting `return`
  entirely). Root cause: needed to slow down and map the plain-English
  Pythagorean theorem (leg = difference in one axis, square each leg, add
  the squares, square-root the sum) onto code *before* typing, instead of
  typing first and hoping it converges.
- Saved to the wrong state / forgot to `:w` in nvim more than once before
  asking for a check — worth doing a reflex `:w` before saying "check it."

## Still to do (pick up here)
1. **`midpoint`** — signature is currently wrong (returns `double`, should
   return `Point2D` per the spec). Fix the signature first. Then the body:
   midpoint is just the *average* of each coordinate —
   `(a.x + b.x) / 2` and `(a.y + b.y) / 2` — packaged into a `Point2D`
   (can reuse `make_point` for that last step instead of building it by hand).
2. **`print_point`** — body is still empty. Needs to print like
   `(1.00, 2.00)` — two decimal places. Will need `<iomanip>`
   (`std::fixed` + `std::setprecision(2)`), or an equivalent `printf`-style
   format.
3. **`main()`** — still just `return 0;`. Needs to:
   - make two points with `make_point`
   - print both with `print_point`
   - print `distance(a, b)`
   - print `midpoint(a, b)` (via `print_point` again)

## Next session starting point
Fix `midpoint`'s return type, then write its body using the
average-of-coordinates approach above.
