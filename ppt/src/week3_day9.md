## Interactive Loops & Patterns

- **Number Guessing Up/Down Game:**

  This is an excellent exercise for teaching standard `while` loops,
  input sanitization, and state management. 

  ```c
  void play_up_down(int secret_number)
  {
          int guess = 0;
          int attempts = 0;
    
          printf("Guess the number between 1 and 100!\n");
    
          while (guess != secret_number) {
                  printf("Enter your guess: ");
                  /* In a secure context, we would validate scanf's return value here */
                  scanf("%d", &guess);
                  attempts++;
        
                  if (guess > secret_number) {
                          printf("Down!\n");
                  } else if (guess < secret_number) {
                          printf("Up!\n");
                  } else {
                          printf("Correct! It took you %d attempts.\n", attempts);
                  }
          }
  }
  ```

* **Pyramid Code in Loop & Solution:**

  A classic visualization of nested loops.
  The outer loop manages the rows (Y-axis), while the inner loops manage the spaces and characters (X-axis).

  ```c
  void print_pyramid(int height)
  {
          int i, j, k;
    
          /* Outer loop: iterates through each row */
          for (i = 1; i <= height; i++) {
                  
                  /* Inner loop 1: prints leading spaces */
                  for (j = i; j < height; j++) {
                      printf(" ");
                  }
                  
                  /* Inner loop 2: prints the stars (2 * row - 1) */
                  for (k = 1; k <= (2 * i - 1); k++) {
                      printf("*");
                  }
                  
                  printf("\n"); /* Move to the next line after the row is complete */
          }
  }
  ```

* **Loop Condition as Input Value:**

  This technique reads data continuously until a specific "sentinel" value or EOF (End of File) is reached.
  It's heavily used in parsing streams.

  ```c
  void process_input_stream()
  {
          int input;
          
          printf("Enter numbers to sum (enter 0 to stop):\n");

          /* The loop checks the assignment and condition simultaneously */
          while (scanf("%d", &input) == 1 && input != 0) {

                  printf("Processing: %d\n", input);
                  /* Logic to handle the input goes here */

          }
          printf("Stream ended.\n");
  }
  ```

## Loop Control Flow

* **The `break` statement:**

  `break` acts as an emergency exit. It immediately terminates the innermost enclosing loop or `switch` statement, bypassing the standard loop condition.

  ```c
  void find_first_negative(int arr[], int size)
  {
          int i;
          for (i = 0; i < size; i++) {
                  if (arr[i] < 0) {
                          printf("Found negative value %d at index %d.\n", arr[i], i);
                          break; /* Stop searching; we found what we needed */
                  }
          }
  }
  ```

* **The `continue` statement:**
  
  Instead of exiting the loop entirely,
  `continue` halts the *current* iteration and immediately jumps back to the loop's condition check
  or the increment step in a `for` loop, to start the next iteration.

  ```c
  void print_odds_only(int max)
  {
          int i;
          for (i = 1; i <= max; i++) {
                  if (i % 2 == 0) {
                          continue; /* Skip the rest of the loop block for even numbers */
                  }
                  printf("%d ", i); /* This only executes if 'i' is odd */
          }
          printf("\n");
  }
  ```

### Low-Level Math & Architecture Concepts

* **Multiplying by Iterating Addition:**

  The most fundamental way to represent multiplication.
  A \times B is simply assigning the value of A to an accumulator, added to itself B times.

  ```c
  int iterative_multiply(int a, int b)
  {
          int result = 0;
          int i;
          /* Using absolute values to handle negatives would be the next step */
          for (i = 0; i < b; i++) {
                  result += a;
          }
          return result;
  }
  ```

* **Binary Multiplication (Shift-and-Add):**

  This is how hardware ALUs actually multiply.
  It is much faster than iterative addition.
  It checks each bit of the multiplier;
  if it's a 1, it adds the multiplicand to the result,
  then shifts the multiplicand left.

  ```c
  unsigned int binary_multiply(unsigned int a, unsigned int b)
  {
          unsigned int result = 0;
          
          while (b > 0) {
                  /* If the lowest bit of b is 1, add 'a' to the result */
                  if (b & 1) {
                          result += a;
                  }
                  /* Shift 'a' left (multiply by 2) */
                  a <<= 1;
                  /* Shift 'b' right (divide by 2, move to the next bit) */
                  b >>= 1;
          }
          return result;
  }
  ```

## Cryptography & Security

* **RSA Encryption:**

  RSA is an asymmetric cryptographic algorithm relying on
  the practical difficulty of factoring the product of two large prime numbers.
  The core mathematical operation for both encryption and decryption is modular exponentiation: 
  $$C = M^e \pmod n$$
  Where $$C$$ is the ciphertext, $$M$$ is the message, $$e$$ is the public exponent, and $$n$$ is the modulus.

* **Power Modulo Function & Loop in Power Modulo:**

  Because $$M^e$$ grows astronomically large, standard data types will immediately overflow.
  We use a loop applying the property that $$(A \times B) \pmod C = ((A \pmod C) \times (B \pmod C)) \pmod C$$. 

  ```c
  /* Calculates (base^exp) % mod efficiently */
  unsigned long long power_modulo(unsigned long long base, 
                                  unsigned long long exp, 
                                  unsigned long long mod)
  {
          unsigned long long result = 1;
          base = base % mod; 
          
          while (exp > 0) {
                  /* If exp is odd, multiply base with result */
                  if (exp % 2 == 1) {
                          result = (result * base) % mod;
                  }
                  /* exp must be even now */
                  exp = exp / 2;
                  base = (base * base) % mod; 
          }
          return result;
  }
  ```

* **Timing Analyzing Attack:**
  In the `power_modulo` function above, notice the `if (exp % 2 == 1)` statement.
  If the bit is 1, the computer performs an extra multiplication `result = (result * base) % mod`.
  If the bit is 0, it skips it. 
  An attacker carefully measuring the time it takes the CPU
  to decrypt a message can determine whether each bit of the private key was a 1 or a 0
  based on tiny execution time differences.
  Secure cryptography requires **constant-time algorithms**
  where the code performs the exact same sequence of instructions regardless of the secret data,
  preventing these timing leaks.

## Common Pitfalls & Logic Errors

* **Infinite Loop:**

  A loop where the terminating condition is never met.
  While sometimes intentional, like a server listening for connections using `while(1)`,
  it is usually a bug caused by forgetting to update the loop counter.
  
  ```c
  /* Accidental Infinite Loop */
  int i = 0;
  while (i < 5) {
          printf("This will print forever.\n");
          /* i++ is missing! */
  }
  ```

* **Unreachable Code:**

  Instructions that exist in the source file but can never be executed under any circumstances.
  This often happens after a premature `return` or an unintentional infinite loop.
  Compilers usually issue warnings for this.

  ```c
  int check_status() {
          return 1;
          printf("This line is unreachable code.\n"); /* Never executes */
  }
  ```

* **Loop Exit Too Early:**

  This often occurs due to flawed boolean logic in the `while` condition or a misplaced `break` statement.
  It is closely related to "off-by-one" errors.

    ```c
    /* Intended to process array indices 0 through 4 */
    int i;
    for (i = 0; i < 5; i++) {
            if (i == 3) {
                    break; /* Exits too early! Index 3 and 4 are never processed. */
            }
            /* Logic... */
    }
    ```
