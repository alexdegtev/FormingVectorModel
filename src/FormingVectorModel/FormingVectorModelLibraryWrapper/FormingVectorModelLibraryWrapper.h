// FormingVectorModelLibraryWrapper.h

#pragma once
#include "Array.h"

using namespace System;

namespace FormingVectorModelLibraryWrapper
{
	namespace MyObjects
	{
		public ref class Array
		{
		public:
			Array(int size)
			{
				data = new ::MyObjects::Array(size);
			}

			~Array()
			{
				delete data;
			}

			int get(int index)
			{
				return data->get(index);
			}

			void set(int index, int value)
			{
				data->set(index, value);
			}

		private:
			::MyObjects::Array *data;
		};
	}
}
