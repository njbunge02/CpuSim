//change binary data into an instruction string
#include "Instruction.h"

//R_TYPE INSTRUCTIONS 
//opcode	rs	rt	rd	shamt	func

//I_TYPE INSTRUCTIONS
//opcode	rs	rt	imm

//J_TYPE INSTRUCTIONS
//opcode	address

void Instruction::convertBianryToAssembly()
{
    
    if (opCode == "000010") //j
    {
        assemblyTranslation = "j ";
        assemblyTranslation += to_string(stoi(jInstruct.address, nullptr, 2));
       

    } else if (opCode == "000100") //beq
    {
        assemblyTranslation = "beq";
        assemblyTranslation += " $";
        assemblyTranslation += to_string(stoi(iInstruct.sourceReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(iInstruct.targetReg, nullptr, 2));
        assemblyTranslation += ", ";

        if (iInstruct.imm[0] == '1') //negative
        {
            string negNum = iInstruct.imm;
            int number;
            for (int i = 0; i < negNum.size(); ++i)
            {
                if (negNum[i] == '0')
                    negNum[i] = '1';
                else
                    negNum[i] = '0';
            }
            bitset<16> bits(negNum);
            number= bits.to_ulong() + 1;

            assemblyTranslation += "-" + to_string(number);

        }else
        {
            assemblyTranslation += to_string(stoi(iInstruct.imm, nullptr, 2));
        }


    } else if (opCode == "101011") //sw
    {
        assemblyTranslation = "sw";
    }else if (opCode == "100011") //lw
    {
        assemblyTranslation = "lw";
    }else if (opCode == "001000") //addi
    {
        assemblyTranslation = "addi";
        assemblyTranslation += " $";
        assemblyTranslation += to_string(stoi(iInstruct.sourceReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(iInstruct.targetReg, nullptr, 2));
        assemblyTranslation += ", ";

        if (iInstruct.imm[0] == '1') //negative
        {
            string negNum = iInstruct.imm;
            int number;
            for (int i = 0; i < negNum.size(); ++i)
            {
                if (negNum[i] == '0')
                    negNum[i] = '1';
                else
                    negNum[i] = '0';
            }
            bitset<16> bits(negNum);
            number= bits.to_ulong() + 1;

            assemblyTranslation += "-" + to_string(number);

        }else
        {
            assemblyTranslation += to_string(stoi(iInstruct.imm, nullptr, 2));
        }

    }else if (rInstruct.func == "100000") //add
    {
        assemblyTranslation = "add";   
        assemblyTranslation += " $";
        assemblyTranslation += to_string(stoi(rInstruct.destReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.sourceReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.targetReg, nullptr, 2));
    }else if (rInstruct.func == "100010") //sub
    {
        assemblyTranslation = "sub";
        assemblyTranslation += " $";
        assemblyTranslation += to_string(stoi(rInstruct.destReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.sourceReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.targetReg, nullptr, 2));
    }else if (rInstruct.func == "100100") //and
    {
        assemblyTranslation = "and";
        assemblyTranslation += " $";
        assemblyTranslation += to_string(stoi(rInstruct.destReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.sourceReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.targetReg, nullptr, 2));
    }else if (rInstruct.func == "100101") //or
    {
        assemblyTranslation = "or"; 
        assemblyTranslation += " $";
        assemblyTranslation += to_string(stoi(rInstruct.destReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.sourceReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.targetReg, nullptr, 2));  

    }else if (rInstruct.func == "101010") //slt
    {
        assemblyTranslation = "slt"; 
        assemblyTranslation += " $";
        assemblyTranslation += to_string(stoi(rInstruct.destReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.sourceReg, nullptr, 2));
        assemblyTranslation += ", $";
        assemblyTranslation += to_string(stoi(rInstruct.targetReg, nullptr, 2));  
    }

}

void Instruction::convertBinaryToInstruction(string binaryString)
{


    opCode = binaryString.substr(0, 6);

    if (opCode == "000000") //rtype
    {
        rInstruct.sourceReg = binaryString.substr(6, 5);
        rInstruct.targetReg = binaryString.substr(11, 5);
        rInstruct.destReg = binaryString.substr(16, 5);
        rInstruct.shamt = binaryString.substr(21,5);
        rInstruct.func = binaryString.substr(26, 6);

    } else if (opCode == "000010") //jtype
    {
        jInstruct.address = binaryString.substr(6, 26);



    } else //itype
    {
        iInstruct.sourceReg = binaryString.substr(6,5);
        iInstruct.targetReg = binaryString.substr(11,5);
        iInstruct.imm = binaryString.substr(16,16);
    }

    convertBianryToAssembly();

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

