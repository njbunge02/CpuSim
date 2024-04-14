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



 string CPU::executeNextInstruction()
 {
   stringstream returnString;
   pcUpdateValue = 0;


    //Instruction Fetch
   cout << "Clock cycle: " << clockCycle << endl << endl;
   clockCycle += 1;
   cout << "Instruction Fetch" << endl;
   returnString << "Instruction Fetch" << endl;
   cout << "-----------------" << endl;
   returnString << "-----------------" << endl;
   Instruction cpuInstruction = instructionFetch();  
   cout << "Instruction Binary: " << cpuInstruction.getBinaryString() << "\n\n\n";
   returnString << "Instruction Binary: " << cpuInstruction.getBinaryString() << endl;


   //MIPS Controller
   setMuxes(cpuInstruction);

  

   //Instruction Decode
   cout << "Clock cycle: " << clockCycle << endl << endl;
    clockCycle += 1;
   cout << "Instruction Decode" << endl;
   returnString << "Instruction Decode" << endl;
   cout << "-----------------" << endl;
   returnString << "-----------------" << endl;
   vector<string> instruction = cpuInstruction.decodeInstruction();
   cout << "Assembly Code: " << cpuInstruction.getAssemby() << "\n\n\n";
   returnString << "Assembly Code: " << cpuInstruction.getAssemby() << endl;
   
   
  

   //Execute
   Registers newReg = reg;
   string result = executeALU(instruction, newReg); // The result of the ALU is returned as a string
   
   if (ALUMux)
   {
   cout << "Clock cycle: " << clockCycle << endl << endl;
    clockCycle += 1;
   cout << "Execute" << endl;
   returnString << "Execute" << endl;
   cout << "-----------------" << endl;
   cout << result.substr(12,32) << "\n\n\n";
   returnString << "-----------------" << endl;
   returnString << result.substr(12,32) << endl;



   } else if (result == "1" && instruction[0] == "000100") //beq and equal
   {
      pcMUX = true;
      pcUpdateValue = stoi(result.substr(2));
   } else if (instruction[0] == "000010") // j
   {
      pcMUX = true;
      pcUpdateValue = stoi(result);
   } 
    else if (instruction[0] == "100011") //sw
   {

   }

   

   //MemoryAccess
   if (memoryAccessMux)
   {
   cout << "Clock cycle: " << clockCycle << endl << endl;
    clockCycle += 1;
   cout << "Memory Access" << endl;
   returnString << "Memory Access" << endl;
   cout << "-----------------" << endl;
   returnString << "-----------------" << endl;


    if (instruction[0] == "100011") //lw
    {
      cout << "Register where data is stored: " << result.substr(33) << endl;
      cout << "The data: " << cpuMemory.retrieveMemory(result.substr(0,32)) << endl;
      cout << "Address Accessed: " << result.substr(0, 32) << endl;
      returnString << "Register where data is stored: " << result.substr(33) << endl;
      returnString << "The data: " << cpuMemory.retrieveMemory(result.substr(0,32)) << endl;
      returnString << "Address Accessed: " << result.substr(0, 32) << endl;

 

      newReg.pushToReg(stoi(result.substr(33)),stoi(cpuMemory.retrieveMemory(result.substr(0,32)), nullptr, 2));
    } else
    {
      cout << "Address Location: " << result.substr(0,32) << endl;
      cout << "Data to be stored: " << result.substr(33) << endl;
      returnString << "Address Location: " << result.substr(0,32) << endl;
      returnString << "Data to be stored: " << result.substr(33) << endl;

     
      
      cpuMemory.putInMemory(result.substr(0,32),  result.substr(33));

    }
      
      
   cout << "\n\n\n";

   }


   //WriteBack
   
   writeBack(newReg);
   if (writeBackMux)
   {
   cout << "Clock cycle: " << clockCycle << endl << endl;
    clockCycle += 1;
   cout << "WriteBack" << endl;
   returnString << "WriteBack" << endl;
   cout << "-----------------" << endl;
   returnString << "-----------------" << endl;




   if (instruction[0] == "100011")
   {
      cout <<  cpuMemory.retrieveMemory(result.substr(0,32)) << " written to register " <<result.substr(33) << "\n\n\n";
      returnString <<  cpuMemory.retrieveMemory(result.substr(0,32)) << " written to register " <<result.substr(33) << endl;
      
   } else
      cout << result << "\n\n\n";
    
   }

   updatePC();

   return returnString.str();
   
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
    writeBackMux = false;

   if (opCode == "100011")
      {writeBackMux = true;}

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
   pcUpdates += 1;
   if (!pcMUX)
      cpuMemory.updatePC(0);
   else
   {
      cpuMemory.updatePC(pcUpdateValue);
   }
   
}








