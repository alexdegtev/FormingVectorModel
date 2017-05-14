#include "Line.h"
#include "Point.h"
#include <sstream>
#include "../../Vectorization/IntersectionPoint.h"

Core::Objects::Geometric::Line::Line() : Line(nullptr, nullptr)
{
}

Core::Objects::Geometric::Line::Line(IPoint* begin, IPoint* end) : _begin(new Point(begin)), _end(new Point(end)), type_(Type::visible)
{
	if (!_begin)
		_begin = new Point();

	if (!_end)
		_end = new Point();
}

Core::Objects::Geometric::Line::Line(IPoint* begin, IPoint* end, std::vector<IPoint*> special_point) : Line(begin, end)
{
}

Core::Objects::Geometric::Line::Line(Point begin, Point end) : Line(new Point(begin.x(), begin.y()), new Point(end.x(), end.y()))
{
}

Core::Objects::Geometric::Line::Line(IPoint* begin, IPoint* end, std::vector<Vectorization::IntersectionPoint*> intersections) : Line(begin, end)
{
	intersections_ = intersections;

	for (auto i : intersections_)
	{
		i->add_object(this);
	}
}

Core::Objects::Geometric::Line::Line(IPoint* begin, IPoint* end, std::set<Vectorization::IntersectionPoint*> intersections) : Line(begin, end)
{
	for(auto i : intersections)
	{
		intersections_.push_back(i);
	}

	for (auto i : intersections_)
	{
		i->add_object(this);
	}
}

Core::Objects::Geometric::Line::~Line()
{
	if (_begin)
		delete _begin;

	if (_end)
		delete _end;
}

Core::Objects::Geometric::IPoint* Core::Objects::Geometric::Line::begin() const
{
	return _begin;
}

Core::Objects::Geometric::IPoint* Core::Objects::Geometric::Line::end() const
{
	return _end;
}

std::string Core::Objects::Geometric::Line::to_string()
{
	std::stringstream ss;

	ss << "<line type=\"main\">" << std::endl
		<< "\t" << _begin->to_string() << std::endl
		<< "\t" << _end->to_string() << std::endl
		<< "</line>" << std::endl;

	return ss.str();
}

Core::Objects::Geometric::ILine::Type Core::Objects::Geometric::Line::type() const
{
	return type_;
}

void Core::Objects::Geometric::Line::type(Type value)
{
	type_ = value;
}
