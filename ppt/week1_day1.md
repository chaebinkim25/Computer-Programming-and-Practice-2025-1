## the system and software (the user's view)

We begin with the computer as a complete, functioning machine and how it starts up and organizes information.

- **computer:** what does a computer do?
  It takes input data, processes it according to a predefined set of rules (programs), and produces output.
  Fundamentally, it is an automated data manipulator.

- **program:** how are the applications and their data stored?
  Under the Von Neumann architecture, both instructions and data are stored together as sequences of bytes in the same memory space (RAM).

- **random access memory:** where these active instructions and data held?
  RAM acts as the computer's high-speed working workspace.
  The operating system, active programs, and the data they are currently manipulating are loaded here from
  slower, long-term storage drives.

- **operating system:** what happens when we start the computer?
  When power flows, the hardware initializes and searches the storage drive for a bootloader.
  The bootloader loads the Operating System kernel into RAM and passes control to it,
  allowing the OS to manage the hardware and start your applications.

- **read only memory:** where are the startup instructions stored before the OS loads?
  In a specialized chip on the motherboard (historically ROM, now typically Flash memory like EEPROM).
  It contains the system firmware (BIOS or UEFI) that tells the CPU how to wake up.

## the language of the machine (the logical view)

Peeling back the software layer, we look at the actual language the software uses to tell the hardware what to do.

- **instruction:** how do we represent commands to the hardware?
  As a highly structured sequence of bits known as machine code.
  A single instruction contains the opcode and the operands formatted in a specific way that the CPU architecture is hardwired to understand.
  
- **operator:** how do we select how to process data?
  Through an "opcode" (operation code).
  This is a specific binary pattern within an instruction that the CPU's Control Unit decodes
  to determine which physical circuits to activate (e.g., telling the ALU to "add" instead of "multiply").

- **operand:** how do we select which data to process?
  The instruction also contains fields specifying the locations of the data.
  Operands can be addresses pointing to specific registers, memory locations in RAM,
  or direct numerical values embedded right in the instruction.

- **program counter:** after executing an instruction, which intruction should be executed next?
  A special register called the Program Counter (PC) holds the memory address of the next instruction.
  It automatically increments after an instruction is fetched, unless a "jump" instruction alters the flow.

- **bit:** how is all of these instructions and data fundamentally represented??
  Through binary digits (0s and 1s).
  Logically, these are states of truth;
  physically, they are represented by the presence or absence of electrical voltage within a circuit.

## the processing core (the microarchitecture view)

Moving from the instructions to the physical engine that reads and executes them.

- **central processing unit:** which part of computer executes instrucionts?
  The CPU contains the calculating unit (*Arithmetic Logic Unit*), fast but small memory (*register*),
  and control unit (*instruction decoder*).
  It is responsible for the fetch-decode-execute-writeback cycle of program instructions.

- **operation:** how is the data physically processed?
  By passing electronic signals through logic gates (AND, OR, NOT) built from transistors.
  These gates are arranged into complex circuits within the CPU to perform
  addition, subtraction, and bitwise operations requested by the opcode.

- **memory:** how is data stored momentarily during these operations?
  Using bistable circuits (like flip-flops) for incredibly fast, temporary storage inside the CPU (registers),
  or microscopic capacitors and transistors for the main system memory (RAM).

- **flipflop:** how is a single bit of data retained?
  It is a fundamental digital memory circuit with two stable states (0 or 1),
  created by routing the outputs of logic gates back into their own inputs.
  This feedback loop "latches" the electrical signal in place,
  allowing it to continuously hold a binary value until a clock signal triggers it to capture new data,
  making it the essential building block of CPU registers.
  
- **clock:** how to update the stored data?
  A quartz oscillator generates a continuous, rhythmic electrical pulse called the clock signal.
  This acts like a metronome, synchronizing the flow of data through the processor and
  dictating exactly when circuits should read or update their state.
  
## the physical construction (the macro hardware view)

Stepping outside the CPU core, we look at how the physical components of the machine are housed and connected.
  
- **package:** what do we see when we see each parts?
  The physical casing—often black plastic, ceramic, or a metal heat-spreader.
  This casing protects the microscopic, fragile silicon chip inside and provides
  the macroscopic metallic pins or pads needed to connect it to the motherboard.

- **mother board:** what constitutes the real computer?
  The main printed circuit board provides the physical sockets and electrical pathways that connect
  the CPU, memory, storage, and peripheral devices.
  
- **printed circuit board:** how physicaly mother board is fabricated?
  It is made of alternating layers of non-conductive fiberglass and conductive copper foil.
  The copper is chemically etched away using photosensitive masks to leave only
  the incredibly fine, precisely routed electrical traces

## the micro-world and physics (the nano view)

Finally, we open up the chip packages to look at the microscopic design and the fundamental physics of the materials used to build them.

- **integrated chip:** what is inside the package?
  a silicon chip: a tiny, flat piece of semiconductor material containing
  millions or billions of microscopic electronic components intricately wired together.
  
- **integrated circuit design:** how integrated circuit is designed?
  Using Hardware Description Languages.
  Digital hardware engineers write code that describes the logic and behavior of the chip,
  rather than drawing physical diagrams of transistors.
  
- **digital integrated circuit:** how much integrated circuit design for computer is automated?
  Electronic Design Automation software translates the human-written HDL code into a physical layout of logic gates,
  optimizing the electrical paths and routing the billions of microscopic wires automatically.

- **gate:** how semiconductor is used for logic operation?
  By arranging the electronic switches properly, output bit can be manipulated to accept certain input bits.  

- **semiconductor fabrication:** how integrated circuit is fabricated?
  Through a process called photolithography.
  Light is shone through intricate masks onto photosensitive chemicals coating a silicon wafer.
  This process is repeated dozens of times to etch patterns and deposit materials layer by microscopic layer.
    
- **semiconductor:** what constitutes integrated circuit?
  Materials, primarily silicon, whose electrical conductivity falls between that of a conductor and an insulator.
  By adding impurities and applying voltage, semiconductors can be manipulated to act as
  microscopic electronic switches.
