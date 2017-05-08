#ifndef CORE_TRANSFORMATION_INOISEREMOVER_H
#define CORE_TRANSFORMATION_INOISEREMOVER_H

#include "ITransformation.h"

namespace Core
{
	namespace Transformation
	{
		class INoiseRemover : public ITransformation
		{
		public:
			virtual ~INoiseRemover()
			{
			}
		};
	}
}

#endif
