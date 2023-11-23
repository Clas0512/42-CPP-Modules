#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>

# define CSVFILENAME "data.csv"

struct dateElements{
	std::string dateStr;
	int		year;
	int		month;
	int		day;
	float	value;
};

class BitcoinExchange
{
	private:
		std::string						csvFileName;
		std::string						inputFileName;
		std::ifstream					csvFile;
		std::ifstream					inputFile;
        std::map<std::string, float>	mapCsv;
	public:
		BitcoinExchange(std::string fileName);
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &instance);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);
		void	locateCsvInMap(void);
		void    checkInputLine(std::string line);
		void	start(void);
		std::map<std::string, float>	&getMap();

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

int	limitCheck(dateElements *elements);
int strToSum(std::string str);
dateElements *fillDateStruct(std::string dateStr);
int *stringDateToInt(std::string stringDate);
void openFile(std::ifstream& file, const std::string& fileName);
void openFile(std::ifstream& file);

#endif