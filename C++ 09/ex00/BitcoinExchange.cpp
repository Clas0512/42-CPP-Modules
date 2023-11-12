#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(float value, std::string year, std::string month,
        std::string day) : _value(value), _year(year), _month(month), _day(day){}

float	BitcoinExchange::getValue()
{
    return (_value);
}

std::string	BitcoinExchange::getYear()
{
	return (_year);
}

std::string	BitcoinExchange::getMonth()
{
	return (_month);
}

std::string	BitcoinExchange::getDay()
{
	return (_day);
}