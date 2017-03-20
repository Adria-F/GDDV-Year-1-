#ifndef __PIXEL__
#define __PIXEL__

class Pixel
{
public:

	Pixel();
	Pixel(int red, int green, int blue);

	int red();
	int green();
	int blue();

	Pixel mix(const Pixel& pixel2);

private:

	int val_red;
	int val_green;
	int val_blue;
};

#endif // __PIXEL__