#include "CPU.h"

int CPU::readBinaryFile(const string filename) {
        
   ifstream file(filename, ios::binary); // Open the file

    if (!file.is_open()) { // Check if the file is opened successfully
        cerr << "Error: Unable to open the file " << filename << endl;
        return 1; // Exit with error code 1
    }

    /*string line;
    while (getline(file, line)) { // Read each line from the file
        cout << line << endl; // Output the line to the console
    }*/

    char byte;
    while (file.read(&byte, 1)) {
        bitset<8> bits(byte);
        
        cout << bits << ' ';
    }

    file.close();

    return 0;
 }