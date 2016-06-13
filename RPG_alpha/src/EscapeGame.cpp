#include "EscapeGame.h"


CEscapeGame::CEscapeGame()
{

	reset();
}

void CEscapeGame::reset()
{
	mode = 0;
	move_speed = 0.5;

	player_length = player_side = 0;

	player_size = Window::WIDTH / 16.0;
}

CEscapeGame::~CEscapeGame()
{
}

//エスケープゲーム全実行
void CEscapeGame::main()
{
	switch (mode)
	{
	case 0 :
		if (Input::KeyUp.pressed) mode = 1;
		title();
		break;
	case 1 :
		Game();
		break;
	default:
		break;
	}

}

//タイトル
void CEscapeGame::title()
{
	Plane(1).asMesh().scaled(14, 1, 8).translated(0, 0.6, 8).rotated(Quaternion::Pitch(Radians(-90))).draw(ColorF(0, 0, 0));
	Plane(1).asMesh().scaled(Window::WIDTH, 1, Window::HEIGHT).translated(0, 0.7, 8).rotated(Quaternion::Pitch(Radians(-90))).draw(texture_titleBG);

	Plane(1).asMesh().scaled(Window::WIDTH, 1, Window::HEIGHT).translated(0, 0.7, 8).rotated(Quaternion::Pitch(Radians(-90))).draw(texture_cloud);
}

//本編実行
void CEscapeGame::Game()
{
	Plane(1).asMesh().scaled(14, 1, 8).translated(0, 0.6, 8).rotated(Quaternion::Pitch(Radians(-90))).draw(ColorF(0, 0, 0));
	Plane(1).asMesh().scaled(Window::WIDTH, 1, Window::HEIGHT).translated(0, 0.7, 8).rotated(Quaternion::Pitch(Radians(-90))).draw(texture_gameBG);

	Plane(1).asMesh().scaled(player_size, 0.1, player_size).translated(player_side, 0.8, 8 + player_length).rotated(Quaternion::Pitch(Radians(-90))).draw(texture_player);

	PlayerMove(player_side, player_length);



}

//プレイヤー移動関数
void CEscapeGame::PlayerMove(float& x, float& y)
{
	if (y < (Window::HEIGHT / 2 - player_size) && Input::KeyUp.pressed)y += 0.05;
	if (y > -(Window::HEIGHT / 2 - player_size) && Input::KeyDown.pressed)y -= 0.05;
	if (x > -(Window::WIDTH / 2 - player_size) && Input::KeyLeft.pressed)x -= 0.05;
	if (x < (Window::WIDTH / 2 - player_size) && Input::KeyRight.pressed)x += 0.05;
}