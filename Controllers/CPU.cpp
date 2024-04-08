#include <iostream>
#include <fstream>
#include <string>

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
    
    void readBinaryFile(const string& filename) {
        
        ifstream file(filename, ios::binary);
        if (file.is_open()) {
            file.read(reinterpret_cast<char*>(&binaryInstruction[0]), sizeof(binaryInstruction));
            file.close();
        }
        else {
            cerr << "Error: Unable to open file " << filename << endl;
        }

        cout << binaryInstruction << "Test" << endl;
    }

};