#include <string>
#include <iostream>
#include <fstream>

void getFile(std::string &fileName, std::fstream &file);
void read(std::fstream &file, std::fstream &outFile);
std::string removeComma(auto str);

int main() {

    std::string fileName{""};
    std::fstream file;
    std::fstream outFile;

    getFile(fileName, file);
    read(file, outFile);

    file.close();
    outFile.close();

} // end main

void getFile(std::string &fileName, std::fstream &file)
{

    fileName = "example.txt";

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
    // will clean
    std::string line;
    size_t linePos{0};
    outFile.open("out.csv", std::ios::out);

    while (std::getline(file, line))
    {
        
        if (line.find("*") != std::string::npos && isdigit(line.at(10))) {

            auto qty = line.substr(48,68);
            outFile << linePos << "," << line.substr(8,20) << "," << removeComma(qty) << std::endl;
            
            //std::cout << line.substr(8,19) << "|" << line.substr(57, 68) << std::endl;
        }
        
        linePos++;
    }
} // end readToTree

std::string removeComma(auto str) {

    std::string comma{","};
    size_t pos{0};

    pos = str.find(comma);

    return (pos > 1000 ? str : str.replace(pos, comma.length(), ""));

} // end removeComma