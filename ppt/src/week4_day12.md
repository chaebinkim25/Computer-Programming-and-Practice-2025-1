## Hash Tables & Data Retrieval

- **hash table:** how do we look up data instantly?

  A highly efficient data structure that pairs unique "keys" to specific "values."
  It uses a mathematical algorithm, a hash function, to convert a key into an exact integer index,
  allowing the program to jump directly to the target data's location in memory with O(1) time complexity.

- **hash table to save passwords:** how do we store passwords securely?

  A critical security practice.
  Instead of storing the plain-text password,
  the system runs the password through a cryptographic hash function and stores the resulting hash.
  When logging in, the user's input is hashed and compared to the stored hash.
  Because hashes are one-way, a compromised database will not reveal the actual passwords.

- **add data to hash table:** how do we insert a new key-value pair?

  The system hashes the provided key to calculate an array index.
  The data is then placed at that specific index.
  If that slot is already occupied by different data, a "collision", the table uses a resolution strategy,
  such as chaining, adding it to a linked list at that index,
  or open addressing, finding the next available empty slot.

- **delete data from hash table:** how do we remove an entry safely?

  You hash the key to find its exact location.
  However, you cannot simply erase the slot,
  as this might break the search path for other items that collided.
  Instead, the slot is explicitly marked with a "tombstone" flag,
  indicating that a value used to be there but is now deleted,
  keeping the structural integrity of the table intact.
  
- **initialize hash table:** how do we prepare the structure?

  You must allocate the contiguous memory block for the underlying array of "buckets"
  and explicitly zero them out, e.g., setting all pointers to `NULL`.
  If you do not initialize the array,
  the table might mistake leftover system garbage for valid stored data.
  
- **iterate hash table:** how do we view all stored data?
 
  Because a hash table distributes data unpredictably,
  iterating requires a standard loop to scan every single physical slot
  in the underlying array from beginning to end,
  processing only the slots that actively contain data and ignoring the empty ones.

- **search in hash table:** how do we find a specific item?

  You pass the target key through the exact same hash function used
  during insertion to calculate the expected index.
  You jump to that index and check if the key matches.
  If it doesn't match (due to a collision),
  you follow the collision path until you find the exact key or hit an empty slot.

---

## Unary Operators

- **postfix increment operator `++`:** how do we use a value, then increase it?

  Written after the variable, e.g., `x++`.
  The compiler evaluates the current value of the variable for use in the surrounding expression,
  and only after that step is complete does it physically increase the variable's memory value by 1.

- **postfix decrement operator `--`:** how do we use a value, then decrease it?

  Written after the variable, e.g., `x--`.
  It returns the variable's current value to the immediate expression,
  and subsequently subtracts 1 from the variable in memory.

- **prefix increment operator `++`:** how do we increase a value before using it?

  Written before the variable, e.g., `++x`.
  The compiler physically adds 1 to the variable's value in memory first,
  and then immediately evaluates to that new, updated value for use in the surrounding expression.

- **prefix decrement operator `--`:** how do we decrease a value before using it?

  Written before the variable, e.g., `--x`.
  It subtracts 1 from the variable's value first,
  and then passes the newly decreased value into the active expression.

---

## Stacks, Arrays & Memory

- **stack:** how do we manage data like a physical pile of plates?

  A strict Last-In, First-Out data structure.
  You can only interact with the very top of the stack.
  The last item you put on top is always the exact first item you must take off.
  It is the fundamental architecture used by computers to track function calls and local variables.

- **add data to stack:** how do we push data?

  An operation universally called a push.
  You increment your integer tracking variable, which points to the "top" of the stack,
  and place the new data into the newly designated top slot of the underlying array.

- **delete data from stack:** how do we pop data?

  An operation called a pop.
  You read the data currently at the "top" tracker index, and then simply decrement the top tracker.
  The raw data remains in memory until overwritten,
  but it is officially abandoned and logically "removed" from the stack.

- **fibonacci numbers in array:** how do we calculate the sequence efficiently?

  Using an array to calculate Fibonacci iteratively.
  By setting `fib[0] = 0` and `fib[1] = 1`, you write a `for` loop where `fib[i] = fib[i-1] + fib[i-2]`.
  The array permanently stores the past answers,
  avoiding the massive performance penalty of recursive recalculation.

- **how array is saved in memory:** what does an array look like physically?

  It is allocated as a single, unbroken, contiguous block of raw memory bytes.
  If you have an array of five 4-byte integers, the compiler reserves exactly 20 bytes in a row.
  The elements sit flush against each other with zero gaps, which is why array indexing is incredibly fast.

- **local variable storage duration:** how long does a local variable live?

  Known as "automatic" storage duration.
  The variable is physically created in stack memory
  the precise moment execution enters the block `{}` where it is declared,
  and the memory is automatically freed and reclaimed the exact moment execution leaves that block.

- **scope of local variable:** where can a local variable be seen?

  Known as "block scope".
  A local variable is strictly isolated, invisible, and inaccessible
  to any code outside of the specific curly braces `{}` in which it was declared.

- **bottom-up and top-down in fibonacci:** how do we approach complex sequences?

  "Top-down" starts with the target, e.g., `fib(5)`,
  and recursively calls smaller instances, `fib(4) + fib(3)` down to the base cases,
  often using a cache memoization to remember answers.
  "Bottom-up" starts from the base cases 0 and 1
  and uses a standard loop to build up to the target number iteratively.
  Bottom-up is preferred in C as it eliminates the risk of a stack overflow
  from too many recursive function calls.
