#pragma once
#include "Misc.h"

class CResult
{
public:
	CResult();
	void Reset();
	CMisc misc;

	bool Result(int score, int hitcount, int& hiScore);

	const Rect rect_result = Rect(0, 0, misc.WIDTH, misc.HEIGHT);

	const Sound result_bgm = Sound(L"res/ESGame/audio/result.mp3");
	const Sound result_se = Sound(L"res/ESGame/audio/resultTop.mp3");
	const Sound score_se = Sound(L"res/ESGame/audio/score.mp3");
	const Sound hiscore_se = Sound(L"res/ESGame/audio/hiscore.mp3");

	int angle;
	int count;

	bool flug;
};

