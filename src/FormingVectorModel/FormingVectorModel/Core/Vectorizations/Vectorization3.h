#ifndef CORE_VECTORIZATIONS_VECTORIZATION3_H
#define CORE_VECTORIZATIONS_VECTORIZATION3_H

#include "IVectorization.h"
#include "../Objects/Geometric/IPoint.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Geometric/ILine.h"
#include "ImageWithVisitedMarks.h"
#include "VectorizationState.h"

namespace Core
{
	namespace Vectorizations
	{
		class Vectorization3 : public IVectorization
		{
		public:
			std::vector<Objects::Geometric::IObject*> execute(Objects::Visual::IImage* image) override;

		private:
			ImageWithVisitedMarks *iwvm;
			VectorizationState *vs;
			std::vector<Core::Objects::Geometric::IObject*> objects;
			void add_object(Objects::Geometric::ILine *line);
		};
	}
}

#endif
