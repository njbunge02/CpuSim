# CPU Simulator
## Nick Bunge and Damyon Olson

This project was provided to us as a way to simulate MIPS instructions. The program takes a binary file outputted by the /Assembler code, and translates the binary to instructions. These instructions are then ran through a simulation to populate registers based on the instruction it was given.

**THIS PROGRAM RUNS ON THE SOC MACHINES**

For example the command "addi $1, $2, 10" will add 10 to the value stored in register 2 and store the result in register 1.

To run the program, use `make` and then `make run`.

To update the file:
    In the `Assembler` directory open the `makefile`. Insert what ever testcase you want to run in this command: `./$(PROGRAM) {testCase}.s output.bin`. While still in the `Assembler` directory, run `make clean`, then `make`, then `make run`. This will create the correct .bin file used for the simulator. Next run `cd ..` to go to the main directory. Run `make clean`, then `make`, then `make run` to run the command. 

# /Assembler
Assembler is code from project 1 that reads assembly code from a text file and outputs the assembly code in binary to a .bin file. The .bin file is in turn used by the Cpu Simulator to decode the binary file and process the instructions.

# /Controllers
Controllers contains the CPU as well as the main file. These do all the interactions between all of the models and the views.

## Main
Main is what starts the GUI window in the view. It also initializes the main CPU controller for the whole program.

## CPU
The CPU is a class that acts as the brain of the simulation. It holds two functions, one for reading in the binary and another to return the binary.

### int readBinaryFile(const string filename);
This function takes in a binary file and translates the bits into strings. The result is stored in the private value `instructionBinary`

### string getInstrunctionSet()
Returns the valye saved within `instructionBinary`

# Models
## ALU
ALU calculates J-Type, I-Type and R-Type instructions.
### executeALU
Execute ALU takes in binary and determines whether the binary string is a J-Type, I-Type or R-Type instruction and then execute the function accordingly.
### rTypeALU
rTypeALU determines if the binary was an add, sub, and, or, or slt function. It then calculates the result accordingly, sets the register, and returns an outputString.
### iTypeALU
iTypeALU determines if the binary was an addi, beq, sw, or lw operation. It then calculates the results based on how each operation works, and returns an output string.
### jTypeALU
Executes the jump function based on how the operation is supposed to work and returns an output string.
## Instruction
The instruction class helps with decoding instructions as they are sent to the PC. It includes a few different helper functions, and helps the user determine if the instruction is R, I, or J type.
### convertBinaryToAssembly
This function converts the binary string into assembly language for reference in the overall output of the program.
### convertBinaryToInstruction
Converts a binary string into its instruction format to be handled within the CPU. The formatted instruction allows the simulation to easily understand which type of instruction it is.
### getBinaryString
Returns a binary string based on the type of instruction.
### decodeInstruction
Breaks down the instruction into a readable binary vector to be used later in the CPU.
## Memory
The memory class is in place to help store memory, as well as update the PC, accesses, and updates to the memory. There are a few helper functions in place
### getUpdates
Returns the amount of updates to Memory
### getAccesses
Returns the amount of times memory was accessed
### getAssemblyCode
Returns assembly code
### convertBinaryToInstructionList
Creates a list of instructions to be used by the PC
### getInstruction
Updates PC and returns the instruction requested by the CPU by checking the current PC.
### setPC
Sets the PC to the provided input
### updatePC
Adds input to the PC
### getPC
Returns the value of PC
### retrieveMemory
Gathers memory based on its location in the hard drive
### putInMemory
Inserts memory into the hard drive based on the location provided.
## Registers
The register class holds helps organize the registers and their values that will be accessed during the execution of the simulation.
### pushToReg
Pushes a value into the registers based on a destination fed in by the program.
### regVal
Returns the value of a register based on the number corresponding to that register
### getRegisterUpdateCount
Returns the number of updates that were made to the register
# Views
Contains the GUI view used for the program
## GUI
The GUI helps us create a GUI that the user can interract with.