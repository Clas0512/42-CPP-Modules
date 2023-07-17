#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed{

private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(int a);
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &number);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


Fixed a(5);
Fixed b(a);

b = a;

#endif
