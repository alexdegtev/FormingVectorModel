#ifndef CORE_TRANSFORMATION_SINGLENOISEPOINTSREMOVER_H
#define CORE_TRANSFORMATION_SINGLENOISEPOINTSREMOVER_H

#include "INoiseRemover.h"

namespace Core
{
	namespace Transformation
	{
		class SingleNoisePointsRemover : public INoiseRemover
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
