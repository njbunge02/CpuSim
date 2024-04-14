#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "Instruction.h"

using namespace std;

class Memory
{
    private:

    vector<Instruction> instructionList;    //list of instructions
    string assemblyCode;    //the entire assembly code

    int pc; //the program counter


    public:

    Memory(){pc = 0;}

    Memory(string binaryString)
    {
        convertBinaryToInstructionList(binaryString);
        pc = 0;
    }

    

    //returns the assemblyCode
    string getAssemblyCode(){return assemblyCode;}
    

    //converts a string of 1's and 0's into a list of Instructions
    void convertBinaryToInstructionList(string binaryString);
    
    //returns the current instruction the pc is on
    Instruction getInstruction()
    {
        if (pc < instructionList.size())
        {
            pc += 1;
            return instructionList[pc - 1];
        } 
    }

    //sets program counter
    void setPC (int input)
    {
        pc = input;
    }

    //updates pc
    void updatePC(int input)
    {
        pc += input;
    }

    //returns program counter
    int getPC()
    {return pc;}

};

#endif