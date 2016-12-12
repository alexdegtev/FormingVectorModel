#ifndef FVM_CORE_TRANSFORMATIONS_ITRANSFORMATION_HPP
#define FVM_CORE_TRANSFORMATIONS_ITRANSFORMATION_HPP

namespace FVM {
	namespace Core {
		namespace Objects {
			namespace Image {
				class IImage;
			}
		}
	}
}

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class ITransformation
			{
			public:
				virtual ~ITransformation() {}
				virtual void execute(Objects::Image::IImage *image) = 0;
			};
		}
	}
}
#endif
