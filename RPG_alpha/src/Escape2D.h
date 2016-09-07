#pragma once
#include "Misc.h"
#include "Title.h"
#include "Stage.h"
#include "Result.h"

class CEscape2D
{
private:
	CMisc misc;
	CTitle title;
	CStage stage;
	CResult result;

	//データロード用
	string loadFile = "res/ESGame/HiScore.ini";

	//Mat3x2 transform;
	int mode;

	int score;
	int hiScore;
	int hitCount;
	int hiHitCount;
	String saveName;

	bool debug;

public:
	CEscape2D();
	~CEscape2D();

	//フォントウィンドウ
	Rect textWindow;

	void reset();
	void main();
};

