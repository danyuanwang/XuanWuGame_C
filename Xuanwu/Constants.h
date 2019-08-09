#pragma once

enum class XW_Color_Value
{
	BLACK = 0x000000, //(0, 0, 0),
	WHITE = 0xffffff,//(255, 255, 255),
	GREEN_L = 0x00ff00, //(0, 255, 0),
	GREEN_D = 0x006900,//(0, 105, 0),
	RED = 0xff0000,//(255, 0, 0),
	BLUE = 0x00ffff,//(0, 255, 255),
	GREY = 0x696969, //(105, 105, 105),
	BLUE_D = 0x000080, //RGB_Color(0, 0, 128),
	BLUE_L = 0xb0c0de, //(176, 196, 222),
};

struct XW_RGB_Color
{
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;

	XW_RGB_Color(unsigned char r, unsigned char g, unsigned char b)
		: Red(r), Green(g), Blue(b)
	{}

	XW_RGB_Color(int rgb)
		: Red((rgb & 0xff0000) >> 16), Green((rgb & 0xff00) >> 8), Blue(rgb & 0xff)
	{}

	XW_RGB_Color(XW_Color_Value rgb)
		: XW_RGB_Color(int(rgb))
	{}

	XW_Color_Value GetColorValue() const
	{
		int rgb = 0x0;
		rgb = Red;
		rgb <<= 8;
		rgb += Green;
		rgb <<= 8;
		rgb += Blue;
		return XW_Color_Value(rgb);

	}
};
