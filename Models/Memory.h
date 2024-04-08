#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "Instruction.h"

using namespace std;

class Memory
{
    private:

    vector<Instruction> instructionList;


    public:

    void convertBinaryToInstructionList(string binaryString);

};

#endif