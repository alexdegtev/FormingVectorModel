#ifndef CORE_TRANSFORMATIONS_SINGLENOISEPOINTSREMOVER_H
#define CORE_TRANSFORMATIONS_SINGLENOISEPOINTSREMOVER_H

#include "INoiseRemover.h"

namespace Core
{
	namespace Transformations
	{
		class SingleNoisePointsRemover : public INoiseRemover
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
