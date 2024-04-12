#include "ALU.h"
//this will take an instruction string execute any ALU instruction and return its value

//R_TYPE INSTRUCTIONS 
//opcode	rs	rt	rd	shamt	func

//I_TYPE INSTRUCTIONS
//opcode	rs	rt	imm

//J_TYPE INSTRUCTIONS
//opcode	address

//PC Changers : j and beq.

// Gathers the instructions to be fed into their corresponding simulation (J-Type, R-Type or I-Type)
void executeALU(const vector<string> instruction){
    if(instruction.size() == 6) {
        string opcode = instruction[0];
        string rs = instruction[1];
        string rt = instruction[2];
        string rd = instruction[3];
        string shamt = instruction[4];
        string funct = instruction[5];
        rTypeALU(opcode, rs, rt, rd, shamt, funct);
    } else if (instruction.size() == 4){
        string opcode = instruction[0];
        string rs = instruction[1];
        string rt = instruction [2];
        string immed = instruction[3];
        iTypeALU(opcode, rs, rt, immed);
    } else if (instruction.size() == 2){
        string opcode = instruction[0];
        string address = instruction[2];
        jTypeALU(opcode, address);
    }
}

void rTypeALU(string opcode, string rs, string rt, string rd, string shamt, string funct){
    if (funct == "100000"){ // add
       
    } else if (funct == "100010") { // sub

    } else if (funct == "100100") { // and

    } else if (funct == "100101"){ // or
    
    } else if( funct == "101010"){ //slt
    
    }
}

void iTypeALU(string opcode, string rs, string rt, string imm){
    if (opcode == "001000"){ //addi 
    
    } else if (opcode == "000100"){ // beq

    } else if (opcode == "101011") { //sw
    
    } else if (opcode == "100011") { //lw
    
    }
}

void jTypeALU(string opcode, string address){
    // j is the only J-Type that we have

    // This needs to set PC to the address (I believe)
}