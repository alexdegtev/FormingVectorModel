#include "Writer.h"
#include "opencv2/opencv.hpp"
#include "../Objects/Visual/Color.h"
#include <iostream>
#include <fstream>
#include "../Objects/Visual/IImage.h"
#include "../Objects/Geometric/ILine.h"

void Core::IO::Writer::write(Path path, Objects::Visual::IImage* image)
{
	write_raster(path.full_path(), image);
}

void Core::IO::Writer::write(Path path, std::vector<Objects::Geometric::IObject*> objects, Objects::Visual::IImage* image)
{
	if (path.file_extention() == "svg")
	{
		write_svg(path.full_path(), objects, image);
	}
	else if (path.file_extention() == "xml")
	{
		write_xml(path.full_path(), objects);
	}
}

void Core::IO::Writer::write_raster(std::string path, Objects::Visual::IImage* image)
{
	cv::Mat mat(image->rows(), image->cols(), CV_8UC3);

	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Visual::IColor* color = image->get(i, j);
			mat.at<cv::Vec3b>(i, j) = cv::Vec3b(color->blue(), color->green(), color->red());
		}
	}

	cv::imwrite(path, mat);
}

void Core::IO::Writer::write_svg(std::string path, std::vector<Objects::Geometric::IObject*> objects, Objects::Visual::IImage* image)
{
	std::ofstream outfile(path);

	std::stringstream str;
	str << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\" width=\"" << image->rows() << "\" height=\"" << image->cols() << "\">" << std::endl;

	for (auto o : objects)
	{
		Objects::Geometric::ILine* l = (Objects::Geometric::ILine*)o;

		str << "\t"
			<< "<line x1=\"" << l->begin()->x() << "\" y1=\"" << l->begin()->y() << "\" "
			<< "x2=\"" << l->end()->x() << "\" y2=\"" << l->end()->y() << "\" "
			<< "stroke=\"rgb(0,0,0)\" />" << std::endl;
	}

	str << "</svg>" << std::endl;

	outfile << str.str() << std::endl;

	outfile.close();
}

void Core::IO::Writer::write_xml(std::string path, std::vector<Objects::Geometric::IObject*> objects)
{

}
