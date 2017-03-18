#ifndef CORE_TRANSFORMATIONS_ITRANSFORMATION_H
#define CORE_TRANSFORMATIONS_ITRANSFORMATION_H

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class IImage;
		}
	}
}

namespace Core
{
	namespace Transformations
	{
		class ITransformation
		{
		public:
			virtual ~ITransformation()
			{
			}

			virtual void execute(Objects::Visual::IImage* image) = 0;
		};
	}
}

#endif
