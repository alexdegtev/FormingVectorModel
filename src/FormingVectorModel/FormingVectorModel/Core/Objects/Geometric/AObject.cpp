#include "AObject.h"

Core::Vectorizations::IntersectionPoint* Core::Objects::Geometric::AObject::intersection_point() const
{
	return _intersection_point;
}

void Core::Objects::Geometric::AObject::intersection_point(Vectorizations::IntersectionPoint* value)
{
	_intersection_point = value;
}
