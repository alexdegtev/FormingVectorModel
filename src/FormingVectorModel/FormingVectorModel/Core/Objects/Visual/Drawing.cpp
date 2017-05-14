#include "Drawing.h"

Core::Objects::Visual::Drawing::Drawing(std::vector<Geometric::ILine*> front_view, std::vector<Geometric::ILine*> top_view, std::vector<Geometric::ILine*> side_view)
	: front_view_(front_view), top_view_(top_view), side_view_(side_view)
{
}

Core::Objects::Visual::Drawing::Drawing()
{
}

std::vector<Core::Objects::Geometric::ILine*> Core::Objects::Visual::Drawing::front_view() const
{
	return front_view_;
}

void Core::Objects::Visual::Drawing::front_view(std::vector<Geometric::ILine*> value)
{
	front_view_ = value;
}

std::vector<Core::Objects::Geometric::ILine*> Core::Objects::Visual::Drawing::top_view() const
{
	return top_view_;
}

void Core::Objects::Visual::Drawing::top_view(std::vector<Geometric::ILine*> value)
{
	top_view_ = value;
}

std::vector<Core::Objects::Geometric::ILine*> Core::Objects::Visual::Drawing::side_view() const
{
	return side_view_;
}

void Core::Objects::Visual::Drawing::side_view(std::vector<Geometric::ILine*> value)
{
	side_view_ = value;
}
