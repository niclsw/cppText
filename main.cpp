#include <string>
#include <iostream>
#include <fstream>

void getFile(std::string &fileName, std::fstream &file);
void read(std::fstream &file, std::fstream &outFile);
std::string removeComma(const auto &str);

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
    // will clean
    std::string line;
    size_t pos{0};
    outFile.open("outfile.csv", std::ios::out);

    while (std::getline(file, line))
    {
        
        if (line.find("*") != std::string::npos && isdigit(line.at(10)) == true) {

            const auto& qty = line.substr(53,68);
            outFile << pos << "," << line.substr(9,20) << "," << removeComma(qty) << std::endl;
            
            //std::cout << line.substr(8,19) << "|" << line.substr(57, 68) << std::endl;
        }
        
        pos++;
    }
} // end readToTree

std::string removeComma(const auto &str) {

    std::string retStr;
    std::string comma{","};
    size_t pos{0};

    pos = str.find(comma);


    retStr = str.replace(pos, comma.length(), "");

    return retStr;

} // end removeComma