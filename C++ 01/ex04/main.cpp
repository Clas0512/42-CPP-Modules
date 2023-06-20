#include "rePlace.hpp"

int checkArgs(int ac, std::string av1, std::string av2, std::string av3)
{
    if (ac != 4)
    {
        std::cout << "ERROR: Invalid anput. Please enter this format!\n  \"./Sed <filename> <String-1> <String-2>\"" << std::endl;
        return 1;
    }
    else if (av1.empty() || av2.empty() || av3.empty())
    {
        std::cout << "ERROR: Empty argument/arguments!" << std::endl;
        return 2;
    }
    else if (av2.compare(av3) == 0)
    {
        std::cout << "ERROR: String-1 same with String-2. They've to be different!" << std::endl;
        return 3;
    }
    return 0;
}

int main(int ac, char **av){

    rePlace Zort;

    int errorValue = checkArgs(ac, av[1], av[2], av[3]);
    if (errorValue != 0)
        return errorValue;
    Zort.fileName = av[1];
    Zort.replaceFileName = Zort.fileName + ".replace";
    Zort.s1 = av[2];
    Zort.s2 = av[3];
    Zort.inputFile.open(Zort.fileName);
    if (!Zort.inputFile.is_open())
    {
        std::cout << "ERROR: File cannot open!" << std::endl;
        return 4;
    }
    Zort.outputFile.open(Zort.replaceFileName);
    if (!Zort.outputFile.is_open())
    {
        std::cout << "ERROR: File cannot open!" << std::endl;
        return 4;
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