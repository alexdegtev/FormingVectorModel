#ifndef CORE_TRANSFORMATIONS_OTSUBINARIZATION_H
#define CORE_TRANSFORMATIONS_OTSUBINARIZATION_H

#include "IBinarization.h"

namespace Core
{
	namespace Transformations
	{
		class OtsuBinarization : public IBinarization
		{
		public:
			void execute(Objects::Visual::IImage* image) override;

		private:
			unsigned char threshold(Objects::Visual::IImage* image);
		};
	}
}

#endif
