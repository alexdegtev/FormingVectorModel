#include "Pixel.h"
#include "../Geometric/Point.h"
#include "Color.h"

Core::Objects::Visual::Pixel::Pixel() : Pixel(nullptr, nullptr)
{
}

Core::Objects::Visual::Pixel::Pixel(IPoint* point, IColor* color) : _point(point), _color(color)
{
	if (!_point)
		_point = new Geometric::Point;

	if (!_color)
		_color = new Color;
}

Core::Objects::Visual::Pixel::Pixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue) : Pixel(new Geometric::Point(x, y), new Color(red, green, blue))
{
}

Core::Objects::Visual::Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue) : Pixel(0, 0, red, green, blue)
{
}

Core::Objects::Visual::Pixel::Pixel(int x, int y, unsigned char brightness) : Pixel(new Geometric::Point(x, y), new Color(brightness))
{
}

Core::Objects::Visual::Pixel::Pixel(IPixel* other) : Pixel(other->x(), other->y(), other->red(), other->green(), other->blue())
{
}

Core::Objects::Visual::Pixel::~Pixel()
{
	if (_point)
		delete _point;

	if (_color)
		delete _color;
}

int Core::Objects::Visual::Pixel::x() const
{
	return _point->x();
}

int Core::Objects::Visual::Pixel::y() const
{
	return _point->y();
}

unsigned char Core::Objects::Visual::Pixel::red() const
{
	return _color->red();
}

void Core::Objects::Visual::Pixel::red(unsigned char value)
{
	_color->red(value);
}

unsigned char Core::Objects::Visual::Pixel::green() const
{
	return _color->green();
}

void Core::Objects::Visual::Pixel::green(unsigned char value)
{
	_color->green(value);
}

unsigned char Core::Objects::Visual::Pixel::blue() const
{
	return _color->blue();
}

void Core::Objects::Visual::Pixel::blue(unsigned char value)
{
	_color->blue(value);
}

unsigned char Core::Objects::Visual::Pixel::brightness() const
{
	return _color->brightness();
}

void Core::Objects::Visual::Pixel::brightness(unsigned char value)
{
	_color->brightness(value);
}
