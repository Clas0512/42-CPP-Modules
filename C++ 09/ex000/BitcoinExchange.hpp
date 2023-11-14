#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
	private:
        std::map<std::string, int> map00;
	public:
		BitcoinExchange(void);
		BitcoinExchange(** replace parameters **);
		BitcoinExchange(BitcoinExchange const &instance);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);
};

#endif