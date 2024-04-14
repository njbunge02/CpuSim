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
    cout << "Clock cycle: " << "1" << endl << endl;


    //Instruction Fetch
   cout << "Instruction Fetch" << endl;
   cout << "-----------------" << endl;
   Instruction cpuInstruction = instructionFetch();  
   cout << "Instruction Binary: " << cpuInstruction.getBinaryString() << "\n\n\n";


   //MIPS Controller
   setMuxes(cpuInstruction);

  

   //Instruction Decode
   cout << "Instruction Decode" << endl;
   cout << "-----------------" << endl;
   vector<string> instruction = cpuInstruction.decodeInstruction();
   cout << "Assembly Code: " << cpuInstruction.getAssemby() << "\n\n\n";
   


   //Execute
   Registers newReg = reg;
   string result = executeALU(instruction, newReg); // The result of the ALU is returned as a string
   
   if (ALUMux)
   {
   cout << "Execute" << endl;
   cout << "-----------------" << endl;
   cout << result.substr(12,32) << "\n\n\n";
   }

   //MemoryAccess
   cout << "Memory Access" << endl;
   cout << "-----------------" << endl;

   cout << "\n\n\n";



   //WriteBack
   writeBack(newReg);
   cout << "WriteBack" << endl;
   cout << "-----------------" << endl;
   cout << result << "\n\n\n";


   updatePC();
   
 }




void CPU::writeBack(Registers inputReg)
{
   reg = inputReg;
}

Instruction CPU::instructionFetch()
{
   return cpuMemory.getInstruction();
}

void CPU::setMuxes(Instruction instruct)
{

vector<string> arguments = instruct.decodeInstruction();
string opCode = arguments[0];



if (opCode == "000000" || opCode == "001000")//RTYPE & addi
{
   memoryAccessMux = false;
   writeBackMux = true;
   ALUMux = true;
   pcMUX = false;

} else if (opCode == "101011"  || opCode == "100011") //lw & sw
{
   memoryAccessMux = true;
   writeBackMux = true;
   ALUMux = false;
   pcMUX = false;

} else if (opCode == "000100") //beq
{
   memoryAccessMux = false;
   writeBackMux = false;
   ALUMux = false;
   pcMUX = true;
} else if ( opCode == "000010") //j
{
   memoryAccessMux = false;
   writeBackMux = false;
   ALUMux = true;
   pcMUX = true;

} else
{
   cout << "INVALID OPCODE\n";
   
}

}


void CPU::updatePC()
{
   cpuMemory.updatePC(4);
}








