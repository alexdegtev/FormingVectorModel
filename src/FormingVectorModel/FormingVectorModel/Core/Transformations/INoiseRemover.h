#ifndef CORE_TRANSFORMATIONS_INOISEREMOVER_H
#define CORE_TRANSFORMATIONS_INOISEREMOVER_H

#include "ITransformation.h"

namespace Core
{
	namespace Transformations
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
