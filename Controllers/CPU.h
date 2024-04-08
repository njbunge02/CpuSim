#ifndef CPU_H
#define CPU_H


#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "Memory.h"

using namespace std;

class CPU
{

    private:
    
    string instructionBinary;
    //Memory


    public:

    CPU(){}
    
    int readBinaryFile(const string filename);

    string getInstrunctionSet() {return instructionBinary;}


};

#endif