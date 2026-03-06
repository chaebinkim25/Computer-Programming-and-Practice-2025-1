## linux and c program

### C Program Anatomy

- **c standard:** how do we ensure code works everywhere?
  The formal, standardized specification of the C programming language (such as C89, C99, or C11).
  It acts as a rigid rulebook that defines the exact syntax, compiler behavior,
  and standard library functions, ensuring that a program written on one operating system will
  behave identically when compiled on another system that strictly follows the same standard.

- **`main`:** where does the program start?
  The mandatory entry point of any C program. 
  When the operating system executes the compiled binary, it specifically looks for a function named main and begins executing the instructions there.

- **`int`:** what kind of data is being returned?
  A fundamental C data type representing an integer (a whole number). 
  When placed right before main, it declares to the compiler that the function will return an integer value back to the operating system upon completion.

- **`()`:** where do we put the inputs?
  Parentheses enclose the parameters (or arguments) that a function accepts. 
  For main, this dictates what command-line arguments the program can process. 
  If it takes no arguments, it is often written as (void), which is excellent practice, particularly under the C89 standard.

- **`{}`:** how do we group instructions?
  Curly braces define a "block" of code or scope. 
  The opening { and closing } immediately following main() enclose the actual sequence of C instructions that make up the body of the program.

- **`return`:** how does the program finish?
  A keyword in C used to exit the current function and pass a specific value back to the entity that called it. 
  In the context of main, it passes an exit status code back to the Linux operating system shell.

- **`0`:** what does a successful finish look like?
  The standard integer value returned to the operating system at the end of main to signal that the program executed successfully and naturally, without encountering any fatal errors.

- **`;`:** how do we end an instruction?
  The semicolon acts as the essential end-of-statement marker in C. 
  It tells the compiler exactly where one instruction finishes and the next begins, functioning much like a period at the end of an English sentence.

- **declaration:** how do we introduce a new variable?
  A mandatory statement that informs the compiler about a new variable before it is ever used.
  It defines both the variable's name and its data type (like int),
  which tells the compiler exactly how much system memory needs to be reserved for it.

- **variable name:** how do we refer to stored data?
  An identifier chosen by the programmer to represent a specific location in the computer's memory.
  It must follow strict rules (e.g., it must start with a letter or underscore, and cannot contain spaces)
  and should ideally describe the data it holds to make the code readable.
  
### Operators and Math

- **`=`:** how do we store a value?
  The assignment operator.
  It computes the value of the expression on its right side and
  stores that result into the memory location of the variable named on its left side.
  (Note: It does not check for mathematical equality, which is handled by `==`).

- **`+`:** how do we add values?
  The addition operator.
  It performs basic mathematical addition on two numeric operands, calculating their sum.

- **`-`:** how do we subtract values?
  The subtraction operator.
  It subtracts the right operand from the left operand.
  It can also be placed directly in front of a single value as a unary operator to
  denote a negative number.
  
- **`*`:** how do we multiply values?
  The multiplication operator.
  It calculates the product of two numeric operands.
  
- **`/`:** how do we divide values?
  The division operator.
  It divides the left operand by the right operand.
  Crucially in C, if both operands are integers,
  it performs integer division—meaning it entirely discards any fractional remainder and
  returns only the whole number.

- **`%`:** how do we find the remainder?
  The modulo operator.
  It divides the left integer operand by the right integer operand and returns only the remainder.
  This is highly useful for checking if a number is even or odd,
  or for wrapping values around a specific range.  
  
- **`()` in expression:** how do we control the order of math?
  Parentheses are used to group sub-expressions and
  override the default mathematical order of operations (precedence).
  The C compiler will always calculate the innermost expressions enclosed in parentheses before
  moving outward.


### The Environment & Workflow

- **linux:** what is the core environment?
  linux is the operating system kernel that manages the computer's hardware resources (CPU, memory, storage) and
  provides the fundamental environment and API (system calls) that programs rely on to run.
  
- **wsl:** how do we run Linux on Windows?
  The Windows Subsystem for Linux. 
  It is a compatibility layer that allows developers to run a genuine Linux environment—complete with 
  command-line tools, utilities, and compilers—directly on a Windows machine without 
  the heavy resource overhead of a traditional virtual machine.

- **ls:** how do we see our files?
  A fundamental command-line utility in the Linux terminal used to "list" the contents of a directory. 
  It allows you to verify that your C source files (.c) and your compiled executables are where they should be.

- **cat:** how do we quickly view code?
  A command-line tool (short for "concatenate") used to read the contents of a file and print it directly to the terminal screen. 
  It is incredibly useful for taking a quick look at a C source file without opening a full text editor.

- **code:** how do we launch our editor?
  A command-line instruction. 
  Typing code . in the terminal tells the system to open the current directory inside the Visual Studio Code editor, 
  seamlessly bridging the command line and the graphical text editor.

- **vscode:** where do we write the code?
  Visual Studio Code. 
  A lightweight, powerful source-code editor that provides features like syntax highlighting, code completion, and integrated debugging. 
  It interfaces perfectly with WSL, allowing you to edit files on the Windows side while compiling them on the Linux side.

### Compilation & Debugging

- **gcc:** how do we translate code?
  The GNU Compiler Collection. 
  It is the standard, open-source compiler used in Linux to translate human-readable C source code into machine-executable binary files through 
  a process of preprocessing, compiling, assembling, and linking.

- **gdb:** how do we find mistakes in our code?
  The GNU Debugger. 
  It is a powerful command-line tool that allows you to peek inside your program while it is executing (or exactly when it crashes). 
  You can set "breakpoints" to pause execution, step through your C code line by line, and inspect the exact values stored in your variables at any given moment.

- **json:** how do we format configuration data?
  JavaScript Object Notation.
  It is a lightweight, widely universally recognized, text-based format used for structuring data.
  It organizes information into easy-to-read "key-value" pairs and arrays,
  making it the standard way to write configuration files for modern development tools.
  
- **launch.json:** how do we tell VS Code to debug?
  A specific JSON configuration file used internally by Visual Studio Code.
  It dictates exactly how the editor should launch your debugger (like GDB),
  instructing it on which compiled executable to run, what command-line arguments to pass,
  and how to map the running binary back to your original source code.
  

















