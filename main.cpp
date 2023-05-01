#include <string>
#include <iostream>
#include <fstream>

void getFile(std::string &fileName, std::fstream &file);
void read(std::fstream &file, std::fstream &outFile);

int main() {

    std::string fileName{""};
    std::fstream file;
    std::fstream outFile;

    getFile(fileName, file);
    read(file, outFile);

    file.close();
    outFile.close();

}

void getFile(std::string &fileName, std::fstream &file)
{

    fileName = "1.txt";

    // open file
    file.open(fileName, std::ios::in);

    try
    {
        if (!file)
            throw std::invalid_argument("File failed to open");
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
} // end getFile

void read(std::fstream &file, std::fstream &outFile)
{

    std::string line;

    outFile.open("outfile.csv", std::ios::out);

    while (std::getline(file, line))
    {
        // if line == string length of 11 then it is an NDC
        if (line.find("*") != std::string::npos && isdigit(line.at(10)) == true) {
            outFile << line.substr(9,20) << "|" << line.substr(53, 68) << std::endl;
            //std::cout << line.substr(8,19) << "|" << line.substr(57, 68) << std::endl;
        }
        //if (line.find("**") != std::string::npos)
        //    std::cout << idValue << " Found - " << line << std::endl;
        //}
    }
} // end readToTree