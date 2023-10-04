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
    int type;

    type = check(str);
    if (type == 0)
        return (0);
    else if (type == 2)
        charConst(str);
    else if (type == 3)
        floatConst(str);
    else if (type == 4)
        doubleConst(str);
    else if (type == 5)
        intConst(str);
    return (1);
}

void ScalarConverter::charConst(const std::string& str)
{
    char c;
    float f;

    c = str[0];
    putChar(c);
    putInt(c);
    try {
        f = std::stof(str);
        putFloat(f);
    }
    catch (const std::out_of_range& f){
        std::cout << "out of range" << std::endl;
    }
    // putDouble();
}

void ScalarConverter::intConst(const std::string& str)
{
    int i;
    float f;

    i = std::stoi(str);
    putChar();
    putInt(i);
    try {
        f = std::stof(str);
        putFloat(f);
    }
    catch (const std::out_of_range& f){
        std::cout << "out of range" << std::endl;
    }
}

void ScalarConverter::floatConst(const std::string& str)
{
        
}

void ScalarConverter::doubleConst(const std::string& str)
{
    
}


////////////       PRINT TYPE      ////////////

void ScalarConverter::putChar(void)
{
    std::cout << "char: '" << "Non displayable" << "'" << std::endl;
}

void ScalarConverter::putChar(const char& c)
{
    std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::putInt(const int& i)
{
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::putFloat(const float& f)
{
    std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::putDouble(const double& d)
{
    std::cout << "double: " << d << std::endl;
}

////////////        END         ////////////

int ScalarConverter::check(std::string& str)
{
    int dot;
    int f;

    dot = 0;
    f = 0;
    if (!(str.compare("+inf") && str.compare("+inff") &&
            str.compare("-inf") && str.compare("-inff") &&
            str.compare("nan") && str.compare("nanf")))
        return (1);     // inf
    else if (str.length() == 1)
    {
        if (isdigit(str[0]))
            return (5);     // int
        return (2);     // char
    }
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
                !(str[i] == '.' && (i != str.length() - 1 && i != 0) && dot == 1) &&
                !(str[i] == '-' && i == 0))
                return (0);
        }
        if (f == 1)
        {
            if (dot == 0)
                return (0);
            else
                return (3);     // float
        }
        else if (dot == 1)
            return (4);     // double
        return (5);      // int
    }
    return (0);
}

