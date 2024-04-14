#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Instruction.h"

using namespace std;

class Memory
{
    private:

    vector<Instruction> instructionList;    //list of instructions
    string assemblyCode;    //the entire assembly code

    unordered_map<string, string> hardDrive;

    int updates;
    int accesses;


    int pc; //the program counter


    public:

    Memory(){
    pc = 0;
    updates = 0;
    accesses = 0;}

    Memory(string binaryString)
    {
        convertBinaryToInstructionList(binaryString);
        pc = 0;
         updates = 0;
    accesses = 0;
    }

    
    int getUpdates()
    {return updates;}

    int getAccesses()
    {
        return accesses;
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
        updates += 1;
        pc += input;
    }

    //returns program counter
    int getPC()
    {return pc;}


    string retrieveMemory(string location)
    {
        
        accesses += 1;
        return hardDrive[location];
    }

    void putInMemory(string location, string contents)
    {
     
        hardDrive[location] = contents;
    }

  
};

#endif