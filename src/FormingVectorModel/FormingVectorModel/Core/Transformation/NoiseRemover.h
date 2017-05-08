#ifndef CORE_TRANSFORMATION_NOISEREMOVER_H
#define CORE_TRANSFORMATION_NOISEREMOVER_H

#include "INoiseRemover.h"
#include <vector>
#include "../Objects/Visual/IColor.h"

namespace Core
{
	namespace Transformation
	{
		class NoiseRemover : public INoiseRemover
		{
		public:
			//NoiseRemover();
			void execute(Objects::Visual::IImage* image) override;

		private:
			//unsigned char get_dominant_color(std::vector<Objects::Visual::IColor*> colors);
			//unsigned char middle_color;
		};
	}
}

#endif
