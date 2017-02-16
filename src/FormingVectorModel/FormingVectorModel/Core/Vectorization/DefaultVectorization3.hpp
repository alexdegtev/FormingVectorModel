#ifndef FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION3_HPP
#define FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION3_HPP

#include "IVectorization.hpp"
#include "../Objects/Geometric/IPoint.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Vectorization
		{


			class VectorizationState
			{
			public:
				VectorizationState(){}

				Objects::Geometric::IPoint previous(){}
				Objects::Geometric::IPoint current
				

			private:

			};

			class DefaultVectorization3 : public IVectorization
			{
			public:
				DefaultVectorization3(){}

				std::vector<Objects::Geometric::IObject*> vectorizate(Objects::Image::IImage* image) override{
					throw;
				}
			};
		}
	}
}
#endif
