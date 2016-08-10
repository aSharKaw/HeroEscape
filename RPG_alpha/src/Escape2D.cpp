#include "Escape2D.h"

CEscape2D::CEscape2D()
{
	reset();

	debug = false;
}

CEscape2D::~CEscape2D()
{
	//delete title;

	//CHeroTitle title;
	//CHeroGame game;
}

void CEscape2D::reset()
{
	mode = 0;

	//ハイスコアのロード
	hiScore = misc.loadManager(loadFile, "Score.HiScore");
	hiHitCount = misc.loadManager(loadFile, "Score.hiHitCount");

	score = 0;
	hitCount = 0;

	textWindow = Rect(0, 5, misc.WIDTH, 60);
}

void CEscape2D::main()
{
	//メインループ
	switch (mode)
	{
	case 0:
		if (title.Title(hiScore, hiHitCount))
		{
			title.Reset();
			mode = 1;
		}

		break;
	case 1:

		if (stage.Game(score, hitCount, hiScore, hiHitCount, debug))
		{
			stage.Reset();
			mode = 2;
		}
		break;
	case 2:

		if (result.Result(score, hitCount, hiScore))
		{
			result.Reset();
			reset();
			mode = 0;
		}

		break;
	default:
		break;
	}
}

