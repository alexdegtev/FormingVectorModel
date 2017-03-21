#include "Line.h"
#include "Point.h"

Core::Objects::Geometric::Line::Line() : Line(nullptr, nullptr)
{
}

Core::Objects::Geometric::Line::Line(IPoint* begin, IPoint* end) : _begin(new Point(begin)), _end(new Point(end))
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
