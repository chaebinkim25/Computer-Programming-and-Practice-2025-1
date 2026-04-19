## Constant Data & Memory Protection

- **constant object declaration:** how do we make a variable read-only?

  Using the `const` keyword during definition, e.g., `const int max = 100;`.
  This explicitly instructs the compiler to lock the memory slot.
  Once initialized, the program is physically forbidden from ever changing that value again.
  
- **array of constant objects:** how do we lock an entire list?

  By declaring the array with `const`, e.g., `const int pins[] = {1234, 5678};`).
  Every single contiguous memory slot inside that block becomes strictly read-only.
  You can read the data, but attempting to reassign any element will trigger a fatal compiler error.

- **constant parameter:** how do we protect incoming function arguments?

  By placing `const` in the parameter list, e.g., `void print_data(const int x)`.
  This acts as a legal contract guaranteeing
  that the function will use the provided data but absolutely will not alter it.
  This is especially critical when passing pointers,
  ensuring the function doesn't silently corrupt the caller's original memory.

## Pointers & `const` Correctness

- **pointer to constant object:** how do we look at locked data?
  
  Declared as `const char *ptr;` (or `char const *ptr;`).
  The pointer itself is mutable, meaning you can change *where* it aims.
  However, the data it points *to* is locked;
  you cannot use `*ptr = 'A'` to modify the destination's memory.

- **constant pointer to object:** how do we lock the address, but not the data?

  Declared as `char * const ptr;` (the `const` is after the asterisk).
  The exact opposite scenario.
  You can freely change the data at the destination using `*ptr = 'A'`,
  but you can never change the pointer to aim at a different memory address once it is initialized.

- **proper type to store string literal:** how do we safely point to hardcoded text?

  Because string literals like `"Hello"` are physically stored in
  the executable's read-only memory segment,
  you must always capture them using a "pointer to a constant character": `const char *str = "Hello";`.
  Using a standard `char *` is dangerous and will cause a Segmentation Fault
  if you accidentally attempt to modify the text.

## String I/O & Array Parameters

- **char array as a parameter:** how do functions receive strings?

  Just like standard arrays, character arrays instantly decay into pointers when passed to a function.
  Even if you write `void parse(char str[])`, the compiler translates it to `void parse(char *str)`.
  You are exclusively passing the memory address of the first letter, not the whole string.

- **function to print string:** how do we output a full text sequence?

  Standard library functions from `<stdio.h>`.

  * `printf("%s", str);` iterates through the memory starting at the pointer
    until it hits the `'\0'` null terminator, without adding a new line.
  * `puts(str);` does the exact same thing but automatically appends
    a `'\n'` newline character to the output stream.

- **function to input string:** how do we safely read text from the keyboard?

  Reading text in C is notoriously dangerous due to buffer overflows.

  * `scanf("%s", buffer);` is highly discouraged because it blindly reads until it hits a space,
    potentially writing past your array's physical memory boundary.

  * `fgets(buffer, size, stdin);` is the strictly secure standard.
    It forces you to explicitly provide the maximum array size,
    guaranteeing it will stop reading from the keyboard
    *before* it accidentally overflows your allocated memory block.

