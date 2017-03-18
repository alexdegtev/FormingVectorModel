#include "IntersectionPoint.h"
#include "../Objects/Geometric/Point.h"

Core::Vectorizations::IntersectionPoint::IntersectionPoint(IPoint* point) : _point(point)
{
	if (_point == nullptr)
	{
		_point = new Objects::Geometric::Point();
	}
}

int Core::Vectorizations::IntersectionPoint::x() const
{
	return _point->x();
}

int Core::Vectorizations::IntersectionPoint::y() const
{
	return _point->y();
}

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::IntersectionPoint::intersected_objects() const
{
	return _intersected_objects;
}

void Core::Vectorizations::IntersectionPoint::add_object(IObject* object)
{
	_intersected_objects.push_back(object);
}
