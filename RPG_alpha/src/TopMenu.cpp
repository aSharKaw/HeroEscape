#include "TopMenu.h"


CTopMenu::CTopMenu()
{
	misc.createModel(moniter);
	misc.createModel(shelf);
	misc.createModel(machin_on);
	misc.createModel(machin_off);

	power = true;
}


CTopMenu::~CTopMenu()
{
}

void CTopMenu::draw(int& gameTitle, int& mode, bool& power)
{
	if (power)
	{
		Plane(1).asMesh().scaled(14, 1, 8).translated(0, 0.6, 8).rotated(Quaternion::Pitch(Radians(-90))).draw(ColorF(0.2, 0.2, 0.2));
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

	misc.drawModel(moniter, Vec3::Zero);
	misc.drawModel(shelf, Vec3(-2, -7, 0));

	if (Input::KeySpace.clicked)
	{
		mode = gameTitle;
	}
}