#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

#define REGISTER_COUNT 32
using namespace std;


class Registers
{
    private:
    
    vector<bitset<32> > registers;

    public:

    Registers()
    {
        string bits32(32, '0');
 
     
        for (int i = 0; i < REGISTER_COUNT; ++i)
        {
            bitset<32> stringToBitset(bits32);
            registers.push_back(stringToBitset);
        }
    }

    void pushToReg(int dest, int value){
        
        
        bitset<32> stringToBitset(value);
   
        registers[dest] = stringToBitset;

    }

    string regVal(int regNum) { return registers[regNum].to_string(); }

};

#endif