#include "OtsuBinarization.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Visual/Color.h"
#include <climits>
#include <iostream>

void Core::Transformation::OtsuBinarization::execute(Objects::Visual::IImage* image)
{
	this->image = image;

	unsigned char t = threshold();

	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Visual::Color color(
				image->get(i, j)->brightness() > t ?
					Objects::Visual::IColor::binary_color::turn_on :
					Objects::Visual::IColor::binary_color::turn_off
			);
			image->set(i, j, &color);
		}
	}
}

unsigned char Core::Transformation::OtsuBinarization::threshold()
{
	int min, max;
	std::vector<int> histogram = get_histogram(&min, &max);

	int tmp1 = 0, tmp2 = 0;
	for (int i = 0; i <= max - min; i++)
	{
		tmp1 += i * histogram[i];
		tmp2 += histogram[i];
	}

	int alpha = 0, beta = 0, threshold = 0;
	double w1, a, sigma, sigma_max = -1;
	for (int i = 0; i < max - min; i++)
	{
		alpha += i * histogram[i];
		beta += histogram[i];

		w1 = static_cast<double>(beta) / tmp2;
		a = static_cast<double>(alpha) / beta - static_cast<double>(tmp1 - alpha) / (tmp2 - beta);
		sigma = w1 * (1 - w1) * a * a;

		if (sigma > sigma_max)
		{
			sigma_max = sigma;
			threshold = i;
		}
	}

	return static_cast<unsigned char>(threshold + min);
}

std::vector<int> Core::Transformation::OtsuBinarization::get_histogram(int* min, int* max)
{
	*min = INT_MAX;
	*max = INT_MIN;
	int tmp;
	
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			tmp = static_cast<int>(image->get(i, j)->brightness());
			if (tmp < *min) *min = tmp;
			if (tmp > *max) *max = tmp;
		}
	}

	std::vector<int> histogram;
	int histgram_size = *max - *min + 1;
	for (int i = 0; i < histgram_size; i++)
	{
		histogram.push_back(0);
	}

	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			histogram[static_cast<int>(image->get(i, j)->brightness()) - *min]++;
		}
	}

	return histogram;
}
