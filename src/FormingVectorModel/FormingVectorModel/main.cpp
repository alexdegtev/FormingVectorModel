#include <iostream>
#include <cstring>
#include "Core/IO/Path.h"
#include "Core/Objects/Visual/IImage.h"
#include "Core/IO/Reader.h"
#include "Core/IO/Writer.h"
#include "opencv2/opencv.hpp"
#include "Core/Objects/Visual/Color.h"
#include "Core/Transformation/YIQGrayscalation.h"
#include "Core/Transformation/Invertation.h"
#include "Core/Transformation/MiddleThresholdBinarization.h"
#include "Core/Transformation/ZhangSuenSkeletization.h"
#include "Core/Transformation/GuoHallSkeletization.h"
#include "Core/Vectorization/Vectorization.h"
#include "Core/Objects/Geometric/ILine.h"
#include "Tests/Vectorization/VectorizationTests.h"
#include "Core/Transformation/NoiseRemover.h"
#include "Core/Transformation/OtsuBinarization.h"
#include "Core/Transformation/ParemetrizedBinarization.h"
#include "Core/Transformation/SingleNoisePointsRemover.h"

void grayscalation(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "grayscalation (YIQGrayscalation)... ";
	image->transform(new Core::Transformation::YIQGrayscalation);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

void invertation(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "invertation (Invertation)... ";
	image->transform(new Core::Transformation::Invertation);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

void binarization_MiddleThresholdBinarization(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "binarization (MiddleThresholdBinarization)... ";
	image->transform(new Core::Transformation::MiddleThresholdBinarization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

void binarization_OtsuBinarization(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "binarization (OtsuBinarization)... ";
	image->transform(new Core::Transformation::OtsuBinarization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

void binarization_ParemetrizedBinarization(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, int threshold, bool write_result = true)
{
	std::cout << "binarization (ParemetrizedBinarization)... ";
	image->transform(new Core::Transformation::ParemetrizedBinarization(threshold));

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

void singleNoisePointsRemover(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "noise removing (SingleNoisePointsRemover)... ";
	image->transform(new Core::Transformation::SingleNoisePointsRemover);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

void skeletization_ZhangSuenSkeletization(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "skeletization (ZhangSuenSkeletization)... ";
	image->transform(new Core::Transformation::ZhangSuenSkeletization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

void skeletization_GuoHallSkeletization(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "skeletization (GuoHallSkeletization)... ";
	image->transform(new Core::Transformation::GuoHallSkeletization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;
}

std::vector<Core::Objects::Geometric::IObject*> vectorization(Core::Objects::Visual::IImage* image, Core::IO::Path output_path, bool write_result = true)
{
	std::cout << "vectorization...";
	std::vector<Core::Objects::Geometric::IObject*> result = image->vectorize(new Core::Vectorization::Vectorization);

	if (write_result) {
		std::cout << "writing...";
		Core::IO::Writer::write(output_path, image);
	}

	std::cout << std::endl;

	return result;
}

// ../../../data/4.png true grayscalation invertation otsuBinarization noiseRemove guoHallSkeletization vectorization
int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		std::cout << "<program_name> <image_name>" << std::endl;
	}
	else
	{
		if (strcmp(argv[1], "/debug") == 0)
		{
			if (strcmp(argv[2], "/tests") == 0)
			{
				VectorizationTests vt;
				vt.run_all_tests();
			}
		}
		else
		{
			Core::IO::Path path(argv[1]);
			Core::Objects::Visual::IImage* image = Core::IO::Reader::read(path);

			bool write_intermediate_results = strcmp(argv[2], "true") == 0;
			int command_counter = 1;

			for (int i = 3; i < argc; i++)
			{
				if (strcmp(argv[i], "grayscalation") == 0)
				{
					grayscalation(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_YIQGrayscalation", path.file_extention()), write_intermediate_results);
				}
				else if (strcmp(argv[i], "invertation") == 0)
				{
					invertation(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_Invertation", path.file_extention()), write_intermediate_results);
				}
				else if (strcmp(argv[i], "middleThresholdBinarization") == 0)
				{
					binarization_MiddleThresholdBinarization(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_MiddleThresholdBinarization", path.file_extention()), write_intermediate_results);
				}
				else if (strcmp(argv[i], "otsuBinarization") == 0)
				{
					binarization_OtsuBinarization(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_OtsuBinarization", path.file_extention()), write_intermediate_results);
				}
				else if (strcmp(argv[i], "paremetrizedBinarization") == 0)
				{
					i++;
					int threshold = std::stoi(argv[i]);
					binarization_ParemetrizedBinarization(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_ParemetrizedBinarization", path.file_extention()), threshold, write_intermediate_results);
				}
				else if (strcmp(argv[i], "noiseRemove") == 0)
				{
					singleNoisePointsRemover(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_SingleNoisePointsRemover", path.file_extention()), write_intermediate_results);
				}
				else if (strcmp(argv[i], "zhangSuenSkeletization") == 0)
				{
					skeletization_ZhangSuenSkeletization(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_ZhangSuenSkeletization", path.file_extention()), write_intermediate_results);
				}
				else if (strcmp(argv[i], "guoHallSkeletization") == 0)
				{
					skeletization_GuoHallSkeletization(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_GuoHallSkeletization", path.file_extention()), write_intermediate_results);
				}
				else if (strcmp(argv[i], "vectorization") == 0)
				{
					i++;
					std::vector<Core::Objects::Geometric::IObject*> objects = ::vectorization(image, Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_Vectorization", path.file_extention()), write_intermediate_results);
					Core::IO::Writer::write(Core::IO::Path(path.path_to_file(), path.file_name() + "_out_" + std::to_string(command_counter++) + "_Vectorization", argv[i]), objects, image);
				}
			}

			delete image;
		}
	}

	return 0;
}
