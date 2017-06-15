#ifndef CORE_OBJECTS_GEOMETRIC_IOBJECT_H
#define CORE_OBJECTS_GEOMETRIC_IOBJECT_H

#include <string>
#include <vector>

namespace Core
{
	namespace Vectorization
	{
		class IntersectionPoint;
	}
}

namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class IObject
			{
			public:
				virtual ~IObject() { }

				virtual std::string to_string() = 0;
				virtual std::vector<Vectorization::IntersectionPoint*> get_intersections() = 0;
			};
		}
	}
}

#endif
