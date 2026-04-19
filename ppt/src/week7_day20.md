## Standard I/O & Terminal Mechanics

- **terminal input:** how do keystrokes reach the program?

  The terminal is an OS-level interface.
  When you type on the keyboard,
  the physical hardware sends interrupt signals to the OS,
  which translates them into characters and places them into a dedicated memory stream,
  which is standard input, or `stdin`, for your C program to read.
  
- **`getchar`:** how do we read exactly one keystroke?

  A standard library function that extracts the very next single character waiting in the `stdin` stream.
  It returns it as an `int`, rather than a `char`,
  so it has enough bit-capacity to safely return negative error codes,
  specifically `-1` for End-Of-File `EOF`.
  
- **`getchar` and input buffer:** why does the program wait for me to press Enter?

  Terminals are "line-buffered" by default.
  When you type "Hello", `getchar` does not run five times instantly.
  The OS holds the letters in a hidden buffer memory until you press the `Enter` key `\n`.
  Only then is the entire line released to `stdin` for `getchar` to pull out one by one.

- **terminal output:** how does the program draw text?

  The program pushes characters into an outward-bound memory stream, standard output, or `stdout`.
  The OS monitors this stream, flushes it to the graphics hardware,
  and renders the corresponding pixels on your screen.
  
- **`putchar`:** how do we print exactly one character?

  A standard library function that takes a single character or its integer ASCII equivalent
  and pushes it into the `stdout` stream to be displayed on the terminal.
  
- **echo program:** how do we build a basic terminal mirror?

  A classic systems programming exercise that indefinitely reads from input and writes to output.
  It uses a concise `while` loop: `while ((c = getchar()) != EOF) { putchar(c); }`.
  This perfectly mirrors whatever the user types directly back to the screen.

- **exit key in echo program:** how do we stop an infinite input loop?

  Because the loop runs until it sees `EOF` End of File,
  you must manually send this hardware signal via the keyboard.
  You press `Ctrl+D` on Linux/macOS or `Ctrl+Z` on Windows,
  which strictly commands the OS to close the input stream,
  causing `getchar` to finally return `-1` and break the loop.
  
- **escape sequence:** how do we print invisible formatting commands?

  Using a backslash followed by a specific character like `\n` for a line break or `\t` for a tab.
  While it looks like two characters in the source code,
  the C compiler converts it into one single,
  physical control byte that the terminal interprets as a formatting command
  rather than a printable letter.

---

## Practical Implementations & Algorithmic Loops

- **show hello, world with `putchar`:** how do we print text without `printf`?

  Because `putchar` only handles one character at a time,
  you must physically iterate over the string's memory block until you hit the null terminator.

  ```c
  char msg[] = "Hello, World!\n";
  int i = 0;
  while (msg[i] != '\0') {
          putchar(msg[i]);
          i++;
  }
  ```

- **draw triangle with for loop:** how do we build a right-aligned staircase?

  Using nested loops.
  The outer loop dictates the row number,
  and the inner loop dynamically limits
  how many stars to print based exactly on what row we are currently on.
  
  ```c
  int rows = 5, i, j;
  for (i = 1; i <= rows; i++) {               /* Outer loop: Rows */
          for (j = 1; j <= i; j++) {          /* Inner loop: Stars increase with row */
                  putchar('*');
          }
          putchar('\n');                      /* Move to the next line */
  }
  ```

- **draw inverse triangle with for loop:** how do we build a staircase going down?

  The logic is flipped.
  The inner loop starts at the maximum amount and shrinks as the outer loop progresses.

  ```c
  int rows = 5, i, j;
  for (i = rows; i >= 1; i--) {               /* Outer loop: Counts backwards */
          for (j = 1; j <= i; j++) {          /* Inner loop: Prints fewer stars each time */
                  putchar('*');
          }
          putchar('\n');
  }
  ```

- **draw equal length triangle with for loop:** how do we build a centered pyramid?

  Requires mathematical balancing.
  You need one inner loop just to print the invisible space padding,
  and a second inner loop to print an odd number of stars `(2 * row - 1)`
  to keep the point perfectly centered.
  
  ```c
  int rows = 5, i, space, star;
  for (i = 1; i <= rows; i++) {
          /* First inner loop: Print decreasing spaces */
          for (space = 1; space <= (rows - i); space++) {
                  putchar(' ');
          }
          /* Second inner loop: Print increasing odd number of stars */
          for (star = 1; star <= (2 * i - 1); star++) {
                  putchar('*');
          }
          putchar('\n');
  }
  ```
