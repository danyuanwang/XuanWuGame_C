#pragma once
#include "Constants.h"

namespace GameSettings
{
	const XW_RGB_Color BackgroundColor = XW_RGB_Color(XW_Color_Value::WHITE);
	const XW_RGB_Color PanelColor = XW_RGB_Color(XW_Color_Value::WHITE);
	const int WidthOfWindowX = 1200;
	const int HeightWindowY = 800;
	static const char* WindowCaption = "Xuanwu Game";
	const int PanelWidth = WidthOfWindowX / 4;
	const int MapWidth = (((WidthOfWindowX - PanelWidth)/22)*20);
	
	const int NumOfBoardRow = 20;
	const int NumOfBoardCol = 16;
	const int CellWidth = MapWidth / NumOfBoardRow;
	const int MineMarginX = CellWidth / 5;
	const int Minewidth = MineMarginX * 3;
	const int CellHeight = CellWidth;
	const int MineMarginY = CellHeight / 5;
	const int MineHeight = MineMarginY * 3;
	const int CellMarginX = 1;
	const int CellMarginY = CellMarginX;
	const int MarginOfBoardX = MapWidth/20;
	const int MapHeight = (CellHeight + CellMarginY)* NumOfBoardCol;
	const int MarginOfBoardY = (HeightWindowY - MapHeight)/2;
	
	const int PanelHeight = MapHeight;
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