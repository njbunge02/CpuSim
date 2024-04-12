#include "../Models/ALU.h"
#include "CPU.h"

int CPU::readBinaryFile(const string filename) {
        
   ifstream file(filename, ios::binary); // Open the file

    if (!file.is_open()) { // Check if the file is opened successfully
        cerr << "Error: Unable to open the file " << filename << endl;
        return 1; // Exit with error code 1
    }

  
    //seperates it into instructions
    char byte;
    int count = 0;
    while (file.read(&byte, 1)) {
        bitset<8> bits(byte); 

        count += 8;
        instructionBinary += bits.to_string();
    
        
    }

    file.close();

    return 0;
 }


 void CPU::Run()
 {

 }



 void CPU::executeNextInstruction()
 {
    cout << "Clock cycle: " << "1" << endl;
    cout << "Instruction Fetch" << endl;
    Instruction cpuInstruction = instructionFetch();
    cout << cpuInstruction.getBinaryString() << endl;
    cout << cpuInstruction.getAssemby() << endl;
    vector<string> instruction = cpuInstruction.decodeInstruction();
    cout << instruction.size() << endl;
    for (int i = 0; i < instruction.size(); ++i) {
       cout << instruction[i] << " ";
    }
    cout << std::endl;

    executeALU(instruction);
 }

Instruction CPU::instructionFetch()
{
   return cpuMemory.getInstruction();
}





