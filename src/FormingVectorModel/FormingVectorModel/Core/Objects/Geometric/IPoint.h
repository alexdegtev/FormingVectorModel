#ifndef CORE_OBJECTS_GEOMETRIC_IPOINT_H
#define CORE_OBJECTS_GEOMETRIC_IPOINT_H

#include "AObject.h"

namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class IPoint : public AObject
			{
			public:
				virtual ~IPoint()
				{
				}

				virtual int x() const = 0;
				virtual int y() const = 0;
			};

			inline bool operator==(const IPoint& lhs, const IPoint& rhs)
			{
				return lhs.x() == rhs.x() && lhs.y() == rhs.y();
			}
		}
	}
}

#endif
