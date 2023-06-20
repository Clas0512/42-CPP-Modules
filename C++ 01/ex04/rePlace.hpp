#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class rePlace{
    public:
        std::ifstream inputFile;
        std::ofstream outputFile;
        std::string replaceFileName;
        std::string fileName;
        std::size_t found;
        std::string temp;
        std::string s1;
        std::string s2;
};


#endif
