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
#include "Core/Transformations/NoiseRemover.h"
#include "Core/Transformations/OtsuBinarization.h"
#include "Core/Transformations/ParemetrizedBinarization.h"
#include "Core/Transformations/SingleNoisePointsRemover.h"

void grayscalation(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "grayscalation (YIQGrayscalation)... ";
	image->transform(new Core::Transformations::YIQGrayscalation);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_1_YIQGrayscalation", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void invertation(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "invertation (Invertation)... ";
	image->transform(new Core::Transformations::Invertation);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_2_Invertation", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void binarization_MiddleThresholdBinarization(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "binarization (MiddleThresholdBinarization)... ";
	image->transform(new Core::Transformations::MiddleThresholdBinarization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_3_MiddleThresholdBinarization", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void binarization_OtsuBinarization(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "binarization (OtsuBinarization)... ";
	image->transform(new Core::Transformations::OtsuBinarization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_3_OtsuBinarization", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void binarization_ParemetrizedBinarization(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "binarization (ParemetrizedBinarization)... ";
	image->transform(new Core::Transformations::ParemetrizedBinarization(200));

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_3_ParemetrizedBinarization", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void noiseRemover(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "noise removing (NoiseRemover)... ";
	image->transform(new Core::Transformations::NoiseRemover);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_4_NoiseRemover", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void singleNoisePointsRemover(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "noise removing (SingleNoisePointsRemover)... ";
	image->transform(new Core::Transformations::SingleNoisePointsRemover);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_4_SingleNoisePointsRemover", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void skeletization_ZhangSuenSkeletization(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "skeletization (ZhangSuenSkeletization)... ";
	image->transform(new Core::Transformations::ZhangSuenSkeletization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_5_ZhangSuenSkeletization", path.file_extention()), image);
	}

	std::cout << std::endl;
}

void skeletization_GuoHallSkeletization(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "skeletization (GuoHallSkeletization)... ";
	image->transform(new Core::Transformations::GuoHallSkeletization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_5_GuoHallSkeletization", path.file_extention()), image);
	}

	std::cout << std::endl;
}

std::vector<Core::Objects::Geometric::IObject*> vectorization(Core::Objects::Visual::IImage* image, Core::IO::Path path, bool write_result = true)
{
	std::cout << "vectorization ";
	std::vector<Core::Objects::Geometric::IObject*> result;// = image->vectorize(new Core::Vectorizations::Vectorization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_6_Vectorization", path.file_extention()), image);
	}

	std::cout << std::endl;

	return result;
}



int main(int argc, char* argv[])
{
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
			std::cout << "    " << "rows (height): " << image->rows() << std::endl;
			std::cout << "    " << "cols (width): " << image->cols() << std::endl;
			

			bool write_result = true;
			grayscalation(image, path, write_result);

			invertation(image, path, write_result);

			//binarization_MiddleThresholdBinarization(image, path, write_result);
			binarization_OtsuBinarization(image, path, write_result);

			//noiseRemover(image, path, write_result);
			singleNoisePointsRemover(image, path, write_result);

			//skeletization_ZhangSuenSkeletization(image, path, write_result);
			skeletization_GuoHallSkeletization(image, path, write_result);

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

	default:
		std::cout << "use help" << std::endl;
		break;
	}


	return 0;
}
