#include "Pixel.h"

Pixel::Pixel(): val_red(0), val_green(0), val_blue(0)
{
}

Pixel::Pixel(int red, int green, int blue): val_red(red), val_green(green), val_blue(blue)
{
}

int Pixel::red()
{
	return this->val_red;
}

int Pixel::green()
{
	return this->val_green;
}

int Pixel::blue()
{
	return this->val_blue;
}

Pixel Pixel::mix(const Pixel& pixel2)
{
	Pixel newPixel;

	newPixel.val_red = (this->val_red + pixel2.val_red) / 2;
	newPixel.val_green = (this->val_green + pixel2.val_green) / 2;
	newPixel.val_blue = (this->val_blue + pixel2.val_blue) / 2;

	return newPixel;
}
