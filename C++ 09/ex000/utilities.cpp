#include "BitcoinExchange.hpp"

std::ifstream	openFile()
{
    std::ifstream returnFile;
    returnFile.open(CSVFILENAME, std::ios::in);
    if (!returnFile.is_open())
        throw std::invalid_argument("selam dostum yağmur var mi orda?");
    return (returnFile);
}

std::ifstream	openFile(std::string fileName)
{
    std::ifstream returnFile;
    returnFile.open(fileName, std::ios::in);
    if (!returnFile.is_open())
        throw std::invalid_argument("selam dostum yağmur var mi orda?");
    return (returnFile);
}

int *stringDateToInt(std::string stringDate)
{
    int *integerDate;

    integerDate = new int[3];
    std::istringstream ss(stringDate);
    std::string dateElements[3];

    std::getline(ss, dateElements[0], '-');
    integerDate[0] = std::stoi(dateElements[0]);
    std::getline(ss, dateElements[1], '-');
    integerDate[1] = std::stoi(dateElements[1]);
    std::getline(ss, dateElements[2], '-');
    integerDate[2] = std::stoi(dateElements[2]);
    return (integerDate);
}
