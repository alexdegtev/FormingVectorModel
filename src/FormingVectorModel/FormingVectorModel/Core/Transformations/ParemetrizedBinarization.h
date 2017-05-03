#ifndef CORE_TRANSFORMATIONS_PAREMETRIZEDBINARIZATION_H
#define CORE_TRANSFORMATIONS_PAREMETRIZEDBINARIZATION_H

#include "IBinarization.h"

namespace Core
{
	namespace Transformations
	{
		class ParemetrizedBinarization : public IBinarization
		{
		public:
			ParemetrizedBinarization(int threshold);
			void execute(Objects::Visual::IImage* image) override;

		private:
			int threshold_;
		};
	}
}

#endif
