#ifndef ALU_H
#define ALU_H

#include <string>
#include <vector>
#include <iostream>

#include "Registers.h"


using namespace std;

//R_TYPE INSTRUCTIONS 
//opcode	rs	rt	rd	shamt	func

//I_TYPE INSTRUCTIONS
//opcode	rs	rt	imm

//J_TYPE INSTRUCTIONS
//opcode	address



//counts the amount of alu operations
extern int aluOps;

//determines what kind of instruction type is in and then executes one of the functions below
string executeALU(const vector<string> instruction, Registers& registers);

//runs if its a j_type instruction
string jTypeALU(string address);
//runs if its a i_type instruction
string iTypeALU(string opcode, string rs, string rt, string imm, Registers& registers);
//runs if its a r_type instruction
string rTypeALU(string opcode, string rs, string rt, string rd, string shamt, string funct, Registers& registers);


#endif