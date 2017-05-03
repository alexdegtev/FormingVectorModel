#include "Vectorization.h"
#include "VectorizationState.h"

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization::execute(Objects::Visual::IImage* image)
{
	VectorizationState *vs = nullptr;
	ImageWithVisitedMarks *image_ = new ImageWithVisitedMarks(image);
	std::vector<Core::Objects::Geometric::IObject*> objects;

	while (image_->has_unvisited_pixels())
	{
		if(vs == nullptr)
		{
			
		}
	}




	if (image_) delete image_;
	if (vs) delete vs;

	return objects;
}
