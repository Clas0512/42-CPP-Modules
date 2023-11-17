#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(std::string fileName) : csvFile(openFile()), inputFile(openFile(fileName))
{
    this->csvFileName = CSVFILENAME;
    this->inputFileName = fileName;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &instance)
{
    *this = instance;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this->csvFile.is_open())
        csvFile.close();
    if (this->inputFile.is_open())
        inputFile.close();
	this->csvFile = openFile(rhs.csvFileName);
    this->inputFile = openFile(rhs.inputFileName);
    this->mapCsv = rhs.mapCsv;
    return (*this);
}

std::map<int *, float>	BitcoinExchange::locateCsvInMap(void)
{
    std::string line;
    std::map<int *, float> returnMap;

    std::getline(this->csvFile, line);
    while (std::getline(this->csvFile, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string value;
        while (std::getline(ss, date, ',') && std::getline(ss, value, ','))
        {
            float tmp;
            int *dateInt;
            try
            {
                dateInt = stringDateToInt(date);
                tmp = std::stof(value);
                std::cout << "date: " << dateInt[0] << " ," << dateInt[1] << " ," << dateInt[2] << " value: " << tmp << std::endl;
            }
            catch(const std::exception& e)
            {
                throw MyException("Type Casting Error.");
            }
            returnMap.insert(std::make_pair(dateInt, tmp));
        }
    }
    return (returnMap);
}

std::map<int *, float> &BitcoinExchange::getMap()
{
    return (this->mapCsv);
}

void	calculateBitcoins()
{

}