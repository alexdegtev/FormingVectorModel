#include "Line.hpp"
#include <math.h>

FVM::Core::Objects::Geometric::Line::Line() : p1_(), p2_()
{
}

FVM::Core::Objects::Geometric::Line::Line(Point p1, Point p2) : p1_(p1), p2_(p2)
{
}

FVM::Core::Objects::Geometric::Line::Line(const Line& other) : p1_(other.p1_), p2_(other.p2_)
{
}

FVM::Core::Objects::Geometric::Point FVM::Core::Objects::Geometric::Line::p1() const
{
	return p1_;
}

FVM::Core::Objects::Geometric::Point FVM::Core::Objects::Geometric::Line::p2() const
{
	return p2_;
}

double FVM::Core::Objects::Geometric::Line::length() const
{
	return sqrt(pow(p2_.x() - p1_.x(), 2) + pow(p2_.y() - p1_.y(), 2));
}

FVM::Core::Objects::Geometric::Line FVM::Core::Objects::Geometric::Line::operator=(const Line& other)
{
	if(this != &other)
	{
		p1_ = other.p1_;
		p2_ = other.p2_;
	}
	return *this;
}
