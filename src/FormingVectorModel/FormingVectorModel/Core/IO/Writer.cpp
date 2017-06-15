#include "Writer.h"
#include "opencv2/opencv.hpp"
#include "../Objects/Visual/Color.h"
#include <iostream>
#include <fstream>
#include "../Objects/Visual/IImage.h"
#include "../Objects/Geometric/ILine.h"
#include <iterator>
#include <set>
#include "../Vectorization/IntersectionPoint.h"

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
	str << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\" width=\"" << image->cols() << "\" height=\"" << image->rows() << "\">" << std::endl;

	for (auto o : objects)
	{
		Objects::Geometric::ILine* l = (Objects::Geometric::ILine*)o;

		str << "\t"
			<< "<line x1=\"" << l->begin()->y() << "\" y1=\"" << l->begin()->x() << "\" "
			<< "x2=\"" << l->end()->y() << "\" y2=\"" << l->end()->x() << "\" "
			<< "stroke=\"rgb(0,0,0)\" />" << std::endl;
	}

	str << "</svg>" << std::endl;

	outfile << str.str() << std::endl;

	outfile.close();
}

void Core::IO::Writer::write_xml(std::string path, Objects::Visual::Drawing* drawing)
{
	std::ofstream outfile(path);
	int line_id = 0;
	int point_id = 0;

	std::stringstream str;
	str << "<?xml version=\"1.0\"?>" << std::endl
		<< "<Model xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">" << std::endl
		<< "	<proections>" << std::endl;
	

	str << "		<proection type=\"front\">" << std::endl
		<< "			<lines>" << std::endl;

	for(auto l : drawing->front_view())
	{
		str << "			<line id=\"" << line_id++ << "\" type=\"visible\">" << std::endl
			<< "				<points>" << std::endl
			<< "					<point id=\"" << point_id++ << "\" x=\"0\" y=\"" << l->begin()->x() << "\" z=\"" << l->begin()->y() << "\" />" << std::endl
			<< "					<point id=\"" << point_id++ << "\" x=\"0\" y=\"" << l->end()->x() << "\" z=\"" << l->end()->y() << "\" />" << std::endl
			<< "				</points>" << std::endl
			<< "			</line>" << std::endl;
	}

	str << "			</lines>" << std::endl
		<< "		</proection>" << std::endl;



	str << "	</proections>" << std::endl
		<< "</Model>" << std::endl;

	outfile << str.str() << std::endl;

	outfile.close();
}

void Core::IO::Writer::write_xml(std::string path, std::vector<Objects::Geometric::IObject*> objects)
{
	std::ofstream outfile(path);

	std::set<Vectorization::IntersectionPoint*> all_intersections_set;

	for (auto object : objects)
	{
		for(auto intersection : object->get_intersections())
		{
			all_intersections_set.insert(intersection);
		}
	}

	std::stringstream str;
	str << "<?xml version=\"1.0\"?>\n";
	str << "<Model xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">\n";
	str << "  <proections>\n";
	str << "    <proection type=\"front\">\n";
	str << "      <lines>\n";

	int point_id = 1;
	for(auto object : objects)
	{
		Objects::Geometric::ILine* l = (Objects::Geometric::ILine*)object;

		str << "        <line type=\"visible\" id=\"" << (int)object << "\">\n";
		str << "          <points>\n";
		str << "			<point id=\"" << point_id++ << "\" x=\"0\" y=\"" << l->begin()->x() << "\" z=\"" << l->begin()->y() << "\" />" << std::endl;
		str << "			<point id=\"" << point_id++ << "\" x=\"0\" y=\"" << l->end()->x() << "\" z=\"" << l->end()->y() << "\" />" << std::endl;
		str << "          </points>\n";
		str << "          <intersertion_points>\n";
		for(auto i : l->get_intersections())
		{
			str << "            <point id=\"" << (int) i << "\" />\n";
		}
		str << "          </intersertion_points>\n";
		str << "        </line>\n";
	}
	str << "        </line>\n";
	str << "      </lines>\n";
	str << "    </proection>\n";
	str << "  </proections>\n";

	str << "  <intersections>\n";
	for (auto i : all_intersections_set)
	{
		str << "    <intersertion_point id=\"" << (int) i << "\" x=\"" << i->x() << "\" y=\"" << i->y() << "\" z=\"0\">\n";
		str << "      <objects>\n";

		for(auto o : i->intersected_objects())
		{
			str << "        <line id=\"" << (int)o << "\" />\n";
		}

		str << "      </objects>\n";
		str << "    </intersertion_point>\n";

	}
	str << "  </intersections>\n";
	str << "</Model>\n";
	outfile << str.str() << std::endl;

	outfile.close();
}
