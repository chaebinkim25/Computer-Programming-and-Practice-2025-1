## Program Design & Syntax

- **top-down approach:** how do we design complex systems?
  A problem-solving method where you start with the big picture (like the main function) and
  break it down into smaller, manageable sub-components or functions until the fundamental details are reached.
 
- **bottom-up approach:** how do we build from the ground up?
  A method where you write the foundational, low-level details and utility functions first,
  gradually combining them to form more complex systems and eventually the complete program.
  
- **language syntax:** how do we know if code is valid?
  The strict set of spelling and grammar rules defined by the C standard.
  It dictates exactly how characters, symbols, and
  keywords must be arranged to form a valid program that the compiler can parse.
  
- **literal:** how do we represent raw, fixed data?
  A value typed directly into the source code that cannot change during execution.
  Examples include the integer `42`, the character `'A'`, or the string `"Hello"`.

- **function definition:** how do we build reusable commands?
  The complete specification of a function, including its return type, name, parameters, and
  the curly-brace-enclosed block of executable statements that dictate its exact behavior.

- **declaration:** how do we introduce identifiers?
  A construct that introduces variable names, function signatures,
  and their types to the compiler before they are used, telling the system how to interpret them and
  how much memory to reserve.

## Statements & Control Flow

- **statement:** how do we execute an action?
  A complete, standalone instruction executed by the program in sequence.
  It dictates an action, a decision, or a change in the program's flow.
  
- **expression-statement:** how do we trigger an evaluation?
  An expression (like a mathematical calculation, an assignment, or a function call) followed immediately by
  a semicolon `;`. The program evaluates the expression, applies any side effects (like updating memory), and
  discards the final calculated value.
  
- **null-statement:** how do we do absolutely nothing?
  A solitary semicolon `;` with no preceding expression.
  It is used when the C syntax strictly requires a statement (like in a loop body),
  but the program logic requires no actual action to be taken.

- **compound-statement:** how do we group multiple commands?
  A sequence of statements tightly enclosed in curly braces `{}`.
  It allows you to treat multiple instructions as a single, unified block.
  
- **jump-statements:** how do we force the flow of control to move?
  Commands that unconditionally transfer program execution to another specific point.
  In C, this includes `return` (to leave a function), `break`, `continue`, and `goto`.
  
- **selection-statement - `if`:** how do we execute code conditionally?
  A control structure that evaluates a condition.
  If the condition evaluates to true (a non-zero value), the attached statement or block is executed.
  If false (zero), it is skipped.

- **selection-statement - `else`:** how do we handle the "otherwise" scenario?
  Attached to an `if` statement, it provides an alternative block of code that is guaranteed to
  execute only when the preceding `if` condition evaluates to false (zero).
  
- **selection-statement - association of `else`:** how do we resolve ambiguity in nested conditions?
  The strict rule dictating that an `else` is always paired with the closest preceding if
  that does not already have an `else`, unless curly braces `{}` are used to explicitly change the grouping.
  This solves the classic compiler parsing issue known as the "dangling else" problem.

## Logic & Comparison Expressions

- **unary-expression - `!`:** how do we logically invert a truth value?
  The logical NOT operator.
  Placed before an operand, it yields `1` (true) if the operand is `0` (false), and
  yields `0` (false) if the operand is non-zero (true).
  
- **relational-expression - `<`:** how do we check if something is strictly smaller?
  The less-than operator.
  It evaluates to `1` (true) if the left operand is strictly less than the right operand, and
  `0` (false) otherwise.
  
- **relational-expression - `>`:** how do we check if something is strictly larger?
  The greater-than operator.
  It evaluates to `1` (true) if the left operand is strictly greater than the right operand, and
  `0` (false) otherwise.
  
- **relational-expression - `<=`:** how do we check if something is smaller or equal?
  The less-than-or-equal-to operator.
  It evaluates to `1` (true) if the left operand is less than or exactly equal to the right operand.
  
- **relational-expression - `>=`:** how do we check if something is larger or equal?
  The greater-than-or-equal-to operator.
  It evaluates to `1` (true) if the left operand is greater than or exactly equal to the right operand.

- **equality-expression - `==`:** how do we check for exact equivalence?
  The equal-to operator.
  It evaluates to `1` (true) if both operands hold the exact same value, and `0` (false) otherwise.
  Crucially, this is a comparison, unlike the single `=` which stores a value.
  
- **equality-expression - `!=`:** how do we check for inequality?
  The not-equal-to operator.
  It evaluates to `1` (true) if the operands have different values, and
  `0` (false) if they are exactly the same.

## Lexical Elements (The Building Blocks)

- **token:** how does the compiler read our code?
  The smallest independent unit of meaning in a C program.
  Just as a sentence is broken down into words and punctuation, the compiler's first job
  (lexical analysis) is to scan your code and chop the text into a stream of discrete tokens so it can
  begin to understand the structure.

- **keyword:** what words are strictly reserved?
  A built-in token with a predefined, unalterable meaning in the C standard (such as int, return, or if).
  Because the compiler relies on these specific words to dictate the core rules and flow of the program,
  you are strictly forbidden from using them as your own names for anything else.
  (In the classic C89 standard, there are exactly 32 of these).

- **identifier:** how do we name our own creations?
  A token representing a unique name created by the programmer to label variables, functions, arrays, or
  other user-defined items.
  They must follow strict naming conventions (e.g., starting with a letter or underscore, no spaces) and
  serve as the human-readable tags for your program's memory locations and routines.
  
- **constant:** how do we represent fixed, raw data?
  A token representing a literal, unchangeable value typed directly into the source code
  (like the integer `42`, the character `'A'`, or the floating-point number `3.14`).
  Unlike variables, these values are baked directly into the compiled program and
  cannot be modified while the program is running.

