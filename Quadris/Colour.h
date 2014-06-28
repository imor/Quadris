#ifndef __COLOUR_H__
#define __COLOUR_H__

class Colour
{
public:
	Colour()
	{
		R = 0.0f;
		G = 0.0f;
		B = 0.0f;
	}
	Colour(float r, float g, float b)
	{
		R = r;
		G = g;
		B = b;
	}
	float R;
	float G;
	float B;
};

#endif //__COLOUR_H__