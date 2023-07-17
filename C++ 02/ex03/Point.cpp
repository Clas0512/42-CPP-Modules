#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{	
}

Point::Point(Point const &copy)
{
    std::cout << "Point copy constructor called" << std::endl;
    *this = copy;
}

Fixed &	Point::operator=(Fixed const &rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    return ;
}