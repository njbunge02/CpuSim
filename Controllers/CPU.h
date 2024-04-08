#ifndef CPU_H
#define CPU_H


#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

class CPU
{

    private:
    
    string binaryInstruction;


    public:

    CPU()
    {
        binaryInstruction = "";
    }
    
    int readBinaryFile(const string filename);

};

#endif