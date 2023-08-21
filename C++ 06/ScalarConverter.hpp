#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
        static void toChar(const std::string& ltr);
        static void toInt(const std::string& ltr);
        static void toFloat(const std::string& ltr);
        static void toDouble(const std::string& ltr);
        static void charConstructor(const std::string& ltr);
        static void intConstructor(const std::string& ltr);
        static void floatConstructor(const std::string& ltr);
        static void doubleConstructor(const std::string& ltr);
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
        static void convert(const std::string& ltr);

};

#endif