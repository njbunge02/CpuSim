#ifndef ALU_H
#define ALU_H

#include <string>
#include <vector>
#include <iostream>


using namespace std;

//R_TYPE INSTRUCTIONS 
//opcode	rs	rt	rd	shamt	func

//I_TYPE INSTRUCTIONS
//opcode	rs	rt	imm

//J_TYPE INSTRUCTIONS
//opcode	address


void executeALU(const vector<string> instruction);
void jTypeALU(string opcode, string address);
void iTypeALU(string opcode, string rs, string rt, string imm);
void rTypeALU(string opcode, string rs, string rt, string rd, string shamt, string funct);


#endif