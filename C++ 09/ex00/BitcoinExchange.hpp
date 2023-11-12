#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <vector>

namespace MyNamespace {
        class Exception : public std::exception {
                public:
                        virtual const char* what() const throw() {
                                return ("Error: ");
                        };
        };
};

using namespace MyNamespace;

class BitcoinExchange
{
	private:
                const float _value;
                const std::string _year;
                const std::string _month;
                const std::string _day;
        public:
                BitcoinExchange(float value, std::string year,
                        std::string month, std::string day);
                float getValue();
                std::string getYear();
                std::string getMonth();
                std::string getDay();
                class CustomException : public MyNamespace::Exception {
                        private:
                                const char* _errorStr;
                        public:
                                CustomException(const char* errorStr) : _errorStr(errorStr) {};
                                const char* what() const throw(){
                                        return (this->_errorStr);
                        }
                };
};

#endif