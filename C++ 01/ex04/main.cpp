#include <iostream>
#include <fstream>

int main(int ac, char **av){

    std::ifstream inputFile;
    std::string filename;
    std::string s1;
    std::string s2;
    if (ac == 4)
    {
        filename = av[1];
        s1 = av[2];
        s2 = av[3];
        inputFile.open(filename);
        
    }
    return 0;
}