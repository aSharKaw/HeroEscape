#include "TopMenu.h"


CTopMenu::CTopMenu()
{
	misc.createModel(moniter);
	misc.createModel(shelf);
	misc.createModel(machin_on);
	misc.createModel(machin_off);

	power = true;
	changeGame = false;

	circle = Circle(400, 400, r);
}


CTopMenu::~CTopMenu()
{
}



void CTopMenu::draw(int& gameTitle, int& mode, bool& power)
{
	if (power)
	{
		Plane(1).asMesh().scaled(14, 1, 8).translated(0, 0.6, 8).rotated(Quaternion::Pitch(Radians(-90))).draw(ColorF(0.2, 0.2, 0.2));

		//circle.drawFrame(0, 5, Color(Palette::Blue));
		//circle.draw(Color(Palette::Pink));
		//r -= 400.0f / 60.0f;
		//circle = Circle(400, 400, r);
		//if (Input::KeyUp.pressed)r--;

		//ESGame.main();
		//ESGame2D.title();
		misc.drawModel(machin_on, Vec3(-10, 0, 0));
		if (Input::KeyO.clicked)
		{
			power = false;
			//ESGame.reset();
			//ESGame2D.reset();
		}
	}
	else
	{
		misc.drawModel(machin_off, Vec3(-10, 0, 0));
		if (Input::KeyO.clicked)
		{
			power = true;
		}
	}

	//ÉQÅ[ÉÄÇÃêÿÇËë÷Ç¶ 
	if (Input::KeyLeft.clicked)
	{
		//changeGame = true;
		//anime.ringAnime(Circle(800 / 2, 800 / 2, 400), 0, Palette::Yellow, 0, Palette::Pink, 5, true);
		gameTitle--;
		//anime.ringAnime(Circle(800 / 2, 800 / 2, 400), 0, Palette::Yellow, 0, Palette::Pink, 5, false);
	}
	else if (Input::KeyRight.clicked)
	{
		gameTitle++;
	}

	misc.drawModel(moniter, Vec3::Zero);
	misc.drawModel(shelf, Vec3(-2, -7, 0));

	if (Input::KeySpace.clicked)
	{
		mode = gameTitle;
	}
}