#include "Convert.hpp"
#include <cmath>

unsigned char FVM::Core::CommonFunctions::Convert::rgb2brightness(unsigned char red, unsigned char green, unsigned char blue)
{
	return static_cast<unsigned char>(round(
		0.299 * static_cast<double>(red) +
		0.587 * static_cast<double>(green) +
		0.114 * static_cast<double>(blue)
	));	// From YIQ model.
}
