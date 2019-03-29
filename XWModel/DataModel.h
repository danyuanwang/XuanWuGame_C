#pragma once
class DataModel
{
private:
	const char* _gameScreenTitle = "xuanwu game";

	const int _gameScreenWidth = 1200;
	const int _gameScreenHeight = 830;
	const int _gameScreenMarginX = 20;
	const int _gameScreenMarginY = 20;

	const int _gameMapColNum = 320;
	const int _gameMapRowNum = 200;

public:
	DataModel();
	~DataModel();

	inline const char* GetGameScreenTitle() { return _gameScreenTitle; }
	inline const int GetGameScreenWidth() { return _gameScreenWidth; }
	inline const int GetGameScreenHeight() { return _gameScreenHeight; }
	inline const int GetGameScreenMarginX() { return _gameScreenMarginX; }
	inline const int GetGameScreenMarginY() { return _gameScreenMarginY; }

	inline const int GetGameMapColNum() { return _gameMapColNum; }
	inline const int GetGameMapRowNum() { return _gameMapRowNum; }
};

