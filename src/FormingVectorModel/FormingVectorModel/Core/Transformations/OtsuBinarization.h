#ifndef CORE_TRANSFORMATIONS_OTSUBINARIZATION_H
#define CORE_TRANSFORMATIONS_OTSUBINARIZATION_H

#include "IBinarization.h"
#include <vector>

namespace Core
{
	namespace Transformations
	{
		class OtsuBinarization : public IBinarization
		{
		public:
			void execute(Objects::Visual::IImage* image) override;

		private:
			Objects::Visual::IImage* image;

			unsigned char threshold();
			std::vector<int> get_histogram(int *min, int *max);
		};
	}
}

#endif
