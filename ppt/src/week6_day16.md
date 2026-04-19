## Arrays vs. Functions

- **array vs function:** what is the fundamental difference?

  An array is a data structure designed to store a collection of values.
  A function is a block of executable code designed to perform a specific task.
  One holds the ingredients; the other is the recipe.

- **array vs function in memory:** where do they physically live?

  An array, if local, exists in the read/write stack memory, or, if global, in the data segment.
  A function exists exclusively in the "text" or code segment of memory,
  which is strictly read-only to prevent the program from accidentally overwriting its own instructions.

- **array vs function when prepared:** when does the system allocate them?

  The memory for a function's instructions is prepared and loaded once at compile load time
  before the program even begins running.
  The memory for a local array is dynamically allocated at runtime,
  the exact moment the execution thread enters the block where the array is defined.

## Global Variables vs. Functions

- **global variable vs function:** how do they compare at the file level?

  Both exist at the "file scope,"
  meaning they are declared outside of any block and are visible to the entire program.
  However, a global variable holds mutable state that any part of the program can change,
  while a function holds immutable logic that any part of the program can call.
  
- **global variable vs function difference:** what sets them apart functionally?

  A global variable represents a shared memory address containing data
  that persists for the entire life of the program.
  A function represents a memory address containing executable machine code
  that is temporarily jumped to and executed.
  
- **global variable vs function same:** what core properties do they share?

  Both possess "static storage duration" they exist for the entire lifetime of the program,
  never being destroyed until the program terminates
  and "external linkage" by default meaning other `.c` files in the project can find and use them.

## Data Retrieval & Interfaces

- **how to get data from array:** how do we extract stored values?

  By using the subscript operator `[]` or pointer arithmetic to directly target
  and read a specific physical offset within the array's contiguous memory block.

- **how to get data from function:** how do we extract computed answers?

  By using the function call operator `()` to invoke the logic,
  and relying on the function's `return` statement.
  The function computes a result,
  places it in a specific CPU register or stack slot,
  and passes that single value back to the caller's execution environment.
  
- **argument:** what is the data we send?

  The actual,
  physical data value or memory address
  that the caller passes into the function during the function call,
  e.g., the `5` in `calculate(5)`.

- **scope of parameter:** where does the received data live?

  Parameters have strict "block scope."
  They act exactly like freshly initialized local variables that belong exclusively to the function.
  They are created when the function starts and are permanently destroyed the moment the function returns.
  
- **two parameters:** how do we pass multiple pieces of data?

  Separated by commas in both the definition `int add(int a, int b)` and the call `add(5, 10)`.
  The compiler rigorously enforces that the caller provides exactly the right amount of arguments,
  pushing them onto the stack or into CPU registers,
  in a strictly defined order so the receiving parameters catch them correctly.

## Hardware Limitations & Safe Logic

- **overflow-safe addition:** how do we prevent math from breaking the computer?

  In C, signed integer overflow results in "undefined behavior", a catastrophic logical error.
  Because standard math operations don't warn you if a number gets too big for its memory slot,
  you must mathematically verify the safety of the addition before executing it.
  For example, checking `if (a > 0 && b > INT_MAX - a)` ensures
  that adding `a` to `b` won't accidentally cross the hardware's maximum integer limit.
