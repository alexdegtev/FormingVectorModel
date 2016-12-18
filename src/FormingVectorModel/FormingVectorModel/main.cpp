#include "Core/Objects/Image/IImage.hpp"
#include "Core/IO/Reader.hpp"
#include "Core/IO/Writer.hpp"
#include <iostream>
#include "Core/Transformations/YIQGrayscale.hpp"
#include "Core/Transformations/OtsuBinarization.hpp"
#include "Core/Transformations/GuoHallSkeletization.hpp"
#include "Core/Transformations/ZhangSuenSkeletization.hpp"
#include "Core/Common/Types/Array.hpp"
#include <array>
#include "Core/Common/Types/Matrix.hpp"
#include "Core/Objects/Geometric/Line.hpp"
#include "Core/Vectorization/DefaultVectorization.hpp"

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

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\2_s.jpg", image);

	delete image;
}

void test_transform_image_to_grayscale()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale());

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1_s.jpg", image);

	delete image;
}

void test_binarization_image()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale);
	image->transform(new FVM::Core::Transformations::OtsuBinarization);

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\1_s.jpg", image);

	delete image;
}

void test_guo_hall_skeletization()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\5.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale);
	image->transform(new FVM::Core::Transformations::OtsuBinarization);
	image->transform(new FVM::Core::Transformations::GuoHallSkeletization);

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\5_s.jpg", image);

	delete image;
}

void test_zhang_suen_skeletization()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\5.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale);
	image->transform(new FVM::Core::Transformations::OtsuBinarization);
	image->transform(new FVM::Core::Transformations::ZhangSuenSkeletization);

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\5_s.jpg", image);

	delete image;
}

void test_array_type_size()
{
	FVM::Core::Common::Types::Array<int, 10> a;
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	FVM::Core::Common::Types::Array<int, 10> b;
	for (int i = 0; i < b.size(); i++)
		b[i] = i;
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	a = b;
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	a[5] = 0;
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
}

void test_array_type()
{
	FVM::Core::Common::Types::Array<int> a(10);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	FVM::Core::Common::Types::Array<int> b(11);
	for (int i = 0; i < b.size(); i++)
		b[i] = i;
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	a = b;
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	a[5] = 0;
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
}


int main()
{
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\13.png");

	FVM::Core::Vectorization::DefaultVectorization dv;
	std::vector<FVM::Core::Objects::Geometric::IObject*> lines = dv.vectorizate(image);

	for (int i = 0; i < lines.size(); i++)
	{
		Line *l = static_cast<Line*>(lines[i]);
		std::cout << l->p1().x() << " " << l->p1().y() << std::endl << l->p2().x() << " " << l->p2().y() << std::endl << std::endl;
	}

	return 0;
}
