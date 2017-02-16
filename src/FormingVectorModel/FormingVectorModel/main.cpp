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
#include "Core/Vectorization/DefaultVectorization1.hpp"
#include "Core/Vectorization/DefaultVectorization2.hpp"

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
	FVM::Core::Objects::Image::IImage *image = FVM::Core::IO::Reader<FVM::Core::Objects::Image::DefaultImage>::read("d:\\C\\diplom_mag\\FormingVectorModel\\data\\2.jpg");

	image->transform(new FVM::Core::Transformations::YIQGrayscale);
	image->transform(new FVM::Core::Transformations::OtsuBinarization);
	image->transform(new FVM::Core::Transformations::GuoHallSkeletization);

	FVM::Core::IO::Writer::write("d:\\C\\diplom_mag\\FormingVectorModel\\data\\2_s.jpg", image);

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

void test_array_type()
{
	FVM::Core::Common::Types::Array<int> a(10);
	for (int i = 0; i < a.size(); i++)
		std::cout << a(i) << " ";
	std::cout << std::endl;

	FVM::Core::Common::Types::Array<int> b(11);
	for (int i = 0; i < b.size(); i++)
		b(i) = i;
	for (int i = 0; i < b.size(); i++)
		std::cout << b(i) << " ";
	std::cout << std::endl;

	a = b;
	for (int i = 0; i < a.size(); i++)
		std::cout << a(i) << " ";
	std::cout << std::endl;

	a(5) = 0;
	for (int i = 0; i < a.size(); i++)
		std::cout << a(i) << " ";
	std::cout << std::endl;
	for (int i = 0; i < b.size(); i++)
		std::cout << b(i) << " ";
	std::cout << std::endl;
}

bool test_image_1()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\1.png");
	if(image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if(lines.size() != 1) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(3, 1)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_2()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\2.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 1) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(3, 3)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_3()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\3.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 1) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(1, 3)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_4()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\4.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 2) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(3, 1)) return false;
	delete l;

	l = static_cast<Line*>(lines[1]);
	if (l->p1() != Point(1, 3) && l->p2() != Point(3, 3)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_5()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\5.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 2) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(3, 1)) return false;
	delete l;

	l = static_cast<Line*>(lines[1]);
	if (l->p1() != Point(3, 1) && l->p2() != Point(5, 3)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_6()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\6.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 3) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(2, 1)) return false;
	delete l;

	l = static_cast<Line*>(lines[1]);
	if (l->p1() != Point(2, 1) && l->p2() != Point(3, 2)) return false;
	delete l;

	l = static_cast<Line*>(lines[2]);
	if (l->p1() != Point(3, 2) && l->p2() != Point(3, 3)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_7()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\7.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 3) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(2, 1)) return false;
	delete l;

	l = static_cast<Line*>(lines[1]);
	if (l->p1() != Point(2, 1) && l->p2() != Point(3, 2)) return false;
	delete l;

	l = static_cast<Line*>(lines[2]);
	if (l->p1() != Point(3, 2) && l->p2() != Point(3, 3)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_8()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\8.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 3) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 2) && l->p2() != Point(2, 2)) return false;
	delete l;

	l = static_cast<Line*>(lines[1]);
	if (l->p1() != Point(2, 2) && l->p2() != Point(3, 1)) return false;
	delete l;

	l = static_cast<Line*>(lines[2]);
	if (l->p1() != Point(2, 2) && l->p2() != Point(3, 3)) return false;
	delete l;

	delete image;
	return true;
}

bool test_image_9()
{
	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\9.png");
	if (image == nullptr) return false;

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	if (lines.size() != 2) return false;

	Line *l = static_cast<Line*>(lines[0]);
	if (l->p1() != Point(1, 1) && l->p2() != Point(3, 1)) return false;
	delete l;

	l = static_cast<Line*>(lines[1]);
	if (l->p1() != Point(2, 1) && l->p2() != Point(3, 2)) return false;
	delete l;

	delete image;
	return true;
}

int main()
{
	std::cout << "image[" << 1 << "]: [ " << (test_image_1() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << "image[" << 2 << "]: [ " << (test_image_2() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << "image[" << 3 << "]: [ " << (test_image_3() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << "image[" << 4 << "]: [ " << (test_image_4() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << "image[" << 5 << "]: [ " << (test_image_5() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << "image[" << 6 << "]: [ " << (test_image_6() ? "OK" : "FAIL") << " ]" << std::endl;
	//std::cout << "image[" << 7 << "]: [ " << (test_image_7() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << "image[" << 8 << "]: [ " << (test_image_8() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << "image[" << 9 << "]: [ " << (test_image_9() ? "OK" : "FAIL") << " ]" << std::endl;


	IImage *image = FVM::Core::IO::Reader<DefaultImage>::read("..\\..\\..\\data\\1.png");

	FVM::Core::Vectorization::DefaultVectorization2 dv;
	std::vector<IObject*> lines = dv.vectorizate(image);

	for (int i = 0; i < lines.size(); i++)
	{
		Line *l = static_cast<Line*>(lines[i]);
		std::cout << l->p1().x() << " " << l->p1().y() << std::endl << l->p2().x() << " " << l->p2().y() << std::endl << std::endl;
	}

	return 0;
}
