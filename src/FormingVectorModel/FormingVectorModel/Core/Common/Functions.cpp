#include "Functions.h"
#include <cmath>
#include "../Objects/Visual/IColor.h"
#include "../Objects/Visual/Color.h"

unsigned char Core::Common::Functions::rgb_to_brightness(unsigned char red, unsigned char green, unsigned char blue)
{
	return static_cast<unsigned char>(round(
		0.299 * static_cast<double>(red) +
		0.587 * static_cast<double>(green) +
		0.114 * static_cast<double>(blue)
	)); // From YIQ model.
}

void Core::Common::Functions::iimage_to_mat(Objects::Visual::IImage* image, cv::Mat* mat)
{
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			if (mat->channels() == 1)
			{
				mat->at<uchar>(i, j) = image->get(i, j)->brightness();
			}
			else
			{
				Objects::Visual::IColor* color = image->get(i, j);
				mat->at<cv::Vec3b>(i, j) = cv::Vec3b(color->blue(), color->green(), color->red());
			}
		}
	}
}

void Core::Common::Functions::mat_to_iimage(cv::Mat* mat, Objects::Visual::IImage* image)
{
	for (int i = 0; i < mat->rows; i++)
	{
		for (int j = 0; j < mat->cols; j++)
		{
			if (mat->channels() == 1)
			{
				Objects::Visual::Color color(mat->at<uchar>(i, j));
				image->set(i, j, &color);
			}
			else
			{
				cv::Vec3b row_color = mat->at<cv::Vec3b>(i, j);
				Objects::Visual::Color color(row_color.val[2], row_color.val[1], row_color.val[0]);
				image->set(i, j, &color);
			}
		}
	}
}

bool Core::Common::Functions::is_aligned(Objects::Geometric::IPoint* a, Objects::Geometric::IPoint* b, Objects::Geometric::IPoint* c)
{
	return (a->x() - c->x()) * (b->y() - c->y()) == (b->x() - c->x()) * (a->y() - c->y());
}

Core::Objects::Geometric::IPoint* Core::Common::Functions::vertical_or_horizontal_neighbour(Objects::Geometric::IPoint* central_point, std::vector<Core::Objects::Geometric::IPoint*> neighbours)
{
	Objects::Geometric::IPoint* c = central_point;
	for (auto n : neighbours)
	{
		if (c->x() + 1 == n->x() && c->y() == n->y() ||
			c->x() - 1 == n->x() && c->y() == n->y() ||
			c->x() == n->x() && c->y() + 1 == n->y() ||
			c->x() == n->x() && c->y() - 1 == n->y())
		{
			return n;
		}
	}

	return nullptr;
}
