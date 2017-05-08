#ifndef CORE_VECTORIZATION_INTERSECTIONPOINTSSET_H
#define CORE_VECTORIZATION_INTERSECTIONPOINTSSET_H

#include <vector>
#include "IntersectionPoint.h"

namespace Core
{
	namespace Vectorization
	{
		class IntersectionPointsSet
		{
		public:
			IntersectionPointsSet();
			~IntersectionPointsSet();

			IntersectionPoint* get(int row, int col);
			IntersectionPoint* get(Objects::Geometric::IPoint* point);
			bool is_exist(int row, int col);
			bool is_exist(Objects::Geometric::IPoint* point);

		private:
			std::vector<IntersectionPoint*> points;
		};
	}
}
#endif