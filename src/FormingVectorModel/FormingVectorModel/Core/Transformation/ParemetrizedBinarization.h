#ifndef CORE_TRANSFORMATION_PAREMETRIZEDBINARIZATION_H
#define CORE_TRANSFORMATION_PAREMETRIZEDBINARIZATION_H

#include "IBinarization.h"

namespace Core
{
	namespace Transformation
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
