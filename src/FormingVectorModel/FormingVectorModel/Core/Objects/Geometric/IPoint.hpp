#ifndef FVM_CORE_OBJECTS_GEOMETRIC_IPOINT_HPP
#define FVM_CORE_OBJECTS_GEOMETRIC_IPOINT_HPP

#include "IObject.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Geometric
			{
				class IPoint : public IObject
				{
				public:
					IPoint(){}
					virtual ~IPoint(){}

					virtual int x() = 0;
					virtual int y() = 0;
				};
			}
		}
	}
}
#endif
