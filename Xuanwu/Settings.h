#pragma once
#include "Constants.h"

struct GameSettings
{
	static inline const XW_RGB_Color BackgroundColor = XW_RGB_Color(XW_Color_Value::WHITE);
	static inline const int WidthOfWindowX = 1200;
	static inline const int HeightWindowY = 830;
	static inline const char* WindowCaption = "Xuanwu Game";

	static inline const int NumOfBoardRow = 20;
	static inline const int NumOfBoardCol = 16;
	static inline const int MarginOfBoardX = 10;
	static inline const int MarginOfBoardY = 10;

	static inline const int FramePerSecond = 45;

};