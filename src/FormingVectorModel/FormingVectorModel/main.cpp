#include "Core/Objects/Image/IImage.hpp"
#include "Core/IO/Reader.hpp"
#include "Core/IO/Writer.hpp"
#include <iostream>
#include "Core/Transformations/YIQGrayscale.hpp"
#include "Core/Transformations/OtsuBinarization.hpp"

void test_open_and_writing_image()
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
}

void test_transform_image_to_grayscale()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale());

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1_s.jpg", image);

	system("pause");

	delete image;
}

void test_binarization_image()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale);
	image->transform(new FVM::Core::Transformations::OtsuBinarization);

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1_s.jpg", image);

	system("pause");

	delete image;
}

int main()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale);
	image->transform(new FVM::Core::Transformations::OtsuBinarization);

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1_s.jpg", image);

	system("pause");

	delete image;

	system("pause");

	return 0;
}
