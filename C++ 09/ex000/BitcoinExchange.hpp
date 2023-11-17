#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>

# define CSVFILENAME "data.csv"

class BitcoinExchange
{
	private:
		std::string						csvFileName;
		std::string						inputFileName;
		std::ifstream					csvFile;
		std::ifstream					inputFile;
        std::map<int *, float>	mapCsv;
	public:
		BitcoinExchange(std::string fileName);
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &instance);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);
		std::map<int *, float>	locateCsvInMap();
		std::map<int *, float>	&getMap();

		class MyException : public std::exception
		{
			private:
				const char* errorString;
			public:
				MyException(const char *str) : errorString(str){};
			const char* what() const throw()
			{
				return (errorString);
			}
		};
};

int *stringDateToInt(std::string stringDate);
std::ifstream	openFile(std::string fileName);
std::ifstream	openFile(void);
void	calculateBitcoins();

#endif