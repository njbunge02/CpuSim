#include "../Models/Memory.h"
#include "../Controllers/CPU.h"

// Test function. Can be removed later.
void printAssembly(Memory testMem){
    cout << testMem.getAssemblyCode() << endl;
}

void printBinary(CPU cpuSim){
    cout << cpuSim.getInstrunctionSet() << endl;
}