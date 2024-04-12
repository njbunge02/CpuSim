#ifndef CONSOLE_H
#define CONSOLE_H

#include "../Models/Memory.h"
#include "../Controllers/CPU.h"

void printAssembly(Memory testMem);
void printBinary(CPU cpuSim);
//void printRegisters(); -- Will print out the registers as the instructions are fed in

#endif