#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    std::cout << "Default Constructor Call" << std::endl;
    openFile(csvFile);

}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    openFile(csvFile);
    openFile(inputFile, fileName);
    this->csvFileName = CSVFILENAME;
    this->inputFileName = fileName;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &instance)
{
    std::cout << "Copy Constructor Call" << std::endl;
    *this = instance;
}

BitcoinExchange::~BitcoinExchange(void)
{
    if (this->csvFile.is_open())
        csvFile.close();
    if (this->inputFile.is_open())
        inputFile.close();
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    std::cout << "Operator Overload Call" << std::endl;
    if (this->csvFile.is_open())
        csvFile.close();
    if (this->inputFile.is_open())
        inputFile.close();
	openFile(this->csvFile);
    openFile(this->inputFile, rhs.inputFileName);
    this->mapCsv = rhs.mapCsv;
    return (*this);
}

void    BitcoinExchange::locateCsvInMap(void)
{
    std::string line;

    std::getline(this->csvFile, line);
    if (line != "date,exchange_rate")
        throw MyException("Invalid CSV file.");
    while (std::getline(this->csvFile, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string value;
        while (std::getline(ss, date, ',') && std::getline(ss, value, ','))
        {
            float tmp;
            try
            {
                tmp = std::stof(value);
            }
            catch(const std::exception& e)
            {
                throw MyException("Type Casting Error.");
            }
            this->mapCsv.insert(std::pair<std::string, float> (date, tmp));
            // std::cout << "date: ." << date << ". value: " << tmp << std::endl;
        }
    }
}

std::map<std::string, float> &BitcoinExchange::getMap()
{
    return (this->mapCsv);
}

void	BitcoinExchange::start(void)
{
    std::string line;

    std::getline(this->inputFile, line);
    if (line != "date | value")
        throw MyException("Invalid Input file.");
    while (std::getline(this->inputFile, line))
    {
        bool newLine = false;
        try
        {
            checkInputLine(line);
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << line << std::endl;
            newLine = true;
        }
        if (newLine == true)
            continue;
        std::stringstream ss(line);
        std::string dateStr;
        dateElements *inputInline;
        std::string valueStr;

        while (std::getline(ss, dateStr, ' ') && std::getline(ss, valueStr, ' ') && std::getline(ss, valueStr, ' '))
        {
            inputInline = fillDateStruct(dateStr);
            try
            {
                checkValue(valueStr);
                inputInline->value = std::stof(valueStr);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << std::endl;
                newLine = true;
                break;
            }
        }
        if (newLine == true)
            continue;
        if (limitCheck(inputInline))
        {
            if (limitCheck(inputInline) == 3)
                std::cout << "Error: too large a number." << std::endl;
            else if (limitCheck(inputInline) == 2)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: bad input => " << inputInline->dateStr << std::endl;
            newLine = true;
        }
        if (newLine == true)
            continue;
        std::map<std::string, float>::iterator its = mapCsv.begin();
        std::map<std::string, float>::iterator expected = its;
        try
        {
            if (strToSum(its->first) == strToSum(dateStr))
                std::cout << dateStr << " => " << inputInline->value << " = " << inputInline->value * its->second << std::endl;
            else
            {
                int diff = strToSum(dateStr) - strToSum(its->first);
                while (++its != mapCsv.end())
                {
                    // std::cout << "cmpDate: " << dateStr << "  csv: " << its->first << "  cmpValue: " << inputInline->value << "  csvValue: " << its->second << std::endl;
                    if ((strToSum(dateStr) - strToSum(its->first)) >= 0)
                    {
                        diff = strToSum(dateStr) - strToSum(its->first);
                        expected = its;
                    }
                    else if ((strToSum(dateStr) - strToSum(its->first)) < 0)
                        break;
                }
                if (diff >= 0)
                    std::cout << dateStr << " => "<< inputInline->value << " = " << (inputInline->value * expected->second) << std::endl;
                else
                    throw BitcoinExchange::MyException("Invalid date.");
            }
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        delete inputInline;
    }
}