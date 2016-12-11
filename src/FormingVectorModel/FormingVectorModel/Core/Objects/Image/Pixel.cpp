#include "Pixel.hpp"
#include "../../CommonFunctions/Convert.hpp"

FVM::Core::Objects::Image::Pixel::Pixel() : Pixel(0, 0, 0)
{
}

FVM::Core::Objects::Image::Pixel::Pixel(unsigned char brightness) : Pixel(brightness, brightness, brightness)
{
}

FVM::Core::Objects::Image::Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue) : red_(red), green_(green), blue_(blue)
{
}

FVM::Core::Objects::Image::Pixel::Pixel(const Pixel& other) : red_(other.red_), green_(other.green_), blue_(other.blue_)
{
}

unsigned char FVM::Core::Objects::Image::Pixel::red() const
{
	return red_;
}

void FVM::Core::Objects::Image::Pixel::red(unsigned char value)
{
	red_ = value;
}

unsigned char FVM::Core::Objects::Image::Pixel::green() const
{
	return green_;
}

void FVM::Core::Objects::Image::Pixel::green(unsigned char value)
{
	red_ = value;
}

unsigned char FVM::Core::Objects::Image::Pixel::blue() const
{
	return blue_;
}

void FVM::Core::Objects::Image::Pixel::blue(unsigned char value)
{
	blue_ = value;
}

unsigned char FVM::Core::Objects::Image::Pixel::brightness() const
{
	return CommonFunctions::Convert::rgb2brightness(red_, green_, blue_);
}

void FVM::Core::Objects::Image::Pixel::brightness(unsigned char value)
{
	red_ = green_ = blue_ = value;
}

FVM::Core::Objects::Image::Pixel FVM::Core::Objects::Image::Pixel::operator=(const Pixel& other)
{
	if (this != &other)
	{
		red_ = other.red_;
		green_ = other.green_;
		blue_ = other.blue_;
	}
	return *this;
}

std::ostream& FVM::Core::Objects::Image::operator<<(std::ostream& os, const Pixel& dt)
{
	os << "(" << static_cast<int>(dt.red_) << ", " 
		<< static_cast<int>(dt.green_) << ", " 
		<< static_cast<int>(dt.blue_) << ")";
	return os;
}
