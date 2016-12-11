#include "Core/Objects/Image/IImage.hpp"
#include "Core/IO/Reader.hpp"
#include "Core/IO/Writer.hpp"
#include <iostream>

int main()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\2.jpg");
	//delete image;

	//system("pause");

	/*for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			std::cout << *image->pixel(i, j) << std::endl;
		}
	}*/

	system("pause");

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\2_s.jpg", image);

	system("pause");

	delete image;

	system("pause");

	return 0;
}
