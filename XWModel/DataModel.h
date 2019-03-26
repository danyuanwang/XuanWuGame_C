#pragma once

class DataModel
{
private:
	const char* _gameScreenTitle = "xuanwu game";

	int _gameScreenWidthPixel = 1200;
	int _gameScreenHeightPixel = 830;

	int _gameWindowWidthDimension = 320;
	int _gameWindowHeigthDimension = 200;

public:
	DataModel();
	~DataModel();

	inline const char* GetGameScreenTitle() { return _gameScreenTitle; }
	inline int GetGameScreenWidth() { return _gameScreenWidthPixel; }
	inline int GetGameScreenHeight() { return _gameScreenHeightPixel; }
	inline int GetGameWindowWidthDimension() { return _gameWindowWidthDimension; }
	inline int GetGameScreenHeightDimension() { return _gameWindowHeigthDimension; }
};

