#include <iostream>
#include <cstring>
#include "Core/IO/Path.h"
#include "Core/Objects/Visual/IImage.h"
#include "Core/IO/Reader.h"
#include "Core/IO/Writer.h"
#include "opencv2/opencv.hpp"
#include "Core/Objects/Visual/Color.h"
#include "Core/Transformations/YIQGrayscalation.h"
#include "Core/Transformations/Invertation.h"
#include "Core/Transformations/MiddleThresholdBinarization.h"
#include "Core/Transformations/ZhangSuenSkeletization.h"
#include "Core/Transformations/GuoHallSkeletization.h"
#include "Core/Vectorizations/Vectorization.h"
#include "Core/Objects/Geometric/ILine.h"
#include "Tests/Vectorization/VectorizationTests.h"

void grayscalation(Core::Objects::Visual::IImage* image, Core::IO::Path path)
{
	std::cout << "grayscalation (YIQGrayscalation)..." << std::endl;
	image->transform(new Core::Transformations::YIQGrayscalation);

	std::cout << "writing..." << std::endl;
	Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_1_YIQGrayscalation", path.file_extention()), image);
}

void invertation(Core::Objects::Visual::IImage* image, Core::IO::Path path)
{
	std::cout << "invertation (Invertation)..." << std::endl;
	image->transform(new Core::Transformations::Invertation);

	std::cout << "writing..." << std::endl;
	Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_2_Invertation", path.file_extention()), image);
}

void binarization_MiddleThresholdBinarization(Core::Objects::Visual::IImage* image, Core::IO::Path path)
{
	std::cout << "binarization (MiddleThresholdBinarization)..." << std::endl;
	image->transform(new Core::Transformations::MiddleThresholdBinarization);

	std::cout << "writing..." << std::endl;
	Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_3_MiddleThresholdBinarization", path.file_extention()), image);
}

void skeletization_ZhangSuenSkeletization(Core::Objects::Visual::IImage* image, Core::IO::Path path)
{
	std::cout << "skeletization (ZhangSuenSkeletization)..." << std::endl;
	image->transform(new Core::Transformations::ZhangSuenSkeletization);

	std::cout << "writing..." << std::endl;
	Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_4_ZhangSuenSkeletization", path.file_extention()), image);
}

void skeletization_GuoHallSkeletization(Core::Objects::Visual::IImage* image, Core::IO::Path path)
{
	std::cout << "skeletization (ZhangSuenSkeletization)..." << std::endl;
	image->transform(new Core::Transformations::GuoHallSkeletization);

	std::cout << "writing..." << std::endl;
	Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_4_GuoHallSkeletization", path.file_extention()), image);
}

std::vector<Core::Objects::Geometric::IObject*> vectorization(Core::Objects::Visual::IImage* image, Core::IO::Path path)
{
	std::cout << "vectorization" << std::endl;
	std::vector<Core::Objects::Geometric::IObject*> result;// = image->vectorize(new Core::Vectorizations::Vectorization);

	std::cout << "writing..." << std::endl;
	Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_5_Vectorization", path.file_extention()), image);

	return result;
}



int main(int argc, char* argv[])
{
	//std::string path = argv[1];
	//cv::Mat mat = cv::imread(path);
	//Core::Objects::Visual::Color *colors = new Core::Objects::Visual::Color[mat.rows * mat.cols];

	//for (int i = 0; i < mat.rows; i++)
	//{
	//	for (int j = 0; j < mat.cols; j++)
	//	{
	//		cv::Vec3b row_color = mat.at<cv::Vec3b>(i, j);
	//		colors[i * mat.cols + j] = Core::Objects::Visual::Color(row_color.val[2], row_color.val[1], row_color.val[0]);
	//	}
	//}

	//std::cout << '\t' << "(0, 0): " << (int)colors[0 * mat.cols + 0].red() << std::endl;
	//std::cout << '\t' << "(0, 1): " << (int)colors[0 * mat.cols + 1].red() << std::endl;

	//Core::Objects::Visual::IColor *ic = &colors[0 * mat.cols + 1];
	//std::cout << '\t' << "(0, 1): " << (int)ic->red() << std::endl;


	//delete[] colors;
	//return 0;


	//std::cout << "params:" << std::endl;
	//for (int i = 0; i < argc; i++)
	//{
	//	std::cout << '\t' << "[" << i << "]: " << argv[i] << std::endl;
	//}

	switch (argc)
	{
	case 2:
		if (strcmp(argv[1], "help") == 0)
		{
			std::cout << "<program_name> <image_name>" << std::endl;
		}
		else
		{
			std::cout << "starting..." << std::endl;

			std::cout << "reading..." << std::endl;
			Core::IO::Path path(argv[1]);
			Core::Objects::Visual::IImage* image = Core::IO::Reader::read(path);

			std::cout << "image:" << std::endl;
			std::cout << '\t' << "rows (height): " << image->rows() << std::endl;
			std::cout << '\t' << "cols (width): " << image->cols() << std::endl;
			std::cout << '\t' << "(0, 0): " << (int)image->get(0, 0)->blue() << std::endl;
			std::cout << '\t' << "(0, 1): " << (int)image->get(0, 1)->red() << std::endl;

			grayscalation(image, path);
			invertation(image, path);
			binarization_MiddleThresholdBinarization(image, path);
			//skeletization_ZhangSuenSkeletization(image, path);
			skeletization_GuoHallSkeletization(image, path);

			std::cout << "end." << std::endl;
			delete image;
		}

		break;

	case 3:
		if (strcmp(argv[1], "/debug") == 0)
		{
			if(strcmp(argv[2], "/tests") == 0)
			{
				VectorizationTests vt;
				vt.run_all_tests();
			}
		}
		break;

	case 4:
		if (strcmp(argv[1], "/debug") == 0)
		{
			if (strcmp(argv[2], "vectorize") == 0)
			{
				Core::IO::Path path(argv[3]);
				Core::Objects::Visual::IImage* image = Core::IO::Reader::read(path);

				std::vector<Core::Objects::Geometric::IObject*> objects = vectorization(image, path);
				for (auto obj : objects)
				{
					Core::Objects::Geometric::ILine* l = (Core::Objects::Geometric::ILine*)obj;
					std::cout << "[(" << l->begin()->x() << ";" << l->begin()->y() << "),(" << l->end()->x() << ";" << l->end()->y() << ")]" << std::endl;
				}

				std::cout << "end." << std::endl;
				delete image;
			}

		}
		break;

	default:
		std::cout << "use help" << std::endl;
		break;
	}


	return 0;
}
