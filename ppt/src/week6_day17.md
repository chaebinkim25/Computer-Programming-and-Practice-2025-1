## Core Arithmetic & Safe Math

- **add function:** how do we combine values?

  A fundamental operational block that takes two integer arguments,
  computes their mathematical sum using the CPU's arithmetic logic unit,
  and returns the resulting value to the caller.

- **overflow save addition of positives function:** how do we add without crashing?

  A defensive programming routine designed to prevent integer overflow,
  which causes undefined behavior in standard C.
  Before executing `a + b`,
  it mathematically verifies that there is enough physical room left in the data type.
  It does this by checking if `b <= INT_MAX - a`.
  If the check fails,
  the function safely aborts or returns an error code
  instead of silently wrapping around to a corrupted negative number.
  
- **multiply function:** how do we scale values?

  A routine that takes two arguments and computes their product.
  While written simply as `a * b` in C, at the hardware level,
  standard multiplication is significantly more complex and computationally expensive than addition,
  often requiring a dedicated, multi-cycle instruction set within the CPU.
  
- **multiplication by addition function:** how do we multiply without a multiplier?

  An algorithmic simulation of multiplication, often used to understand primitive hardware constraints.
  It calculates `a * b` by setting an accumulator variable to `0`,
  and then writing a loop to literally add `a` to that accumulator exactly `b` times.
  It proves that multiplication is fundamentally just highly structured,
  repetitive addition.

## Modular Arithmetic & Cryptography

- **mod multiplication function:** how do we multiply within a boundary?

  A function that calculates the product of two numbers and immediately restricts the result
  using the modulo operator, e.g., `(a * b) % m`.
  In cryptography, this is critical for keeping calculations within a strict "finite field,"
  ensuring numbers wrap around cleanly instead of growing infinitely large.
  
- **modular power function:** how do we calculate massive exponents safely?

  An essential cryptographic algorithm, also known as modular exponentiation,
  used to calculate `(base^exponent) % mod`.
  If you tried to calculate standard `base^exponent` first,
  the number would instantly overflow any physical memory limit.
  Instead, this algorithm applies the modulo operation continuously
  at every single step of the multiplication process,
  guaranteeing the physical numbers never exceed the integer limit
  while mathematically arriving at the exact correct final remainder.
