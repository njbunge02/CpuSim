#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdbool.h>
#include <bitset>



using namespace std;

string checkForErrors(vector<vector<string> > instructions);
vector<string> convertToBinary(vector<vector<string> > instructions);

int main(int argc, char* argv[])
{

    ifstream file(argv[1]);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Read the file line by line
    string line;
    string element;
    stringstream ss;

    vector<vector<string> > instructions;    //holds all lines of file
    vector<string> arguments;

    //reads file and puts them into a vector
    while (getline(file, line)) {
       
       for (size_t i = 0; i < line.size(); ++i)
       {
            if (line[i] == ',')
                line[i] = ' ';
       }

       ss.str(line);
       while (ss >> element)
       {
        arguments.push_back(element);     
       }
        ss.clear(); 

        instructions.push_back(arguments);
        arguments.clear();

    }
    file.close();


    string errors = checkForErrors(instructions);

    if (errors != "0")
    {
        cerr << errors;
        return 1;
    }

    //writing to output file
    ofstream outFile(argv[2], ios::binary);

    if (!outFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
   
    vector<string> binaryData = convertToBinary(instructions);

    
    for (size_t i = 0; i < binaryData.size(); ++i)
    {
        bitset<32> bits(binaryData[i]);

        uint32_t data = bits.to_ulong();

        for (int j = 3; j >= 0; --j) {
            outFile.put((data >> (j * 8)) & 0xFF);
        }
    }

    outFile.close();
    


    return 0;
}

string checkForErrors(vector<vector<string> > instructions)
{
    
    stringstream errorSS;
    bool isError = false;


    for (size_t i = 0; i < instructions.size(); i++)
    {
        
        for (size_t j = 0; j < instructions[i].size(); ++j)
        {
            if (j == 0) //checks for correct instruction
            {
                if (instructions[i][j] != "lw" && instructions[i][j] != "sw" && instructions[i][j] != "add" && instructions[i][j] != "sub" && \
                instructions[i][j] != "and" &&instructions[i][j] != "or" && instructions[i][j] != "slt" &&instructions[i][j] != "beq" && \
                instructions[i][j] != "j" && instructions[i][j] != "addi")
                {
                    errorSS << "Line " << i + 1 << " has an error " << "(unsupported instruction)" << endl;
                    isError = true;
                }
            }else     
            {

                if (instructions[i][j][0] == '$')
                {
                    if (stoi(instructions[i][j].substr(1)) < 0 || stoi(instructions[i][j].substr(1)) > 31 )
                    {
                        errorSS << "Line " << i + 1 << " has an error " << "(register number is out of range)" << endl;
                        isError = true;
                    }
                }

            
            }

        }

        if (instructions[i][0] == "lw" || instructions[i][0] == "sw") //checks for correct amount of arguments
            {
                if (instructions[i].size() != 3)
                    {
                        errorSS << "Line " << i + 1 << " has an error " << "(incorrect amount of arguments)" << endl;
                        isError = true;
                    }
                } else if (instructions[i][0] == "add" ||instructions[i][0] == "sub" ||instructions[i][0] == "or" ||\
                instructions[i][0] == "and" ||instructions[i][0] == "slt" || instructions[i][0] == "beq")
                {
                    if (instructions[i].size() != 4)
                        {
                            errorSS << "Line " << i + 1 << " has an error " << "(incorrect amount of arguments)" << endl;
                            isError = true;
                        }
                } else if (instructions[i][0] == "j")
                {
                    if (instructions[i].size() != 2)
                        {
                            errorSS << "Line " << i + 1 << " has an error " << "(incorrect amount of arguments)" << endl;
                            isError = true;
                        }
                }

    }

   if (isError)
   {
    return errorSS.str();
   } else
   {
    return "0";
   }
}

vector<string> convertToBinary(vector<vector<string> > instructions)
{
    vector<string> data;
    stringstream lineDataSS;
    bitset<5> rs;
    bitset<5> rt;
    bitset<5> rd;
    string opCode;
    string shamt;
    string funct;
    bitset<16> imm;
    bitset<26> target;


    for (size_t i = 0; i < instructions.size(); ++i)
    {
       
        if (instructions[i][0] == "add" || instructions[i][0] == "sub" || instructions[i][0] == "and" || \
        instructions[i][0] == "or" || instructions[i][0] == "slt")
        {
           
            opCode = "000000";
            rd = stoi(instructions[i][1].substr(1));
            rs = stoi(instructions[i][2].substr(1));
            rt = stoi(instructions[i][3].substr(1));
            shamt = "00000";

            if (instructions[i][0] == "add")
            {
                funct = "100000";
            }
            else if (instructions[i][0] == "sub")
            {
                funct = "100010";
            }
            else if (instructions[i][0] == "and")
            {
                funct = "100100";
            }
            else if (instructions[i][0] == "or")
            {
                funct = "100101";
            }
            else if (instructions[i][0] == "slt")
            {
                funct = "101010";
            }
    
            lineDataSS << opCode << rs.to_string() << rt.to_string() << rd.to_string() << shamt << funct;
            //lineDataSS << funct << shamt << rd.to_string() << rt.to_string() << rs.to_string() << opCode;
        }
        else if (instructions[i][0] == "beq")
        {
            opCode = "000100";
            rs = stoi(instructions[i][1].substr(1));
            rt = stoi(instructions[i][2].substr(1));
            imm = stoi(instructions[i][3]);


            lineDataSS << opCode << rs.to_string() << rt.to_string() << imm;

        }
        else if(instructions[i][0] == "sw")
        {
        opCode = "101011";
           rt = stoi(instructions[i][1].substr(1));
            int firstParenthesis = 0;
            string tempRS;
            for (size_t q = 0; q < instructions[i][2].size(); q++)
            {
                if (instructions[i][2][q] == '(')
                {
                    imm = stoi(instructions[i][2].substr(0,q));
            
                    firstParenthesis = q;
                } else if (instructions[i][2][q] == ')')
                {
                    tempRS = instructions[i][2].substr(firstParenthesis + 1, q - firstParenthesis - 1);
                    size_t pos = 0;
                    pos = tempRS.find('$', pos);
                    tempRS.erase(pos, 1);

                    
                    rs = stoi(tempRS);
                }
      
            }
           

            lineDataSS << opCode << rs.to_string() << rt.to_string() << imm;
  

        }
        else if(instructions[i][0] == "lw")
        {

            opCode = "100011";
            rt = stoi(instructions[i][1].substr(1));
            int firstParenthesis = 0;
            string tempRS;
            for (size_t q = 0; q < instructions[i][2].size(); q++)
            {
                if (instructions[i][2][q] == '(')
                {
                    imm = stoi(instructions[i][2].substr(0,q));
            
                    firstParenthesis = q;
                } else if (instructions[i][2][q] == ')')
                {
                    tempRS = instructions[i][2].substr(firstParenthesis + 1, q - firstParenthesis - 1);
                    size_t pos = 0;
                    pos = tempRS.find('$', pos);
                    tempRS.erase(pos, 1);
                    
                    rs = stoi(tempRS);
                }
      
            }
           
        lineDataSS << opCode << rs.to_string() << rt.to_string() << imm;
  
        }
        else if(instructions[i][0] == "j")
        {
            opCode = "000010";
            target = stoi(instructions[i][1]);

            lineDataSS << opCode << target.to_string(); 
        }
        // addi - new opcode, grabs the rs, rt and the imm value. The imm value should be 16 bits.
        else if(instructions[i][0] == "addi"){
            opCode = "001000";
            rs = stoi(instructions[i][1].substr(1));
            rt = stoi(instructions[i][2].substr(1));
            imm = stoi(instructions[i][3]);
        }

        data.push_back(lineDataSS.str());
        lineDataSS.str("");
    }



    return data;
}