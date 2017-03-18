#ifndef CORE_OBJECTS_GEOMETRIC_ILINE_H
#define CORE_OBJECTS_GEOMETRIC_ILINE_H

#include "IPoint.h"

namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class ILine : public AObject
			{
			public:
				virtual ~ILine()
				{
				}

				virtual IPoint* begin() const = 0;
				virtual IPoint* end() const = 0;
			};

			inline bool operator==(const ILine& lhs, const ILine& rhs)
			{
				return *(lhs.begin()) == *(rhs.begin()) && *(lhs.end()) == *(rhs.end());
			}
		}
	}
}

#endif
