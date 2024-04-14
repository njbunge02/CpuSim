#ifndef CPU_H
#define CPU_H


#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "../Models/Memory.h"
#include "../Models/Registers.h"
#include "../Models/Instruction.h"
#include "../Models/ALU.h"

using namespace std;

class CPU
{

    private:
    
    string instructionBinary;
    Memory cpuMemory;
    Registers reg;

    Instruction instructionFetch();

    public:

    CPU(){}

    CPU(const string filename)
    {
        readBinaryFile(filename);
        
        Memory tempCPUMemory(instructionBinary);
        cpuMemory = tempCPUMemory;
    
    }
    
    //updates instructionBinary
    int readBinaryFile(const string filename);

    string getInstrunctionSet() {return instructionBinary;}

    void Run();

    void executeNextInstruction();

    //prints all the CPU stats
    void printCPU();
    
    void writeBack(Registers inputReg);

  

};

#endif