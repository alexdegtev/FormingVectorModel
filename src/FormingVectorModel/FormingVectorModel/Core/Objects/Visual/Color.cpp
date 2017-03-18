#include "Color.h"
#include "../../Common/Functions.h"

Core::Objects::Visual::Color::Color() : Color((unsigned char)0)
{
}

Core::Objects::Visual::Color::Color(unsigned char brightness) : Color(brightness, brightness, brightness)
{
}

Core::Objects::Visual::Color::Color(IColor* c) : Color(c->red(), c->green(), c->blue())
{
}

Core::Objects::Visual::Color::Color(unsigned char red, unsigned char green, unsigned char blue) : _red(red), _green(green), _blue(blue)
{
}

unsigned char Core::Objects::Visual::Color::red() const
{
	return _red;
}

void Core::Objects::Visual::Color::red(unsigned char value)
{
	_red = value;
}

unsigned char Core::Objects::Visual::Color::green() const
{
	return _green;
}

void Core::Objects::Visual::Color::green(unsigned char value)
{
	_green = value;
}

unsigned char Core::Objects::Visual::Color::blue() const
{
	return _blue;
}

void Core::Objects::Visual::Color::blue(unsigned char value)
{
	_blue = value;
}

unsigned char Core::Objects::Visual::Color::brightness() const
{
	return Common::Functions::rgb_to_brightness(_red, _green, _blue);
}

void Core::Objects::Visual::Color::brightness(unsigned char value)
{
	_red = _green = _blue = value;
}
