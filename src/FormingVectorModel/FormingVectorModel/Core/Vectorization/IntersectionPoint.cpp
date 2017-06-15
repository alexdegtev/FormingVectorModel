#include "IntersectionPoint.h"
#include "../Objects/Geometric/Point.h"

Core::Vectorization::IntersectionPoint::IntersectionPoint(Objects::Geometric::IPoint* point) : _point(point)
{
	if (_point == nullptr)
	{
		_point = new Objects::Geometric::Point();
	}
}

int Core::Vectorization::IntersectionPoint::x() const
{
	return _point->x();
}

int Core::Vectorization::IntersectionPoint::y() const
{
	return _point->y();
}

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorization::IntersectionPoint::intersected_objects() const
{
	return _intersected_objects;
}

void Core::Vectorization::IntersectionPoint::add_object(Objects::Geometric::IObject* object)
{
	_intersected_objects.push_back(object);
}

std::string Core::Vectorization::IntersectionPoint::to_string()
{
	throw;
}

std::vector<Core::Vectorization::IntersectionPoint*> Core::Vectorization::IntersectionPoint::get_intersections()
{
	std::vector<IntersectionPoint*> s;
	return s;
}


