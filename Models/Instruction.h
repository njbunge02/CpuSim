#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//R_TYPE INSTRUCTIONS 
//opcode	rs	rt	rd	shamt	func

//I_TYPE INSTRUCTIONS
//opcode	rs	rt	imm

//J_TYPE INSTRUCTIONS
//opcode	address

struct R_TYPE
{
    string sourceReg;
    string targetReg;
    string destReg;
    string shamt;
    string func;
};


struct I_TYPE
{
    string sourceReg;
    string targetReg;
    string imm;
};

struct J_TYPE
{
    string address;
};

class Instruction
{
    private:
   
    string opCode;

    R_TYPE rInstruct;
    I_TYPE iInstruct;
    J_TYPE jInstruct;

    string assemblyTranslation;

    void convertBianryToAssembly();

    public:
    
    Instruction(){}

    Instruction(string binaryString)
    {convertBinaryToInstruction(binaryString);}

    void convertBinaryToInstruction(string binaryString);

    vector<string> getArguments();
    

    string getopCode(){return opCode;}

    string getAssemby()
    {
        return assemblyTranslation;
    }

};

#endif