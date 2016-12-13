#include "OtsuBinarization.hpp"
#include "../Objects/Image/Pixel.hpp"
#include "../Objects/Image/IImage.hpp"

void FVM::Core::Transformations::OtsuBinarization::execute(Objects::Image::IImage* image)
{
	unsigned char t = 128;// threshold(image);
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Image::Pixel pixel = *image->pixel(i, j);
	
			if (t > pixel.brightness())
				pixel.brightness(turn_on_pixel);
			else
				pixel.brightness(turn_off_pixel);
	
			image->pixel(i, j, &pixel);
		}
	}
}

unsigned char FVM::Core::Transformations::OtsuBinarization::threshold(Objects::Image::IImage* image)
{
	unsigned char min, max;
	min = max = image->pixel(0, 0)->brightness();
	
	// Make histogram
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			unsigned char tmp = image->pixel(i, j)->brightness();
			if (tmp < min) min = tmp;
			if (tmp > max) max = tmp;
		}
	}
	
	int hist_size = max - min + 1;
	int *hist = new int[hist_size];
	
	for (int i = 0; i < hist_size; i++)
		hist[i] = 0;
	
	for (int i = 0; i < image->rows(); i++)
		for (int j = 0; j < image->cols(); j++) 
		{
			//if (hist_size <= image->pixel(i, j).brightness() - min)
			//	std::cout << "hist_size <= image->pixel(i, j).brightness() - min" << std::endl;
			hist[image->pixel(i, j)->brightness() - min]++;
		}
	// Histogram made
	
	int tmp1 = 0, tmp2 = 0;
	for (int i = 0; i <= (max - min); i++)
	{
		tmp1 += i * hist[i];
		tmp2 += hist[i];
	}
	
	int alpha = 0, beta = 0;
	double max_sigma = -1;
	unsigned char threshold = 0;
	for (int i = 0; i < (max - min); i++)
	{
		alpha += i*hist[i];
		beta += hist[i];
	
		double w1 = (double)beta / tmp1;
		double a = (double)alpha / beta - (double)(tmp1 - alpha) / (tmp1 - beta);
		double sigma = w1 * (1 - w1)*a*a;
		if(sigma > max_sigma)
		{
			max_sigma = sigma;
			threshold = i;
		}
	}
	
	delete[] hist;
	
	return threshold + min;
}
