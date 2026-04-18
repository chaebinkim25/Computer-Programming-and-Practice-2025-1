## Fundamental Algorithms & Data Operations

- **finding maximum value:** how do we identify the largest item?
  A core algorithm where you assume the very first item is the largest,
  then scan through the rest of the dataset one by one,
  updating your "current largest" variable whenever you encounter a bigger number. 

- **sorting:** how do we organize raw data?
  The systematic process of rearranging an array of items into a highly predictable sequence,
  making the data exponentially easier to search, analyze, and display later.
  
- **ascending order:** how do we arrange from smallest to largest?
  A sorting rule where data is arranged so that every element is greater than or equal to the one before it,
  e.g. counting up from 0 to 9, or alphabetizing from A to Z.
  
- **descending order:** how do we arrange from largest to smallest?
  A sorting rule where data is arranged so that every element is less than or equal to the one before it,
  e.g., counting down from 9 to 0, or reverse-alphabetizing from Z to A.

- **finding interval:** how do we check if a value is within a specific boundary?
  Using the logical AND operator `&&` to verify that a number satisfies a minimum and maximum limit simultaneously,
  for example, checking if a `score` is both `>= 0` and `<= 100`.

## Classic Logic Applications

- **coin-exchange:** how do we break a large value into smaller units?
  A practical math exercise that perfectly demonstrates C's arithmetic.
  It uses integer division `/` to find out how many of the largest coin fit into the total,
  and the modulo operator `%` to calculate the exact remaining change to pass down to the next coin size.
  
- **leap-year:** how do we handle overlapping, complex rules?
  An elegant test of logical operators `&&` and `||`.
  It requires you to chain conditions together using modulo `%` to check if a year is evenly divisible by 4,
  while simultaneously ensuring it is not divisible by 100, unless it is also divisible by 400.
  
- **rock-scissor-paper game:** how do we program cyclical rules and outcomes?
  A foundational logic problem that teaches you how to map real-world choices to simple integers,
  like 0, 1, and 2.
  It tests your ability to write `if` and `else if` statements to determine the winning relationship
  between three distinct, looping states.

## System & Security Concepts

- **file permission:** how do we manage system security access?
  The Linux/Unix method of strictly defining who is allowed to Read 4, Write 2, or Execute 1 a specific file.
  In C, these permissions are uniquely represented using octal base-8 numbers
  and are often manipulated at the lowest level using bitwise operators.
