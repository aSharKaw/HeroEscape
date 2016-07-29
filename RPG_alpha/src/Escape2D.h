#pragma once
//#include <Siv3D.hpp>
//#include "Save.h"
#include "Misc.h"
#include "Title.h"
#include "Stage.h"

class CEscape2D
{
public:
	CEscape2D();
	~CEscape2D();

	CMisc misc;
	CTitle title;
	CStage stage;

	//フォントウィンドウ
	Rect textWindow;

	void reset();
	void main();

	void result();

	int score;
	int hiScore;
	int hitCount;
	int hiHitCount;

private:
	//データロード用
	INIReader scoreRead = INIReader(L"res/ESGame/HiScore.ini");

	const Rect rect_result = Rect(0, 0, misc.WIDTH, misc.HEIGHT);

	const Sound result_bgm = Sound(L"res/ESGame/audio/result.mp3");
	const Sound result_se = Sound(L"res/ESGame/audio/resultTop.mp3");
	const Sound score_se = Sound(L"res/ESGame/audio/score.mp3");
	const Sound hiscore_se = Sound(L"res/ESGame/audio/hiscore.mp3");

	Mat3x2 transform;
	int mode;
	int angle;
	int count;

	bool flug;


};

