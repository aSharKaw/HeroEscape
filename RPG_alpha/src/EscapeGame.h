#pragma once
#include <Siv3D.hpp>
#include <boost\random.hpp>

class CEscapeGame
{
public:
	CEscapeGame();
	~CEscapeGame();
	/*
	モニターメモ：
	Plane(1).asMesh()
	.scaled(14, 1, 8)
	.translated(0, -0.6, -8)
	.rotated(Quaternion::Pitch(Radians(90)))
	.draw(texture_titleBG);
	*/
	//ウィンドウ幅
	enum Window 
	{
		WIDTH = 8,
		HEIGHT = 8
	};

	int mode;
	enum scene
	{
		TITLE = 0,
		GAME = 0
	};
	//int* mode;

	void reset();
	void main();
	void title();
	void Game();

	void PlayerMove(float& x, float& y);
	const Texture texture_titleBG = Texture(L"res/ESGameImg/title.png", TextureDesc::For3D);
	const Texture texture_cloud = Texture(L"res/ESGameImg/kumo.png", TextureDesc::For3D);

	float player_length, player_side;
	float move_speed;
	float player_size;



	const Texture texture_gameBG = Texture(L"res/ESGameImg/gameBG.png", TextureDesc::For3D);
	const Texture texture_player = Texture(L"res/ESGameImg/player.png", TextureDesc::For3D);

	const Texture texture_enemy = Texture(L"res/ESGameImg/enemy.png", TextureDesc::For3D);

};

