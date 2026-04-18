## GDB Commands

- **info locals:**
  This command displays all the local variables and their current values within the active stack frame,
  which is the function you are currently debugging.
  It is an excellent way to get a snapshot of the environment at a specific breakpoint
  before stepping further into the logic.
  
- **continue:**
  Think of this as the "play" button after you've paused a video.
  Once execution is halted at a breakpoint, typing `continue` tells the debugger
  to resume running the program at full speed until it hits the next breakpoint,
  encounters an error, or finishes executing.
  
- **watch variable_name:**
  This sets a data breakpoint, or a "tripwire," on a specific variable.
  Instead of pausing the program at a specific line of code,
  the debugger will automatically halt execution the exact moment that variable's value is modified.
  This is incredibly powerful for tracking down rogue pointer assignments or unintended memory overwrites.

## Core Loop Concepts (C89 Standard)

- **`for` statement syntax:**
  A `for` loop consolidates the three main elements of
  iteration—initialization, condition, and increment—into a single, readable line.
  In the strict C89 standard, the loop counter variable must be declared at the beginning of the block,
  prior to the loop itself.

  ```c
  int i; /* Declaration must happen before the loop in C89 */
  for (i = 0; i < 10; i++) {
          /* Code to execute */
  }
  ```

- **Counting from 1 to 5:**
  ```c
  int i;
  for (i = 1; i <= 5; i++) {
      printf("%d ", i);
  }
  /* Output: 1 2 3 4 5 */
  ```

- **Counting from 5 to 1:**
  ```c
  int i;
  for (i = 5; i >= 1; i--) {
      printf("%d ", i);
  }
  /* Output: 5 4 3 2 1 */
  ```

## Algorithmic Examples

- **Decimal to Binary:**
  For systems programming,
  extracting binary values is often best done using bitwise operators rather than mathematical division,
  as it directly mirrors how the hardware processes the data.
  This example checks each bit from left to right assuming a 32-bit integer.

  ```c
  void print_binary(unsigned int n)
  {
          /* Create a mask with only the most significant bit set to 1 */
          unsigned int mask = 1 << 31; 
      
          while (mask > 0) {
                  /* If bitwise AND is non-zero, the bit is 1 */
                  if ((n & mask) == 0) {
                      printf("0");
                  } else {
                      printf("1");
                  }
                  mask >>= 1; /* Shift the mask one position to the right */
          }
          printf("\n");
  }
  ```

- **Fibonacci Numbers:**
  An iterative approach to printing the sequence (0, 1, 1, 2, 3, 5...).
  It is generally safer and more memory-efficient than a recursive approach,
  avoiding stack overflow risks for larger inputs.

  ```c
  void print_fibonacci(int count) {
          int a = 0, b = 1, next, i;
      
          for (i = 0; i < count; i++) {
                  printf("%d ", a);
                  next = a + b; /* Calculate the next term */
                  a = b;        /* Shift variables forward */
                  b = next;
          }
          printf("\n");
  }
  ```

- **Finding out PIN number by Brute Force Simulation**
  This demonstrates an exhaustive search algorithm, testing every possible 4-digit combination.
  Using `%04d` ensures that numbers like `7` are printed correctly as `0007`.
  
  ```c
  void find_pin(int target_pin) {
          int attempt;
      
          for (attempt = 0; attempt <= 9999; attempt++) {
                  if (attempt == target_pin) {
                          printf("PIN successfully cracked: %04d\n", attempt);
                          break; /* Stop searching once found */
                  }
          }
  }
  ```

- **3-6-9 Game:**
  A simulation of the classic game where a player must clap instead of saying a number
  if it contains a 3, 6, or 9.
  This is an excellent exercise for teaching students how to isolate individual digits
  using the modulo (`%`) and division (`/`) operators.
  
  ```c
  void play_369(int max_number)
  {
          int i, temp, digit, clap_count;
      
          for (i = 1; i <= max_number; i++) {
                  temp = i;
                  clap_count = 0;
          
                  /* Extract and check each digit */
                  while (temp > 0) {
                          digit = temp % 10; 
                          if (digit == 3 || digit == 6 || digit == 9) {
                              clap_count++;
                          }
                          temp /= 10; /* Remove the last digit */
                  }
          
                  /* Output logic based on how many 3s, 6s, or 9s were found */
                  if (clap_count > 0) {
                          printf("Clap! ");
                  } else {
                          printf("%d ", i);
                  }
      }
      printf("\n");
  }
  ```
