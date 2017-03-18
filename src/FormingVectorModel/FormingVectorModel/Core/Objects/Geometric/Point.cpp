#include "Point.h"

Core::Objects::Geometric::Point::Point() : Point(0, 0)
{
}

Core::Objects::Geometric::Point::Point(int x, int y) : _x(x), _y(y)
{
}

Core::Objects::Geometric::Point::Point(IPoint* other) : Point(other->x(), other->y())
{
}

Core::Objects::Geometric::Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
}

int Core::Objects::Geometric::Point::x() const
{
	return _x;
}

int Core::Objects::Geometric::Point::y() const
{
	return _y;
}
