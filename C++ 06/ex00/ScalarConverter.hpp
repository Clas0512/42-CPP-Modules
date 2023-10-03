#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
        static int check(std::string&);
        static void putChar(const char& c);
        static void putInt(const int& i);
        static void putFloat(const float& f);
        static void putDouble(const double& d);
        static void charConst(const std::string&);
        static void intConst(const std::string&);
        static void floatConst(const std::string&);
        static void doubleConst(const std::string&);
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
        class   InputException : public std::exception{
            public:
                virtual const char* what() const throw()
                {
                        return ("Invalid Input!");
                }
        };
        static bool convert(std::string&);
};

#endif
