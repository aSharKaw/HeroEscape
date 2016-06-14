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

	Font font;
	Font bigFont;

	
	//フォントウィンドウ
	Rect textWindow;

	void reset();
	void main();
	void title();
	void game();
	void result();

	void playerMove(Vec2& pos);
	void enemyMove(Vec2 startPos, Vec2 targetPos, Vec2& enemyPos, int frame, bool& flug);

	int score;
	int hiScore;
	int hitCount;
	int hiHitCount;

private:
	INIWriter scoreWrite = INIWriter(L"res/ESGame/HiScore.ini");
	INIReader scoreRead = INIReader(L"res/ESGame/HiScore.ini");


	const Texture texture_titleBG = Texture(L"res/ESGame/image/title.png");
	const Texture texture_titleLogo = Texture(L"res/ESGame/image/titlelogo.png");
	const Texture texture_cloud = Texture(L"res/ESGame/image/kumo.png");
	const Texture texture_gameBG = Texture(L"res/ESGame/image/gameBG.png");
	const Texture texture_player = Texture(L"res/ESGame/image/player.png");
	const Texture texture_enemy = Texture(L"res/ESGame/image/enemy.png");
	const Texture texture_item = Texture(L"res/ESGame/image/item.png");
	const Rect rect_result = Rect(0, 0, Window::WIDTH, Window::HEIGHT);

	const Sound title_bgm = Sound(L"res/ESGame/audio/title.mp3");
	const Sound game_bgm = Sound(L"res/ESGame/audio/game.mp3");
	const Sound damage_se = Sound(L"res/ESGame/audio/damage.mp3");
	const Sound pickup_se = Sound(L"res/ESGame/audio/pickup.mp3");

	const Sound result_bgm = Sound(L"res/ESGame/audio/result.mp3");
	const Sound result_se = Sound(L"res/ESGame/audio/resultTop.mp3");
	const Sound score_se = Sound(L"res/ESGame/audio/score.mp3");
	const Sound hiscore_se = Sound(L"res/ESGame/audio/hiscore.mp3");


	Mat3x2 transform;
	int mode;
	int angle;
	int count;

	bool flug;

	float player_size;
	Vec2 playerPos;
	float move_speed;

	int itemNum;

	Vec2 itemPos;


	Rect player_collider;
	Rect enemy1_collider;
	Rect enemy2_collider;
	Rect enemy3_collider;
	Vec2 enemy1Pos;
	Vec2 enemy2Pos;
	Vec2 enemy3Pos;
	bool enemy_flag;
	bool dummy_flug;

	bool enemy_collision();

	Circle item_collider;

	int haveItem;
	int goalItem;

	float bgmValue;
};

