#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av){

    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string replaceFileName;
    std::string fileName;
    std::size_t found;
    std::string temp;
    std::string s1;
    std::string s2;
    if (ac == 4)
    {
        fileName = av[1];
        replaceFileName = fileName + ".replace";
        s1 = av[2];
        s2 = av[3];
        inputFile.open(fileName);
        outputFile.open(replaceFileName);
        if (!outputFile.is_open())
        {
            std::cout << "ERROR: file cannot open!" << std::endl;
            return 0;
        }
        if (!inputFile.is_open())
        {
            std::cout << "ERROR: file cannot open!" << std::endl;
            return 0;
        }
        while (std::getline(inputFile, temp))
        {
            std::cout << temp << std::endl;
        }
        inputFile.close();
        inputFile.open(fileName);
        temp = "";
        while (std::getline(inputFile, temp))
        {
            found = temp.find(s1);
            while (found != std::string::npos)
            {
                temp.replace(found, s1.length(), s2);
                found = temp.find(s1);
            }
            outputFile << temp << std::endl;
        }
    }
    return 0;
}