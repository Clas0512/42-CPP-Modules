#include "rePlace.hpp"

int checkArgs(std::string *av)
{
    if (av[1].empty() || av[2].empty() || av[3].empty())
        return 1;
    return 0;
}

int main(int ac, char **av){

    rePlace Zort;

    if (ac != 4)
    {
        std::cout << "ERROR: Invalid anput. Please enter this format:\n  \"./Sed <filename> <String-1> <String-2>\"" << std::endl;
        return 1;
    }
    if (checkArgs((std::string *)av))
    {
        std::cout << "ERROR: Empty argument/arguments" << std::endl;
        return 2;
    }
    Zort.fileName = av[1];
    Zort.replaceFileName = Zort.fileName + ".replace";
    Zort.s1 = av[2];
    Zort.s2 = av[3];
    Zort.inputFile.open(Zort.fileName);
    Zort.outputFile.open(Zort.replaceFileName);
    if (!Zort.outputFile.is_open() || !Zort.inputFile.is_open())
    {
        std::cout << "ERROR: File cannot open!" << std::endl;
        return 3;
    }
    while (std::getline(Zort.inputFile, Zort.temp))
    {
        Zort.found = Zort.temp.find(Zort.s1);
        while (Zort.found != std::string::npos)
        {
            Zort.temp.erase(Zort.found, Zort.s1.length());
            Zort.temp.insert(Zort.found, Zort.s2);
            Zort.found = Zort.temp.find(Zort.s1);
        }
        Zort.outputFile << Zort.temp << std::endl;
    }
    Zort.inputFile.close();
    Zort.outputFile.close();
    return 0;
}