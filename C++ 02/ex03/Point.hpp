#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		~Point();
		Point(const float n1, const float n2);
		Point(const Point &copy);
		Point &operator=(Point const &pnt);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif