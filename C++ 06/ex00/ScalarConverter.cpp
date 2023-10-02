#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default Constructor Call" << std::endl;	
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	std::cout << "Copy Constructor Call" << std::endl;
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Default Destructor Call" << std::endl;	
}

bool ScalarConverter::convert(std::string& str)
{
    return (check(str));
}

////////////       PRINT TYPE      ////////////

static void putChar(const char& c)
{
    std::cout << "char: '" << c << "'" << std::endl;
}

static void putInt(const int& i)
{
    std::cout << "int: " << i << std::endl;
}

static void putFloat(const float& f)
{
    std::cout << "float: " << f << std::endl;
}

static void putDouble(const double& d)
{
    std::cout << "double: " << d << std::endl;
}

////////////        END         ////////////



static void charConstructor(const char *ltr)
{
    putChar(ltr[0]);
    putInt(ltr[0]);
    char *end;
    try
    {
        putFloat(strtof(ltr, &end));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

static void intConstructor(const std::string& ltr)
{

}

static void floatConstructor(const std::string& ltr)
{

}

static void doubleConstructor(const std::string& ltr)
{

}

void	ScalarConverter::toChar(const std::string& ltr)
{
	
}

void	ScalarConverter::toInt(const std::string& ltr)
{
	
}

void	ScalarConverter::toFloat(const std::string& ltr)
{
	
}

void	ScalarConverter::toDouble(const std::string& ltr)
{
	
}

bool ScalarConverter::check(std::string& str)
{
    int dot;
    int f;

    dot = 0;
    f = 0;
    if (!(str.compare("+inf") && str.compare("+inff") &&
            str.compare("-inf") && str.compare("-inff") &&
            str.compare("nan") && str.compare("nanf")))
        return (true);
    else if (str.length() == 1)
        return (true);
    else if (str.length() > 1)
    {
        for(int i = 0; i < (int)str.size(); i++)
        {
            if (str[i] == '.')
                dot++;
            if (str[i] == 'f')
                f++;
            if(!isdigit(str[i]) &&
                !(str[i] == 'f' && i == str.length() - 1 && f == 1) &&
                !(str[i] == '.' && (i != str.length() - 1 && i != 0) && dot == 1))
                return (false);
        }
        return (true);
    }
    return (false);
}
