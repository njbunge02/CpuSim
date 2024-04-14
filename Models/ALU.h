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

string executeALU(const vector<string> instruction, Registers& registers);
string jTypeALU(string address);
string iTypeALU(string opcode, string rs, string rt, string imm, Registers& registers);
string rTypeALU(string opcode, string rs, string rt, string rd, string shamt, string funct, Registers& registers);


#endif