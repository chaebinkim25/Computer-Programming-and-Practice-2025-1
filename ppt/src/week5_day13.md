## Object Definition & Block Scope

- **where object definition is allowed:** where can I declare my variables?

  In C, variables can be defined either at the "file scope", outside of any function, making them global,
  or within a "block scope", inside a function or a set of curly braces `{}`.

- **object definition in a block:** how do we create local data?

  Writing a declaration statement, like `int score;` explicitly inside a set of curly braces `{}`.
  This creates an isolated variable that belongs strictly to that specific block.

- **meaning of object definition:** what happens when I define a variable?

  You are instructing the compiler to do two things:
  allocate a physically contiguous block of memory of the correct size,
  and permanently bind your chosen identifier, the variable name, to that memory address
  for the duration of its scope.

- **when memory for object is prepared:** when does the data physically exist?

  For block-scoped, in another word, local objects, the memory is allocated on the system stack
  the exact moment the execution sequence enters the block where it is defined.

- **which code can use object after its definition:** who can see my variable?

  Only the code that sequentially follows the definition and
  remains completely inside the same enclosing curly braces `{}`.
  To the rest of the program, the variable does not exist.

- **when memory for object is returned:** when is the data destroyed?

  The exact moment the program's execution flow hits the closing curly brace `}` of the block,
  the stack pointer recedes.
  The memory is instantly reclaimed by the system, and any data left inside is functionally abandoned.

- **why define object in a block:** why restrict our data?

  To ensure "encapsulation" and safe memory management.
  By keeping the variable's lifespan short and isolated,
  you prevent other parts of the program from accidentally modifying it,
  and you ensure the memory is quickly freed for reuse.
  
- **how to define object for `for`-statement:** where does the loop counter go?

  In strict C89, you must define the loop variable at the very top of the function block.
  In modern C, meaning C99 and later, you can define it directly inside the loop's initialization phase
  `for (int i = 0; ...)`; its scope will be restricted entirely to the loop body.

- **memory layout regarding block:** how does the computer track nested braces?

  The computer uses a Stack.
  Every time you enter a new block, its local variables are pushed onto the top of the stack frame.
  When you exit that block, those specific variables are popped off,
  returning the stack to the exact state it was in before the block began.
  
- **what is the point of object:** why do we call it an "object"?
 
  In standard C terminology,
  an "object" is simply a physical region of data storage in the execution environment.
  Its point is to physically hold the state, meaning the raw values, of your program as it runs.

## Pointers & Memory Navigation

- **why address of an object is needed:** how do we share data efficiently?

  When you pass a variable to a function, C makes a complete, isolated copy of it.
  If you want a function to physically alter the original data,
  or if you want to share a massive data structure without wasting time and memory copying it,
  you must pass its exact memory location instead.

- **address-of operator `&`:** how do we find where data lives?

  A unary operator placed directly in front of a variable, e.g., `&score`.
  It evaluates to the exact mathematical memory location, the address,
  where that specific object's data begins.
  
- **pointer type:** what kind of variable holds an address?

  A specific, derived data type engineered exclusively to store memory addresses
  rather than standard values like numbers or text. 

- **pointer declaration:** how do we prepare the system to store an address?

  You declare it by combining a base data type with an asterisk, which tells the compiler,
  "Reserve memory to hold an address, and expect to find this specific type of data at that destination",
  e.g., `int ptr;`.

- **pointer declarator `*`:** how do we signify a pointer?

  The asterisk symbol `*` used specifically during the declaration phase
  to explicitly mark the identifier as a pointer.

- **dereference operator `*`:** how do we interact with the data at an address?

  Used in an executable expression not a declaration.
  Placing the asterisk before a pointer variable, e.g., `*ptr = 5;` instructs the compiler
  to "travel to the address stored in this pointer,
  and interact directly with the physical memory slot found there."
  
- **calculating the address of minimum value:** how do we track locations instead of values?

  When searching an array for the smallest number,
  instead of saving the smallest number* to a variable,
  you use a pointer to save the memory address of the slot containing the smallest number.
  This allows you to not only know what the minimum is,
  but exactly where it physically resides so you can modify or swap it later.

## Arrays, Pointers & Memory Offsets

- **why array decay:** why does C change arrays into pointers?

  A deliberate performance mechanism.
  If you tried to pass a 10,000-element array into a function,
  copying it would instantly crash the stack memory.
  To prevent this,
  C automatically "decays" (converts) the array's name into a simple,
  lightweight pointer aimed at its very first element.
  
- **which type can store array:** how do we catch a decayed array?
  
  Because arrays decay into addresses, you cannot store an array in a standard variable.
  You must catch and store it using a pointer
  whose type identically matches the array's underlying data type,
  e.g., catching an `int arr[10]` using an `int *` pointer.
  
- **subscription operator and array decay:** how do brackets work with pointers?

  When you write `arr[3]`, the array name `arr` instantly decays into a pointer pointing to index `0`.
  The compiler then takes that base address,
  mathematically adds `3` units of the data type's size to it,
  and targets that new location.

- **subscription operator and dereference operator:** are brackets just a math shortcut?

  Yes. In standard C,
  the bracket syntax `a[i]` is strictly a human-readable alias
  for the pointer arithmetic expression `*(a + i)`.
  They are mathematically and physically identical to the compiler.

- **array of addresses:** can we make a list of pointers?

  Yes.
  You can declare an array where every single slot is designed to hold a memory address
  rather than a standard value, e.g., `int list[5];`.
  This is heavily used to manage strings or jagged data sets.
  
- **user number and phone numbers example:** how do we link jagged data?

  If one user has 1 phone number and another has 5,
  a standard 2D array wastes memory with empty slots.
  Instead, you create an array of pointers, where the index is the user ID,
  and each pointer aims at
  the exact starting address of a dynamically sized list of phone numbers elsewhere in memory.

- **two dimensional array:** how do grids work in linear memory?
 
  Declared as an "array of arrays", e.g., `int grid[3][4];`.
  While humans visualize it as a 2D table of rows and columns,
  the computer physically allocates it as one completely flat,
  1D contiguous strip of memory.
  The compiler uses hidden math, `row * width + column`, to simulate the 2D grid structure.
