//This will read the assembler output data and store it in an array of instructions
#include "Memory.h"

void Memory::convertBinaryToInstructionList(string binaryString)
{
    assemblyCode = "";
    int numInstructions = binaryString.length() / 32;
    Instruction newInstruction;
    for (int i = 0; i < numInstructions; ++i)
    {
        newInstruction.convertBinaryToInstruction(binaryString.substr(i * 32, 32));
        
        assemblyCode += newInstruction.getAssemby();
        assemblyCode += "\n";

        instructionList.push_back(newInstruction);
        
    }
}

