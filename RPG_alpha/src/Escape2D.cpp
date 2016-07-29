//#include "stdafx.h"
#include "Escape2D.h"


CEscape2D::CEscape2D()
{
	reset();

	//音の準備
	result_bgm.setLoop(true);
	result_bgm.setVolume(misc.bgmValue);

	result_se.setVolume(misc.bgmValue);

}

CEscape2D::~CEscape2D()
{
	//delete title;

//		CHeroTitle title;
	//CHeroGame game;
}

void CEscape2D::reset()
{
	mode = 0;
	angle = 0;
	count = 0;

	flug = false;

	//ハイスコアのロード
	//INIReader宣言時にしかロードされないので、変更の必要あり
	hiScore = scoreRead.getOr<int>(L"Score.HiScore", 99 * 60);
	hiHitCount = scoreRead.getOr<int>(L"Score.hiHitCount", 99);

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

		if (stage.Game(score, hitCount, hiScore, hiHitCount))
		{
			stage.Reset();
			mode = 2;
		}
		//game();
		//if (angle > 255)
		//{
		//	angle = 0;
		//	mode = 2;
		//}
		break;
	case 2:
		result();

		if (count > 60 * 4)
		{
			reset();
		}

		break;
	default:
		break;
	}
}


void CEscape2D::result()
{
	//game_bgm.stop();

	if (angle == 0)result_se.play();

	rect_result.draw(Color(Palette::Black));

	misc.bigFont(L"エスケープ成功！").drawCenter(misc.WIDTH / 2, 100);

	if (angle > 60 * 4) misc.font(L"Time : ", score / 60).draw(misc.WIDTH / 5, 250);
	if (angle == 60 * 4) score_se.play();

	if (angle > 60 * 5) misc.font(L"EnemyHit : ", hitCount).draw(misc.WIDTH / 5, 300);
	if (angle == 60 * 5) score_se.play();


	String text = L"ハイスコア更新!!";
	if (angle > 60 * 7 && score < hiScore)
	{
		for (size_t i = 0; i < text.length; ++i)
		{
			misc.font(text[i]).draw(200 + 60 * i, 500, HSV(i * 20 + angle));
		}

		misc.saveManager("res/ESGame/HiScore.ini", "Score.HiScore", score, "Score.hiHitCount", hitCount);
	}
	if (angle == 60 * 7 && score < hiScore) 	hiscore_se.play();


	if (angle > 60 * 9)result_bgm.play();

	if (Input::AnyKeyClicked())flug = true;

	angle++;

	if (flug)
	{
		count++;

		result_bgm.pause(3.0s);
		rect_result.draw(Color(Palette::White, count));
	}
}
