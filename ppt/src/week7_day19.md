## Multi-File Compilation & Linkage

- **multiple source files:** how do we build large programs?

  Instead of writing one massive text file, C allows splitting code into modular `.c` files.
  The compiler translates each file individually into an independent binary "object" file `.o`,
  and a system tool called the Linker permanently stitches them all together
  into one final executable program.
  
- **global object declaration:** how do files share variables?

  Using the `extern` keyword.
  It tells the compiler,
  "This variable physically exists somewhere in another file;
  trust me and let me compile without throwing an undefined error."
  It strictly declares the name and type without allocating any new physical memory.
  
- **declaration and definition:** what is the exact difference?

  A declaration introduces an identifier and its type to the compiler like a promise.
  A definition is a declaration that also physically allocates the memory for a variable,
  or provides the executable code body for a function, which is the physical fulfillment of that promise.
  
- **`#include`:** how do we share declarations safely?

  A preprocessor directive that physically copies and pastes the entire text contents
  of a header file `.h` directly into your `.c` file before compilation begins.
  This ensures all your source files agree on the exact same declarations and function signatures.
  
- **library function:** how do we use pre-written code?

  Standardized, highly optimized functions like `printf` or `malloc` whose compiled binary code is provided
  by the operating system or compiler suite, ready to be seamlessly linked into your program's executable.

- **library header file:** how do we access the library?

  Files like `<stdio.h>` containing the exact function declarations, macros, and type definitions
  needed by the compiler to successfully verify and set up calls to the underlying binary library functions.

## Characters & Encoding

- **represent character with number:** how does hardware store text?

  Text is stored by mapping specific integer values to specific human characters
  using an agreed-upon encoding standard, historically, ASCII.
  For example, the computer stores the number `65`,
  which mathematically and universally represents the capital letter `'A'`.

- **character literal:** how do we write a single letter?

  A single character wrapped in single quotes, e.g., `'A'`.
  To the C compiler, this is not text; it is instantly evaluated as an integer constant
  representing its underlying numeric ASCII value.

- **escape sequence:** how do we type un-typeable characters?

  A backslash followed by a specific character like `\n` for newline or `\t` for tab.
  It allows programmers to embed hidden formatting instructions, control codes,
  or reserved syntax symbols directly into text using standard keystrokes.

- **char:** what is the text data type?

  The smallest addressable integer data type in standard C,
  guaranteed to be exactly 1 byte, which is 8 bits, in size.
  While humans use it to store letters, to the CPU,
  it is just a tiny integer capable of holding values from `-128` to `127`.

## Strings & Memory Management

- **string:** what is text conceptually in C?

  Standard C does not have a dedicated "string" data type.
  A string is purely a conceptual convention:
  it is defined strictly as a contiguous sequence of `char` variables in memory,
  terminated by a null character.

- **string literal:** how do we write text blocks?

  A sequence of characters enclosed in double quotes, e.g., `"Hello"`.
  The compiler automatically allocates the sequential memory for these characters
  and silently appends the required null terminator at the very end.

- **null character:** how does the computer know the text is finished?

  A physical byte consisting of all zero bits, written using the escape sequence `'\0'`, 
  numeric value `0`.
  Because C arrays do not inherently know their own length,
  every string-processing function scans memory sequentially
  and strictly stops the exact moment it hits this zero-byte boundary.

- **char array initialization:** how do we build a mutable string?

  By assigning a string literal to a local array during definition: `char name[] = "Alice";`.
  The compiler takes the read-only letters and the null terminator
  and physically copies them into the array's newly allocated read/write stack memory.

- **string literal type:** where do hardcoded strings live?

  A string literal inherently decays into a "pointer to a constant character" `const char *`.
  The physical text is stored in the read-only data segment of the compiled binary.
  Attempting to directly modify a string literal via a pointer, e.g., `char str = "Hi"; str[0] = 'M';`
  will cause a fatal memory access violation, which is segmentation fault.
