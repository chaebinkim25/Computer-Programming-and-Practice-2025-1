## Common Compiler Errors & Memory Traps

- **incomplete type "int []" is not allowed:** why does the compiler refuse an empty bracket?

  Because the compiler must know exactly how much physical memory to reserve at compile time.
  If you declare an array without a size in the brackets and without an initializer list,
  e.g., `int arr[];`, it is considered "incomplete" and cannot be physically created.
  
- **the size of an array must be greater than zero:** why can't we make an empty array?

  In standard C, every allocated object must occupy a physical amount of memory.
  A zero-length array provides no storage and makes no logical sense for allocation,
  so the standard strictly forbids it.
  
- **array of void is not allowed:** why can't we store "nothing"?
 
  The `void` keyword represents the intentional absence of a specific data type.
  Because `void` has no defined size (in bytes),
  the compiler cannot mathematically calculate how much memory to reserve for an array of them.
  
- **invalid initializer:** why did my starting data fail to load?
 
  This error triggers when you attempt to fill an array with incompatible data.
  For example, trying to initialize an integer array using a string, or trying to use a variable
  rather than a fixed constant to initialize a globally scoped array.
  
- **excess elements in array initializer:** what happens if we overfill the braces?
 
  You explicitly instructed the compiler to reserve a specific number of slots, e.g., `int arr[3];`,
  but you provided too many values in the curly braces, e.g., `{1, 2, 3, 4}`.
  The compiler steps in to stop a guaranteed memory overflow before the program is even allowed to run.

- **expression must be a modifiable lvalue:** why can't I reassign an entire array?

  An array's identifier, its name, intrinsically represents the permanent,
  fixed memory address of its very first element.
  It is a constant pointer, not a modifiable variable.
  You cannot write `listA = listB;`
  because you cannot physically pick up and move the starting address of a compiled array.

## The Array List Data Structure

- **list:** how do we represent an ordered sequence conceptually?

  An abstract concept in computer science representing a finite,
  ordered sequence of data items where the exact same value might appear multiple times.

- **array list:** how do we build a list using physical arrays?
- 
  A concrete implementation of the list concept using a standard, contiguous C array.
  It offers incredibly fast read access, but because C arrays cannot grow or shrink,
  the programmer must manually track a separate count variable to know exactly
  how many of the allocated slots are currently full.

- **add data to array list:** how do we insert a new item?

  If adding to the very end,
  you place the data at the index matching your current count and then increment the count.
  However, if inserting into the middle,
  you must write a loop to physically copy and shift all subsequent elements one slot to the right
  just to make a safe gap for the new data.

- **delete data from array list:** how do we remove an item without leaving an empty hole?

  You cannot simply erase the slot, as that breaks the contiguous nature of the list.
  Instead, you must write a loop to take every element to the right of the target
  and physically shift them one slot to the left, overwriting the deleted item and closing the gap,
  before decrementing your count.
  
- **find data in array list:** how do we search disorganized data?

  Using a "Linear Search". You write a loop starting at index 0 and check every single element,
  one by one, until you either find a match or reach the end of the filled list.
  
- **sort data in array list:** how do we logically organize the collection?

  Applying a specific algorithm, like Bubble Sort or Insertion Sort, to repeatedly compare and swap
  the physical elements in the array until they are perfectly arranged in ascending or descending order.

- **find data in sorted array list:** how do we search intelligently?

  Using a "Binary Search".
  Because the data is guaranteed to be sorted, you do not need to check every item.
  You check the exact middle element;
  if your target is smaller, you instantly discard the entire right half of the array.
  You repeat this halving process, finding the data exponentially faster than a linear search.
