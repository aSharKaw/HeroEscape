#include "Result.h"

CResult::CResult()
{
	//音の準備
	result_bgm.setLoop(true);
	result_bgm.setVolume(misc.bgmValue);

	result_se.setVolume(misc.bgmValue);
}

void CResult::Reset()
{
	angle = 0;
	count = 0;

	flug = false;
}

bool CResult::Result(int score, int hitCount, int& hiScore)
{
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
		//名前入力(3文字)
		//Input::GetCharsHelper(saveName);

	}
	if (angle == 60 * 7 && score < hiScore) hiscore_se.play();


	if (angle > 60 * 9)result_bgm.play();

	if (Input::AnyKeyClicked())flug = true;

	angle++;

	if (flug)
	{
		misc.saveManager("res/ESGame/HiScore.ini", "Score.HiScore", score, "Score.hiHitCount", hitCount);

		count++;

		result_bgm.pause(3.0s);
		rect_result.draw(Color(Palette::White, count));

		if (count > 60 * 4)
		{
			return true;
		}
	}

	return false;
}