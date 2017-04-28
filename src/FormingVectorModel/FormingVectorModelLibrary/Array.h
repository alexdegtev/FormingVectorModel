#pragma once

namespace MyObjects {
	class Array
	{
	public:
		Array(int size);
		~Array();
		int get(int index);
		void set(int index, int value);

	private:
		int size;
		int *data;
	};
}