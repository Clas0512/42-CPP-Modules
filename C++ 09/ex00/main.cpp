#include "BitcoinExchange.hpp"

void    fillCsvLines(std::fstream& csvFile, std::vector<BitcoinExchange> &csvLines)
{
    std::string line;

    std::getline(csvFile, line);
    while (std::getline(csvFile, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> v;
        int i = 0;
        while (ss.good()) {
            std::string substr;
            if (i == 2)
                std::getline(ss, substr, ',');
            else
                std::getline(ss, substr, '-');
            v.push_back(substr);
            i++;
        }
        BitcoinExchange tmp(std::stof(v[3]), v[0], v[1], v[2]);
        csvLines.push_back(tmp);
    }
}

void    checkInputLinesArguments(std::vector<std::string> &v, std::string &line)
{
    std::cout << v.size() << std::endl;
    if (v.size() != 4)
    {
        std::string errorStr = "Error: bad input => " + line;
        const char* str = errorStr.c_str();
        std::cout << str << std::endl;
        throw (BitcoinExchange::CustomException(str));
    }    
}

void    fillInputLines(std::fstream& inputFile, std::vector<BitcoinExchange> &inputLines)
{
    std::string line;

    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> v;
        int i = 0;
        while (ss.good()) {
            std::string substr;
            if (i >= 2)
                std::getline(ss, substr, ' ');
            else
                std::getline(ss, substr, '-');
            
            if (substr != "|")
                v.push_back(substr);
            i++;
        }
        checkInputLinesArguments(v, line);                          // son aşama burda kaldım ve plan yapılması gerekiyor..
        BitcoinExchange tmp(std::stof(v[3]), v[0], v[1], v[2]);
        inputLines.push_back(tmp);
    }
}


// void    checkPrototypes(std::fstream& inputFile, std::fstream& csvFile)
// {
//     std::string line;
//     while (std::getline(csvFile, line)) {
//         //
//    }
//    inputFile.close();
// }q

void    openFile(char *input, std::fstream& inputFile, std::fstream& csvFile)
{
    inputFile.open(input, std::ios::in);
    csvFile.open("data.csv", std::ios::in);
    if (!inputFile.is_open() || !csvFile.is_open())
        throw (BitcoinExchange::CustomException("Error: could not open file."));
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            std::fstream inputFile;
            std::fstream csvFile;
            std::vector<BitcoinExchange> csvLines;
            std::vector<BitcoinExchange> inputLines;
            openFile(av[1], inputFile, csvFile);
            // checkPrototypes(inputFile, csvFile);
            fillCsvLines(csvFile, csvLines);
            fillInputLines(inputFile, inputLines);

        }
        catch(const BitcoinExchange::CustomException& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout << "Error: invalid arguments." << std::endl;
    return (0);
}