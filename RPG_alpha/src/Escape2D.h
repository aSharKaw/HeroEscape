#pragma once
#include <Siv3D.hpp>

class CEscape2D
{
public:
	CEscape2D();
	~CEscape2D();

	enum Window
	{
		WIDTH = 800,
		HEIGHT = 800
	};
	
	const Texture texture_titleBG = Texture(L"res/ESGameImg/title.png");
	const Texture texture_titleLogo = Texture(L"res/ESGameImg/titlelogo.png");
	const Texture texture_cloud = Texture(L"res/ESGameImg/kumo.png");
	const Texture texture_gameBG = Texture(L"res/ESGameImg/gameBG.png");
	const Texture texture_player = Texture(L"res/ESGameImg/player.png");

	const Rect rect_result = Rect(0, 0, Window::WIDTH, Window::HEIGHT);

	Font font;
	//Font font_hiScore;
	
	//フォントウィンドウ
	Rect textWindow;

	void reset();
	void main();
	void title();
	void game();
	void result();

	void playerMove(float& x, float& y);
	void enemyMove();

	bool RectCollision(Rect& obj1, Rect& obj2);


	Mat3x2 transform;
	int mode;
	int angle;

	float player_size;
	float player_x, player_y;
	float move_speed;

	struct ITEM
	{
		int texture_x, texture_y;
	};



	Rect player_collider;
	Circle item_collider;

	int score;
	int hiScore;

	int haveItem;
	int goalItem;
};

