#pragma once
#include "Constants.h"

namespace GameSettings
{
	const XW_RGB_Color BackgroundColor = XW_RGB_Color(XW_Color_Value::WHITE);
	const int WidthOfWindowX = 320;
	const int HeightWindowY = 200;
	static const char* WindowCaption = "Xuanwu Game";
	const int PanelWidth = WidthOfWindowX / 6;
	const int MapWidth = (((WidthOfWindowX - PanelWidth)/22)*20);
	
	const int NumOfBoardRow = 20;
	const int NumOfBoardCol = 16;
	const int CellWidth = MapWidth / NumOfBoardRow;
	const int CellHeight = CellWidth;
	const int CellMarginX = CellWidth / 50;
	const int CellMarginY = CellMarginX;
	const int MarginOfBoardX = MapWidth/20;
	const int MarginOfBoardY = MarginOfBoardX;
	const int MapHeight = HeightWindowY - (2 * MarginOfBoardY);
	const int PanelHeight = HeightWindowY - (2 * MarginOfBoardY);
	const XW_RGB_Color CellColorMap[] = {
		XW_RGB_Color(XW_Color_Value::WHITE),
		XW_RGB_Color(XW_Color_Value::BLUE_L),
		XW_RGB_Color(XW_Color_Value::GREY),
		XW_RGB_Color(XW_Color_Value::GREEN_D),
		XW_RGB_Color(XW_Color_Value::BLUE),
		XW_RGB_Color(XW_Color_Value::BLUE_D),
		XW_RGB_Color(XW_Color_Value::GREEN_L)
	};
		const int FramePerSecond = 45;

};