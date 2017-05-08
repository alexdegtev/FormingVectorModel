#ifndef CORE_OBJECTS_GEOMETRIC_AOBJECT_H
#define CORE_OBJECTS_GEOMETRIC_AOBJECT_H

#include "IObject.h"

namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class AObject : public IObject
			{
			public:
				virtual ~AObject() { }
			};
		}
	}
}

#endif
