#include "BitcoinExchange.hpp"

void openFile(std::ifstream& file)
{
    file.open(CSVFILENAME, std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("Error: ivalid argument.");
}

void openFile(std::ifstream& file, const std::string& fileName)
{
    file.open(fileName, std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("Error: ivalid argument.");
}

void    BitcoinExchange::checkInputLine(std::string line)
{
    if (!(line.length() > 13 && line[10] == ' ' && line[11] == '|' && line[12] == ' '))
        throw BitcoinExchange::MyException("Error: bad input => ");
    if (line[4] != '-' || line[7] != '-')
        throw BitcoinExchange::MyException("Error: bad input => ");
}

int limitCheck(dateElements *elements)
{
    if (elements->year < 2009 || elements->year > 2023)
        return (1);
    if (elements->year % 4 == 0 && elements->month == 2 && elements->day > 29)
        return (1);
    if (!(elements->year % 4 == 0) && elements->month == 2 && elements->day > 28)
        return (1);
    if ((elements->month == 4 || elements->month == 6 || elements->month == 9 || elements->month == 11) &&
        elements->day > 30)
        return (1);
    if (elements->day > 31 || elements->day < 1)
        return (1);
    if (elements->month < 1 || elements->month > 12)
        return (1);
    if (strToSum(elements->dateStr) > 20220329 || strToSum(elements->dateStr) < 20090102)
        return (1);
    if (elements->value < 1)
        return (2);
    if (elements->value > 1000)
        return (3);
    return (0);
}

int strToSum(std::string str)
{
    int result = 0;

    try
    {
        result += std::stoi(str.substr(0, 4)) * 10000;
        result += std::stoi(str.substr(5, 2)) * 100;
        result += std::stoi(str.substr(8, 2));
    }
    catch(const std::exception& e)
    {
        throw BitcoinExchange::MyException("STOI error.");
    }
    return (result);
}

dateElements *fillDateStruct(std::string dateStr)
{
    dateElements *returnValue = new dateElements;
    size_t index = dateStr.find("-");

    returnValue->dateStr = dateStr;
    returnValue->year = std::stoi(dateStr.substr(0, index));
    returnValue->month = std::stoi(dateStr.substr(index + 1, 2));
    returnValue->day = std::stoi(dateStr.substr(index + 4, 2));
    return (returnValue);
}

void    checkValue(std::string& valueStr)
{
    int dot = 0;

    for (int i = 0; valueStr[i]; i++)
    {
        if (valueStr[i] == '-')
            throw BitcoinExchange::MyException("Error: not a positive number.");
        if ((i == 0 && valueStr[i] == '.') || dot > 1)
            throw BitcoinExchange::MyException("Error: invalid value.");
        if (!isdigit(valueStr[i]) && valueStr[i] != '.' )
            throw BitcoinExchange::MyException("Error: invalid value.");
        if (valueStr[i] == '.')
        {
            dot++;
            if (!isdigit(valueStr[i + 1]))
                throw BitcoinExchange::MyException("Error: invalid value.");
        }
    }
    
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
