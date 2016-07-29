#pragma once
#include "Misc.h"

class CStage
{
public:
	CStage();

	bool Game(int& score, int& hitCount, int hiScore, int hiHitCount);
	void drawGame(int score, bool debug);
	void Reset();

private:
	CMisc misc;

	void playerMove(Vec2& pos);
	void enemyMove(Vec2 startPos, Vec2 targetPos, Vec2& enemyPos, int frame, bool& flug);
	bool enemy_collision();

	//フォント

	//フォントウィンドウ
	const Rect textWindow = Rect(0, 5, misc.WIDTH, 60);

	//画像用意
	const Texture texture_gameBG = Texture(L"res/ESGame/image/gameBG.png");
	const Texture texture_player = Texture(L"res/ESGame/image/player.png");
	const Texture texture_enemy = Texture(L"res/ESGame/image/enemy.png");
	const Texture texture_item = Texture(L"res/ESGame/image/item.png");
	const Rect rect_result = Rect(0, 0, misc.WIDTH, misc.HEIGHT);

	//音の用意
	const Sound game_bgm = Sound(L"res/ESGame/audio/game.mp3");
	const Sound damage_se = Sound(L"res/ESGame/audio/damage.mp3");
	const Sound pickup_se = Sound(L"res/ESGame/audio/pickup.mp3");

	int angle;

	float player_size;
	Vec2 objectSize;
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

	Circle item_collider;

	int haveItem;
	int goalItem;

};

