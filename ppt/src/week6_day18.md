## Function Mechanics & Local Scope

- **identifier of object in function:** how do we name local data?

  A unique human-readable label like `count` or `x` given to a variable declared inside a function.
  To the compiler, this identifier simply acts as a mapped offset
  representing a specific physical slot within that function's temporary stack frame.

- **duplicate identifier in function:** can two variables have the same name?
  Within the exact same block scope,
  it is strictly illegal to declare two objects with the identical name.
  This causes a compilation error.
  However, an identifier defined in a nested inner block, like inside a `while` loop,
  can temporarily "shadow" or hide an identically named variable from an outer block.
  
- **meaning of function call:** what actually happens when we use a function?

  It is a control flow instruction that abruptly pauses the execution of the current code,
  packages the current environment context onto the call stack,
  and physically jumps the CPU's instruction pointer
  to the starting memory address of the target function's compiled code.
  
- **value stored in parameter:** what exactly does the function receive?

  Standard C strictly uses "pass-by-value."
  The parameter variable in the receiving function is a brand-new, completely independent local object.
  The data stored inside it is an exact, isolated physical copy of the original value passed by the caller.
  
- **void return type:** how do we say "no answer needed"?

  Declaring a function with a `void` return type explicitly tells the compiler
  that this logic block performs an action, like printing to a screen,
  but will absolutely not pass any mathematical or data value back to the caller's environment.
  
- **return without value:** how do we exit early without a result?

  In a `void` function, you can use the standalone keyword `return;`.
  This immediately halts the function's execution and destroys its stack frame,
  but safely passes nothing back.

- **no return statement in void function:** what happens if we forget to write return?

  When the execution thread naturally reaches the closing curly brace `}` of a `void` function,
  the compiler has automatically generated a hidden, implicit return instruction
  to safely clean up the stack and jump back to the caller.

## Pointers & Array Arguments

- **address in parameter:** how do we let a function change original data?

  By declaring a parameter as a pointer, e.g., `int ptr`.
  The parameter is still a copy, but it is a copy of a memory location.
  The function can use the dereference operator `*` on this address
  to reach out of its own stack frame and directly modify the caller's original memory.
  
- **address argument:** how do we send a location?

  When calling a function that expects a pointer,
  you must provide a valid mathematical memory address.
  This is typically done by placing the address-of operator `&`
  in front of an existing variable, e.g., `update_score(&player_score)`.
  
- **array parameter:** how does a function receive an array?

  Even if you declare a parameter with array brackets, e.g., `void print(int arr[])`,
  the C compiler silently forces it to "decay" into a standard pointer (`int arr`).
  You are never receiving a physical copy of the whole array;
  you are exclusively receiving the starting address of its 0th element.
  
- **array parameter and size parameter:** why do arrays need a second argument?

  Because arrays decay into simple pointers when passed to a function,
  the function mathematically loses all knowledge of the array's original physical length.
  You must strictly pass a separate integer representing the item count,
  e.g., `process(int arr, int size)`
  so the function knows exactly when to stop iterating and avoid memory overflows.

- **array argument:** how do we send an array?

  You simply pass the array's identifier, e.g., `print(my_list)`.
  Because of array decay, the name automatically evaluates to the starting memory address,
  making it a perfectly valid pointer argument for the function to catch.

## The Call Stack & System Security

- **address of next instruction:** how does the CPU know where to come back to?

  Also known as the Program Counter context.
  Before jumping to a new function,
  the CPU automatically saves the memory address of the very next line of code,
  which ist he return address, onto the call stack.
  This ensures that when the target function finishes, execution resumes exactly where it left off.

- **valid memory in function call:** which data is safe to use?

  A running function is strictly isolated.
  It can only safely access its own local variables in its active stack frame,
  dynamically allocated heap memory, global/static variables,
  or memory explicitly handed to it via valid pointers.

- **access memory outside activation stack memory:** what happens if we look beyond our boundaries?

  Attempting to read or write to stack memory belonging to other functions,
  or functions that have already returned, is a severe violation.
  It results in undefined behavior, silent data corruption,
  or a fatal segmentation fault if the operating system catches the illegal access.

- **return address:** where is the exact jumping point stored?

  A specific hardware-level value buried within the stack frame when a function is called.
  It physically points the CPU back to the exact machine code line in the caller's block.

- **return address modification:** how do hackers hijack a program?

  A classic technique known as "Stack Smashing."
  If a function has a vulnerability like a buffer overflow,
  an attacker can write past a local array's boundaries
  and intentionally overwrite the hidden return address.
  When the function finishes, instead of jumping back to the program,
  the CPU blindly jumps to the malicious code injected by the attacker.

## Recursion

- **recursion:** how does a function loop using itself?

  A structural design pattern where a function solves a small piece of a problem,
  and then pauses itself to call a brand-new, nested instance of itself to solve the next piece.
  It relies entirely on the call stack's Last-In, First-Out nature
  to remember the history and data of all paused instances.

- **recursion and infinite call:** what happens if recursion never stops?

  If a recursive function lacks a valid "base case",
  which is a strict condition telling it to stop calling itself,
  it will endlessly push new stack frames into memory.
  Eventually, the physical RAM allocated for the system stack is completely exhausted,
  resulting in a fatal Stack Overflow crash.
