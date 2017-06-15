#pragma once

#include "../Objects/Geometric/IPoint.h"
#include <vector>

namespace Core
{
	namespace Vectorization
	{
		class IntersectionPoint //: //public Objects::Geometric::IPoint
		{
		public:
			IntersectionPoint(Objects::Geometric::IPoint *point);

			int x() const ;
			int y() const ;
			std::vector<Objects::Geometric::IObject*> intersected_objects() const;
			void add_object(Objects::Geometric::IObject *object);

			std::string to_string() ;

			std::vector<IntersectionPoint*> get_intersections() ;
		private:
			Objects::Geometric::IPoint *_point;
			std::vector<Objects::Geometric::IObject*> _intersected_objects;
		};
	}
}
