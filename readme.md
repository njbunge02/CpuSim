# CPU Simulator
## Nick Bunge and Damyon Olson

This project was provided to us as a way to simulate MIPS instructions. The program takes a binary file outputted by the /Assembler code, and translates the binary to instructions. These instructions are then ran through a simulation to populate registers based on the instruction it was given.

For example. If the command addi $1 $2 10 will add 10 to the value stored in register 2 and store the result in register 1.

# /Assembler
Assembler is code from project 1 that reads assembly code from a text file and outputs the assembly code in binary to a .bin file. The .bin file is in turn used by the Cpu Simulator to decode the binary file and process the instructions.

# /Controllers
Controllers contains the CPU as well as the main file.

## Main
Main is what runs the entire simulation. The binary file is read in using command line arguments and then processed into the CPU.

## CPU
The CPU is a class that acts as the brain of the simulation. It holds two functions, one for reading in the binary and another to return the binary.

### int readBinaryFile(const string filename);
This function takes in a binary file and translates the bits into strings. The result is stored in the private value `instructionBinary`

### string getInstrunctionSet()
Returns the valye saved within `instructionBinary`