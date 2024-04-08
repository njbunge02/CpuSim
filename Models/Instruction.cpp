//change binary data into an instruction string
#include "Instruction.h"

//R_TYPE INSTRUCTIONS 
//opcode	rs	rt	rd	shamt	func

//I_TYPE INSTRUCTIONS
//opcode	rs	rt	imm

//J_TYPE INSTRUCTIONS
//opcode	address

void Instruction::convertBinaryToInstruction(string binaryString)
{

}

vector<string> Instruction::getArguments()
{

    vector<string> arg;
    
    if (opCode == "000000") //rtype
    {
        arg.push_back(opCode);
        arg.push_back(rInstruct.sourceReg);
        arg.push_back(rInstruct.targetReg);
        arg.push_back(rInstruct.destReg);
        arg.push_back(rInstruct.shamt);
        arg.push_back(rInstruct.func);

    } else if (opCode == "000010") //jType
    {
        arg.push_back(opCode);
        arg.push_back(jInstruct.address);
    }else
    {
        arg.push_back(opCode);
        arg.push_back(iInstruct.sourceReg);
        arg.push_back(iInstruct.targetReg);
        arg.push_back(iInstruct.imm);
    }

    return arg;
    
}