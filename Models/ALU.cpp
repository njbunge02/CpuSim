#include "ALU.h"
#include "Registers.h"
//this will take an instruction string execute any ALU instruction and return its value

//R_TYPE INSTRUCTIONS 
//opcode	rs	rt	rd	shamt	func

//I_TYPE INSTRUCTIONS
//opcode	rs	rt	imm

//J_TYPE INSTRUCTIONS
//opcode	address

//PC Changers : j and beq.

// Gathers the instructions to be fed into their corresponding simulation (J-Type, R-Type or I-Type)
string executeALU(const vector<string> instruction, Registers& registers){
    if(instruction.size() == 6) {
        string opcode = instruction[0];
        string rs = instruction[1];
        string rt = instruction[2];
        string rd = instruction[3];
        string shamt = instruction[4];
        string funct = instruction[5];
        return rTypeALU(opcode, rs, rt, rd, shamt, funct, registers);
    } else if (instruction.size() == 4){
        string opcode = instruction[0];
        string rs = instruction[1];
        string rt = instruction [2];
        string immed = instruction[3];
        return iTypeALU(opcode, rs, rt, immed, registers);
    } else if (instruction.size() == 2){
        string opcode = instruction[0];
        string address = instruction[2];
        return jTypeALU(opcode, address);
    }
}

string rTypeALU(string opcode, string rs, string rt, string rd, string shamt, string funct, Registers& registers){
    if (funct == "100000"){ // add
        int source = stoi(rs, nullptr, 2);
        int target = stoi(rt, nullptr, 2);
        int destination = stoi(rd, nullptr, 2);


        int sourceVal = stoi(registers.regVal(source), nullptr, 2);
        int targetVal = stoi(registers.regVal(target), nullptr, 2);

        int result = sourceVal + targetVal;

   
        registers.pushToReg(destination, result);
         
        string outputString = "Register " + to_string(destination) + ": " + bitset<32>(result).to_string();
       return outputString;

    } else if (funct == "100010") { // sub
        int source = stoi(rs, nullptr, 2);
        int target = stoi(rt, nullptr, 2);
        int destination = stoi(rd, nullptr, 2);

        int sourceVal = stoi(registers.regVal(source), nullptr, 2);
        int targetVal = stoi(registers.regVal(target), nullptr, 2);

        int result = sourceVal - targetVal;


        registers.pushToReg(destination, result);

        string outputString = "Register " + to_string(destination) + ": " + bitset<32>(result).to_string();
       return outputString;
    } else if (funct == "100100") { // and
        int source = stoi(rs, nullptr, 2);
        int target = stoi(rt, nullptr, 2);
        int destination = stoi(rd, nullptr, 2);

        int sourceVal = stoi(registers.regVal(source), nullptr, 2);
        int targetVal = stoi(registers.regVal(target), nullptr, 2);

        int result = sourceVal & targetVal;


        registers.pushToReg(destination, result);

        string outputString = "Register " + to_string(destination) + ": " + bitset<32>(result).to_string();
       return outputString;
    } else if (funct == "100101"){ // or
        int source = stoi(rs, nullptr, 2);
        int target = stoi(rt, nullptr, 2);
        int destination = stoi(rd, nullptr, 2);

        int sourceVal = stoi(registers.regVal(source), nullptr, 2);
        int targetVal = stoi(registers.regVal(target), nullptr, 2);

        int result = sourceVal | targetVal;


        registers.pushToReg(destination, result);

        string outputString = "Register " + to_string(destination) + ": " + bitset<32>(result).to_string();
       return outputString;
    } else if( funct == "101010"){ //slt
        int source = stoi(rs, nullptr, 2);
        int target = stoi(rt, nullptr, 2);
        int destination = stoi(rd, nullptr, 2);

        int sourceVal = stoi(registers.regVal(source), nullptr, 2);
        int targetVal = stoi(registers.regVal(target), nullptr, 2);
        int result = 0;

        if (sourceVal < targetVal) {
            result = 1;
        }

        registers.pushToReg(destination, result);

     string outputString = "Register " + to_string(destination) + ": " + bitset<32>(result).to_string();
       return outputString;
    }
}

string iTypeALU(string opcode, string rs, string rt, string imm, Registers& registers){
    if (opcode == "001000"){ //addi 
        int source = stoi(rs, nullptr, 2);
        int target = stoi(rt, nullptr, 2);
        int immediate = stoi(imm, nullptr, 2);

        int targetVal = stoi(registers.regVal(target), nullptr, 2);
        int immVal = immediate;

        int result = targetVal + immVal;

        registers.pushToReg(source, result);

        string outputString = "Register " + to_string(source) + ": " + bitset<32>(result).to_string();
        return outputString;
    
    } else if (opcode == "000100"){ // beq (Updates PC)
    //I_TYPE INSTRUCTIONS
    //opcode	rs	rt	imm
    int source = stoi(rs, nullptr, 2);
    int target = stoi(rt, nullptr, 2);
    int immediate = stoi(imm, nullptr, 2);

    int val2 = stoi(registers.regVal(source), nullptr, 2);
    int val1 = stoi(registers.regVal(target), nullptr, 2);

    if (val1 == val2)
    {
        return "1";
    } else
    {
        return "0";
    }

    } else if (opcode == "101011") { //sw
    
    } else if (opcode == "100011") { //lw
    
    }
}

string jTypeALU(string opcode, string address){
    // j is the only J-Type that we have

    // This needs to set PC to the address (I believe)
}