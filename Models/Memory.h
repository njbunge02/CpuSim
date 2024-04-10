#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "Instruction.h"

using namespace std;

class Memory
{
    private:

    vector<Instruction> instructionList;
    string assemblyCode;

    int pc;


    public:

    Memory(){pc = 0;}

    Memory(string binaryString)
    {
        convertBinaryToInstructionList(binaryString);
        pc = 0;
    }

    void generateAssemblyCode();

    string getAssemblyCode(){return assemblyCode;}
    

    //converts a string of 1's and 0's into a list of Instructions
    void convertBinaryToInstructionList(string binaryString);
    
    Instruction getInstruction()
    {
        if (pc < instructionList.size())
        {
            pc += 1;
            return instructionList[pc - 1];
        } 
    }

    void setPC (int input)
    {
        pc = input;
    }

    int getPC()
    {return pc;}

};

#endif