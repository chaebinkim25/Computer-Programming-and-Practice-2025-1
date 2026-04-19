## Pointer Arithmetic & Array Iteration

- **calculating address of next item in array:** how do we mathematically move forward in memory?

  Because arrays are contiguous,
  pointer arithmetic automatically scales based on the data type's size.
  Adding `1` to an integer pointer `ptr + 1` doesn't add 1 byte;
  it mathematically adds exactly enough bytes to reach the very next integer in the sequence
  e.g., +4 bytes on a standard 32-bit architecture.

- **comparing `[]` and `*`:** which syntax is better for accessing memory?

  The bracket syntax `arr[i]` is highly readable and best for standard array traversal.
  The dereference operator `*(arr + i)` or `*ptr` is mathematically identical
  to the compiler but is often used in lower-level algorithms,
  or when explicitly manipulating pointer variables as they physically move through memory.
  
- **use address as loop variable:** can we iterate without an integer counter?

  Yes. Instead of an integer `i` counting from 0 to 10,
  you use a pointer variable that starts at the base address of the array
  and physically increments its memory location
  until it reaches the boundary address at the end of the array.
  
- **initialization expression in address for loop:** how do we set the starting memory location?

  You assign the base address of the array to a pointer.
  For example, `int p = arr;` or `int p = &arr[0];`.
  This places the pointer directly on the very first element.

- **condition expression in address for loop:** how do we know when to stop moving through memory?

  You compare the current pointer's address against
  the calculated address of the theoretical "one-past-the-end" element.
  For example, `p < arr + size;`.
  As long as the pointer hasn't crossed this strict physical boundary,
  the loop continues.
  
- **update expression in address for loop:** how do we take a step to the next memory slot?

  You increment the pointer using the postfix operator `p++`.
  This automatically scales by the size of the data type,
  physically moving the pointer to aim at the exact starting byte of the next element
  in the contiguous sequence.
  
- **loop statement in address for loop:** how do we interact with the current element?

  Inside the loop body, you simply dereference the current pointer `*p`
  to directly read or write the data located at that specific physical address for the current cycle.

## Operator Precedence

- **operator precedence `[]` and `+`:** which happens first: indexing or addition?

  The subscript operator `[]` has very high precedence,
  higher than the binary addition operator `+`.
  In the expression `arr[i] + 5`, the compiler fetches the physical value at index `i` first,
  and then adds 5 to that retrieved number.
  
- **operator precedence `[]` and `&`:** how do we get the address of a specific slot?

  The subscript operator `[]` has higher precedence than the unary address-of operator `&`.
  In the expression `&arr[i]`,
  the compiler evaluates `arr[i]` first to target the specific physical slot,
  and then the `&` steps in to grab the mathematical memory address of that specific slot.
  
- **operator precedence `*` and `+`:** which happens first: dereferencing or addition?

  The dereference operator `*` has higher precedence than standard binary addition `+`.
  In the expression `*ptr + 1`, the system reads the value residing at `ptr` first,
  and then adds 1 to that value.
  If you want to mathematically step the pointer forward before* reading,
  you must force precedence with parentheses: `*(ptr + 1)`.

## Memory Safety

- **buffer overflow:** what happens if we ignore memory boundaries?

  A critical and widely exploited security vulnerability that occurs
  when a program writes data past the strictly allocated physical boundary of an array or buffer.
  Because standard C does not automatically check bounds at runtime,
  this runaway data simply overwrites whatever happens to be sitting in the adjacent memory spaces,
  causing silent data corruption, system crashes,
  or allowing malicious code execution.
