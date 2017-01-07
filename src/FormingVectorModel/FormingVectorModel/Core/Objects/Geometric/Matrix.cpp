#include "Point.hpp"

FVM::Core::Objects::Geometric::Point::Point() : Point(0, 0)
{
}

FVM::Core::Objects::Geometric::Point::Point(int x, int y) : x_(x), y_(y)
{
}

FVM::Core::Objects::Geometric::Point::Point(const Point& other) : x_(other.x_), y_(other.y_)
{
}

int FVM::Core::Objects::Geometric::Point::x() const
{
	return x_;
}

int FVM::Core::Objects::Geometric::Point::y() const
{
	return y_;
}

FVM::Core::Objects::Geometric::Point FVM::Core::Objects::Geometric::Point::operator=(const Point& other)
{
	if(this != &other)
	{
		x_ = other.x_;
		y_ = other.y_;
	}
	return *this;
}