## The Mechanics of Iteration

- **loop:** how do we repeat instructions automatically?
  A fundamental programming structure that executes a specific block of code multiple times.
  It drastically reduces manual repetition, keeps code clean,
  and allows the program to process large amounts of data efficiently.
  
- **controlling expression:** how does the loop know when to stop?
  A logical test evaluating to true meaning non-zero or false meaning zero that acts as the gatekeeper.
  As long as this expression evaluates to true, the loop continues;
  the precise moment it evaluates to false, the loop terminates.
  
- **iteration statement `for`:** how do we write a strictly controlled, counting loop?
  A highly structured loop designed specifically for situations
  where you know exactly how many times you want an action to repeat.
  It elegantly packages the start, the test, and the step into a single, highly readable line.
  
- **expression-1 in `for`:** how do we set the starting line?
  The initialization phase.
  It executes exactly once before the loop ever begins.
  It is typically used to assign a starting value to the loop variable.
  
- **expression-2 in `for`:** how do we define the finish line?
  The condition phase.
  Evaluated before every single cycle.
  If it is true, the loop body runs.
  If false, the loop terminates immediately, and the program moves on.
  
- **expression-3 in `for`:** how do we take a step forward?
  The update phase.
  Executed automatically at the very end of each successful cycle.
  It is typically used to increment or decrement the loop variable,
  driving it closer to the finish line condition.

- **loop body in `for`:** what exactly is being repeated?
  The instruction executed during each cycle.
  For safe, defensive programming,
  this should always be a compound statement tightly enclosed in curly braces `{}`,
  even if you are only repeating a single line of code.

- **loop variable:** how do we track our progress?
  A dedicated variable, traditionally named `i`, `j`, or `k`, used specifically to count the iterations.
  Under classic strict C standards,
  the declaration of this variable's type must happen at the top of the function block,
  separate from the `for` statement itself.

## Loop Control & Data Manipulation

- **compound assignment `+=`:** how do we add to an existing value efficiently?
  A shorthand operator that adds the right-side value directly to the left-side variable
  and updates it in one step, e.g., `total += 5` does the exact same work as `total = total + 5`.
  
- **compound assignment `-=`:** how do we subtract from an existing value efficiently?
  A shorthand operator that subtracts the right-side value from the left-side variable,
  updating the variable in place.

- **infinite loop and `for`:** what happens if the finish line is never reached?
  A scenario where the controlling expression never evaluates to false.
  While often a critical logical error,
  it can also be an intentional design choice for persistent system processes.
  In C, omitting all three expressions in a `for` loop—written exactly as `for(;;)`—is the standard,
  valid way to create an intentional infinite loop.
  
- **nested loop:** how do we iterate in multiple dimensions?
  Placing one loop entirely inside the body of another.
  For every single step of the "outer" loop, the "inner" loop must run completely from start to finish.
  This is essential for traversing 2D grids, matrices, or tables.
  
- **spaghetti code and `for`:** how do loops prevent tangled logic?
  By strictly encapsulating repetition within predictable structures.
  Relying on properly formatted `for` loops rather than using legacy jump statements `goto`
  to loop backward ensures the program flow remains linear, readable, and mathematically provable.

## Classic Loop-Based Algorithms

- **brute force:** how do we solve problems by checking everything?
  A straightforward algorithm design that relies on sheer computing power
  and loops to systematically try every single possible combination
  or answer until the correct one is verified.
  
- **decimal to binary conversion:** how do we translate human math to machine language?
  A classic algorithm that uses a loop alongside integer division `/ 2` and modulo `% 2`
  to repeatedly extract the remainders, systematically building the 1s and 0s that make up a base-2 number.

- **fibonacci numbers:** how do we calculate a sequence built on its past?
  A mathematical sequence where each number is the sum of the two preceding ones.
  Calculating it iteratively requires a loop and the careful use of temporary variables
  to continuously shift the "previous" values forward safely without overwriting them prematurely.

  
