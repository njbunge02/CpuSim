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
    bool NoMoreInstructions;

    int clockCycle;
    int pcUpdateValue;
    int pcUpdates;
 
    Instruction instructionFetch();

    public:

    CPU(){
    clockCycle = 1;
    pcUpdates = 0;
    NoMoreInstructions = false;

    }

    CPU(const string filename)
    {
        readBinaryFile(filename);
        
        Memory tempCPUMemory(instructionBinary);
        cpuMemory = tempCPUMemory;
        clockCycle = 1;
        pcUpdates = 0;
        NoMoreInstructions = false;
    
    
    }
    
    //updates instructionBinary
    int readBinaryFile(const string filename);

    string getInstrunctionSet() {return instructionBinary;}

    //runs the program
    void Run();

    //runs the next instruction
    string executeNextInstruction();

    //prints all the CPU stats
    void printCPU();
    
    void writeBack(Registers inputReg);
    
    //sets all the muxes based on the instruction
    void setMuxes(Instruction instruct);

    //updates PC
    void updatePC();

//prints all registers to terminal
    void printAllRegisters()
    {
        for (int i = 0; i < 32; ++i)
        {
            cout << "Register " + to_string(i) + ": ";
            cout << reg.regVal(i) << endl;
        }
    }

//String that displays registers for gui
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

    //String that displays stats for gui
    string getStatsString()
    {
        string outputString = "";

        outputString += "Number of ALU operations: " + to_string(aluOps) +"\n";
        outputString += "Number of memory updates: " + to_string(cpuMemory.getUpdates())+"\n";
    

        outputString += "Number of register updates: " + to_string(reg.getRegisterUpdateCount()) +"\n";
        outputString += "Number of PC updates: "+ to_string(pcUpdates) +"\n";
        outputString += "Number of cycles: " + to_string(clockCycle - 1) + "\n";
        outputString += "CPU Stats: \n";

        return outputString;
    }

//String that displays memory for gui
    string getMemoryString()
    {
        string outputString = "";

        outputString += "MEMORY\n";
      
        outputString += cpuMemory.getMemoryString();



        return outputString;
    }




  

};

#endif