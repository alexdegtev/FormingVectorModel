#ifndef CORE_VECTORIZATIONS_VECTORIZATION2_H
#define CORE_VECTORIZATIONS_VECTORIZATION2_H

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
		class Vectorization2 : public IVectorization
		{
		public:
			std::vector<Objects::Geometric::IObject*> execute(Objects::Visual::IImage* image) override;

		private:
			ImageWithVisitedMarks *iwvm;
			VectorizationState *vs;
			std::vector<Core::Objects::Geometric::IObject*> objects;
			void add_object_with_resolving_dependences(Objects::Geometric::ILine *line);
		};
	}
}

#endif
