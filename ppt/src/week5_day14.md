## Pointers & Direct Memory Access

- **pointer variable:** what kind of variable holds a memory location?

  A derived data type engineered exclusively to store the mathematical memory address of another object,
  rather than storing a standard data value like a number or a character.
  
- **save value to the specified address:** how do we write data using a pointer?

  By using the dereference operator on the left side of an assignment `*ptr = 5;`.
  This instructs the CPU to travel to the exact physical memory address
  stored inside the pointer and overwrite the bytes at that destination.
  
- **read value from the specified address:** how do we fetch data using a pointer?

  By using the dereference operator in a standard expression, e.g., `int x = ptr;`.
  The compiler looks at the address in the pointer, travels to that slot in memory,
  and reads the raw data stored there.

## Array Decay & Pointer Arithmetic

- **address of each member of array:** how is an array physically laid out?

  As a strictly contiguous block of memory.
  The address of each subsequent member is exactly `sizeof(type)` bytes
  immediately after the previous member's address, with zero padding or gaps between elements.

- **address of 0th array index member:** where does an array start?

  The very first physical slot in the allocated memory block.
  This specific address serves as the foundational baseline, offset `0`,
  for all mathematical pointer arithmetic involving that array.
  
- **access to 0th array member:** how do we interact with the first item?

  You can access it using standard bracket syntax, `arr[0]`,
  or by directly dereferencing the decayed array pointer, `*arr`,
  as adding an offset of 0 requires no physical memory shift.
  
- **what should be the meaning of array:** what does the array's name actually represent?

  In almost all C expressions,
  an array's identifier intrinsically "decays" into a constant pointer aimed precisely at its 0th element.
  It represents the permanent starting address of the memory block.
  
- **how to save array to pointer:** how do we capture a decayed array?

  By assigning the array's name directly to a pointer of the exact same underlying type,
  e.g., `int p = arr;`.
  You do not use the `&` operator here
  because the array name already automatically evaluates to the starting address.
  
- **address of array:** how do we get a pointer to the entire array block?

  While `arr` decays to a pointer to the first element `int *`,
  explicitly using the address-of operator,
  `&arr` yields a "pointer to an array" `int (*)[size]`.
  It points to the exact same physical memory location,
  but the compiler treats its mathematical scale differently.
  
- **index operator `[]`:** how does bracket syntax actually work?

  It is strictly a syntactic shortcut for pointer arithmetic and dereferencing.
  When you write `a[i]`,
  the compiler mechanically translates it into `*(a + i)`: take the base address,
  jump forward `i` slots, and dereference that location.
  
- **how to save value to second member:** how do we write to index 1?

  You use the assignment operator with either the subscript shortcut `arr[1] = value;`
  or explicit pointer arithmetic `*(arr + 1) = value;`.

- **adding data to array list:** how do we insert an item?

  You place the data at the index matching your current element count `list[count] = data;`,
  and then immediately increment that count variable.
  If inserting in the middle,
  you must use a loop to shift existing elements rightwards first.

## Multi-Dimensional Arrays

- **array of array:** what is a 2D array fundamentally?

  Standard C does not possess true multi-dimensional memory grids.
  A 2D array is simply a standard 1D array
  where every single individual element is itself another fully formed 1D array.

- **how to make two-dimensional array:** how do we allocate a grid?

  By declaring an array with two sets of brackets, e.g., `int grid[3][4];`.
  This instructs the compiler to allocate one completely flat,
  contiguous memory block large enough to hold 3 consecutive arrays,
  each containing 4 integers, 12 integers in a row.
  
- **what can save two-dimensional array:** how do we point to a grid?

  Because a 2D array decays into a pointer to its first element which is a 1D array,
  you must capture it using a "pointer to an array",
  e.g., `int (*ptr)[4] = grid;`.
  The pointer must explicitly know the width `4`
  so it knows exactly how many bytes to jump when moving from one row to the next.
  
- **how to use subscription operator `[]` twice:** how do we navigate the grid?
- 
  In the expression `grid[row][col]`,
  the first bracket `[row]` performs pointer arithmetic to jump to the correct 1D array (the row).
  That row then decays into a pointer,
  and the second bracket `[col]` jumps to the specific item within that row.
  
- **how to get 0th one-dimensional array, and get 0th variable:** how do we access the very first cell?

  By writing `grid[0][0]`.
  The first `[0]` accesses the very first nested array,
  and the second `[0]` dereferences the very first integer slot within that specific nested array.
