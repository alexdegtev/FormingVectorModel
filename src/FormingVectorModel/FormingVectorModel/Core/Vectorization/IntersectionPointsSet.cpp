#include "IntersectionPointsSet.h"
#include "../Objects/Geometric/Point.h"

Core::Vectorization::IntersectionPointsSet::IntersectionPointsSet()
{
}

Core::Vectorization::IntersectionPointsSet::~IntersectionPointsSet()
{
}

Core::Vectorization::IntersectionPoint* Core::Vectorization::IntersectionPointsSet::get(int row, int col)
{
	for (auto i : points)
	{
		if (i->x() == row && i->y() == col)
		{
			return i;
		}
	}

	IntersectionPoint* point = new IntersectionPoint(new Objects::Geometric::Point(row, col));
	points.push_back(point);

	return point;
}

Core::Vectorization::IntersectionPoint* Core::Vectorization::IntersectionPointsSet::get(Objects::Geometric::IPoint* point)
{
	return get(point->x(), point->y());
}

bool Core::Vectorization::IntersectionPointsSet::is_exist(int row, int col)
{
	for (auto i : points)
	{
		if (i->x() == row && i->y() == col)
		{
			return true;
		}
	}

	return false;
}

bool Core::Vectorization::IntersectionPointsSet::is_exist(Objects::Geometric::IPoint* point)
{
	return is_exist(point->x(), point->y());
}
