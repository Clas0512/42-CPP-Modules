#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
        static bool check(std::string&);
        static void toChar(const std::string&);
        static void toInt(const std::string&);
        static void toFloat(const std::string&);
        static void toDouble(const std::string&);
        static void putChar(const char& c);
        static void putInt(const int& i);
        static void putFloat(const float& f);
        static void putDouble(const double& d);
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
        class   InputException : public std::exception{
            public:
                virtual const char* what() const throw(){ return ("Invalid Input!");}
        };
        static bool convert(std::string&);
};

#endif
