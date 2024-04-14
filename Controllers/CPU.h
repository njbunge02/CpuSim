#ifndef CPU_H
#define CPU_H


#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <sstream>
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

    bool memoryAccessMux;
    bool writeBackMux;
    bool ALUMux;
    bool pcMUX;

    int clockCycle;
    int pcUpdateValue;

    Instruction instructionFetch();

    public:

    CPU(){
    clockCycle = 1;
    }

    CPU(const string filename)
    {
        readBinaryFile(filename);
        
        Memory tempCPUMemory(instructionBinary);
        cpuMemory = tempCPUMemory;
        clockCycle = 1;
    
    }
    
    //updates instructionBinary
    int readBinaryFile(const string filename);

    string getInstrunctionSet() {return instructionBinary;}

    void Run();

    string executeNextInstruction();

    //prints all the CPU stats
    void printCPU();
    
    void writeBack(Registers inputReg);
    
    //sets all the muxes based on the instruction
    void setMuxes(Instruction instruct);

    //updates PC
    void updatePC();

    void printAllRegisters()
    {
        for (int i = 0; i < 32; ++i)
        {
            cout << "Register " + to_string(i) + ": ";
            cout << reg.regVal(i) << endl;
        }
    }

    string getRegisterString()
    {
        string registerString = "";
     
        for (int i = 31; i >= 0; --i)
        {
        if (i < 10)
            registerString += "Register " + to_string(i) + ":   " + reg.regVal(i) + "\n";
        else 
            registerString += "Register " + to_string(i) + ": " + reg.regVal(i) + "\n";
        }
        registerString += "Register Contents: \n";

        return registerString;
    }

    string getStatsString()
    {
        string outputString = "";

        outputString += "Number of ALU operations: \n";
        outputString += "Number of memory updates: \n";
        outputString += "Number of register updates: \n";
        outputString += "Number of PC updates: \n";
        outputString += "Number of cycles: \n";
        outputString += "CPU Stats: \n";

        return outputString;
    }




  

};

#endif