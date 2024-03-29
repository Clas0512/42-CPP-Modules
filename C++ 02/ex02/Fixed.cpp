#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int intToFix)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = intToFix << bits;
}

Fixed::Fixed(const float floatToFix)
{
	std::cout << "Float constructor called" << std::endl;
	float scaledValue = floatToFix * pow(2, bits);
    int roundedValue = static_cast<int>(roundf(scaledValue));
    this->value = roundedValue;
}

Fixed & Fixed::operator=(const Fixed &number)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->value = number.value;
	return (*this);
}

float Fixed::toFloat(void) const
{
	float scaleFactor = 1.0f / pow(2, bits);
    return static_cast<float>(this->value) * scaleFactor;
}

int Fixed::toInt(void) const
{
	return this->value >> bits;
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

bool Fixed::operator>(const Fixed &number)
{
	return (this->value > number.value);
}

bool Fixed::operator<(const Fixed &number)
{
	return (this->value < number.value);
}

bool Fixed::operator>=(const Fixed &number)
{
	return (this->value >= number.value);
}

bool Fixed::operator<=(const Fixed &number)
{
	return (this->value <= number.value);
}

bool Fixed::operator==(const Fixed &number)
{
	return (this->value == number.value);
}

bool Fixed::operator!=(const Fixed &number)
{
	return (this->value != number.value);
}

Fixed Fixed::operator+(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() + number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator-(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() - number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator*(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() * number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator/(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() / number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator++(int)
{
	Fixed returnvalue = *this;
	this->value++;
	return (returnvalue);
}

Fixed &Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed returnvalue = *this;
	this->value--;
	return (returnvalue);
}

Fixed &Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.value < f2.value)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.value > f2.value)
		return (f1);
	return (f2);
}
