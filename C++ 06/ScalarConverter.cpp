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

void	ScalarConverter::convert(const std::string& ltr)
{
    int i;

    i = 0;
	if (ltr[i] && ltr.length() == 1 && ltr[0] <= 127 && ltr[0] >= 32)
    {
        ScalarConverter::charConstructor(ltr);
        return ;
    }
    if (ltr[i] && (ltr[i] == '-' || ltr[i] == '+'))
        i++;
    while (ltr[i])
    {
        if (ltr[i] == '.')
        {
            while (ltr[i])
            {
                if (ltr[i] == 'f')
                {
                    ScalarConverter::floatConstructor(ltr);
                    return ;
                }
                if (!(ltr[i] >= 48 && ltr[i] <= 57))
                    throw InputException();
                i++;
            }
            ScalarConverter::doubleConstructor(ltr);
            return ;
        }
        if (!(ltr[i] >= 48 && ltr[i] <= 57))
            throw InputException();
        i++;
    }
    ScalarConverter::intConstructor(ltr);
}
