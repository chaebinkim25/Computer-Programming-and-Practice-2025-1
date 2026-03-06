
## Structural Foundations

- **function definition:** how do we build reusable commands?
  The complete specification of a function.
  It includes the return type, the function's name, its parameters,
  and the actual curly-brace-enclosed block of code (the body) that dictates exactly what the function does. 

- **object definition:** how do we physically allocate variables?
  In the C standard, an "object" refers to a region of data storage (memory).
  Defining it means telling the compiler to actually carve out the memory space for a variable and,
  optionally, giving it a starting value.

## Primary & Unary Expressions

- **primary-expression - identifier:** how do we use a name in math?
  The simplest form of an expression, consisting purely of a variable's name.
  When the program runs,
  it evaluates this identifier by fetching the value currently stored in that specific memory location.

- **primary-expression - constant:** how do we use hardcoded values?
  A fixed, unchangeable value directly typed into the source code, such as `42`, `3.14`, or `'A'`.
  
- **primary-expression - `(`expression`)`:** how do we force priority?
  An expression wrapped in parentheses.
  It forces the compiler to treat the contents as a single, primary expression,
  guaranteeing that the operations inside are calculated before interacting with the surrounding code.
  
- **unary-expression - unary-operator `+`:** how do we explicitly state positive?
  Placed directly in front of a single value, it yields the value itself.
  Numbers are positive by default, so this is mostly used for visual symmetry in your code.
  
- **unary-expression - unary-operator `-`:** how do we negate a value?
  Placed directly in front of a single value,
  it mathematically flips the sign—turning a positive number into a negative one,
  or a negative into a positive.

## Binary Expressions

- **multiplicative-expression - `*`:** how do we multiply?
  The binary operator used to compute the product of two values.
  
- **multiplicative-expression - /:** how do we divide?
  The binary operator used to find the quotient.
  (Remember: if both sides are integers, C drops the decimal remainder entirely).

- **multiplicative-expression - %:** how do we get the remainder?
  The binary operator that divides the left integer by the right integer and
  evaluates only to the leftover remainder.
  
- **additive-expression - +:** how do we add?
  The binary operator used to calculate the sum of two values.
  
- **additive-expression - -:** how do we subtract?
  The binary operator used to find the difference between the left and right values.
  
- **assignment-expression: =:** how do we write to memory?
  Evaluates the math or expression on its right side and
  stores the final result into the memory location designated by the identifier on its left side.

## Statements & Control Flow

- **statement:** how do we issue a command?
  A complete, standalone instruction executed by the program in sequence.
  It dictates an action, a decision, or a change in the program's flow.

- **expression-statement:** how do we turn math into a command? 
  Any expression (like a math calculation, an assignment, or a function call) followed immediately by
  a semicolon `;`.
  It evaluates the expression and is usually executed for its "side effects"
  (like modifying a variable in memory).
  
- **selection-statement - if:** how do we make decisions?
  Evaluates a specific condition.
  If the condition is mathematically true (non-zero), it executes the attached statement.
  If false (zero), it skips that code entirely.
  
- **jump-statement - return:** how do we leave a function?
  Instantly stops the execution of the current function and transfers control (and a specific value)
  back to the exact point in the code where the function was originally called.
  
- **compound-statement:** how do we group multiple commands?
  A sequence of statements tightly enclosed in curly braces {}.
  It allows you to treat multiple instructions as a single, unified block,
  which is essential for things like if statements or function bodies.
