//#include "stdafx.h"
#include "Title.h"

CTitle::CTitle()
{
	title_bgm.setLoop(true);
	title_bgm.setVolume(misc.bgmValue);

	//misc.createModel(stageObj);

	Reset();
}


CTitle::~CTitle()
{
	Reset();
}

void CTitle::Reset()
{
	sceneMoveFlug = false;
	count = 0;
	cloudAngle = 0;
}

void CTitle::Draw()
{

}

bool CTitle::Title(int hiScore, int hiHitCount)
{
		//misc.drawModel(stageObj, Vec3(0, 0, 0), Vec3(0, (float)cloudAngle / 100, 0));

		//画像表示
		texture_titleBG.resize(misc.HEIGHT, misc.HEIGHT).draw();
		texture_cloud(cloudAngle, cloudAngle, misc.WIDTH, misc.HEIGHT)
			.resize(misc.WIDTH, misc.HEIGHT).draw();
		texture_titleLogo.resize(misc.WIDTH, misc.HEIGHT).draw();

		//テキスト表示
		textWindow.draw(Color(255, 255, 255, 100));
		misc.font(L"HiScore:", hiScore / 60, L"sec").draw(10, 5, Color(0, 0, 0));
		misc.font(L"EnemyHit:", hiHitCount).draw(misc.WIDTH / 2, 5, Color(0, 0, 0));

		if (cloudAngle % 60 >= 30)
		{
			misc.font(L"Any Push Start!").drawCenter(misc.WIDTH / 2, misc.HEIGHT / 4 * 3, Color(Palette::Red));
		}

		//雲移動
		cloudAngle++;

		if (Input::AnyKeyClicked())
		{
			sceneMoveFlug = true;
			//angle = 0;
		}

		if (sceneMoveFlug)
		{
			count++;
			title_bgm.pause(3.0s);

			cloudAngle += count / 60;


			texture_cloud((cloudAngle * 2), (cloudAngle * 2) + 50, misc.WIDTH, misc.HEIGHT)
				.resize(misc.WIDTH, misc.HEIGHT).draw(Color(Palette::White, count));
			texture_cloud((cloudAngle * 2) / 2, cloudAngle + 100, misc.WIDTH, misc.HEIGHT)
				.resize(misc.WIDTH, misc.HEIGHT).draw(Color(Palette::White, count));
			//60*4
			if (count >= 60 * 4)
			{
				return true;
			}
		}
		else
		{

			title_bgm.play();
		}

	
	return false;
}