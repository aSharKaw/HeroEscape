#include "Stage.h"


CStage::CStage()
{
	game_bgm.setLoop(true);
	game_bgm.setVolume(misc.bgmValue);

	misc.createModel(stageObj);

	Reset();
}

void CStage::Reset()
{
	//乱数シード値を時間から取得
	Reseed(DateTime::Now().second);

	angle = 0;
	animation = 0;

	playerSize = Vec2(misc.WIDTH / 16.0f, misc.HEIGHT / 16.0f + 4);
	objectSize = misc.WIDTH / 16.0f;

	playerPos = Vec2(misc.WIDTH / 2, misc.HEIGHT / 2);
	move_speed = 5.0f;

	itemNum = Random(0, 7);
	itemPos = Vec2(Random(50.0f, (float)misc.WIDTH - 50.0f), Random(50.0f, (float)misc.HEIGHT - 50.0f));

	enemy1Pos = Vec2(50, 50);
	enemy2Pos = Vec2(700, 50);
	enemy3Pos = Vec2(misc.WIDTH / 2, 700);

	enemy_flag = false;
	dummy_flug = false;

	haveItem = 0;
	goalItem = 8;

}

bool CStage::Game(int& score, int& hitCount, int hiScore, int hiHitCount, bool debug)
{
	drawGame(score, false);

	//当たり判定の更新
	player_collider = Rect(playerPos.x, playerPos.y, playerSize.x, playerSize.y);
	item_collider = Circle(itemPos.x + (objectSize / 2), itemPos.y + (objectSize / 2), objectSize / 3);
	enemy1_collider = Rect(enemy1Pos.x, enemy1Pos.y, objectSize, objectSize);
	enemy2_collider = Rect(enemy2Pos.x, enemy2Pos.y, objectSize, objectSize);
	enemy3_collider = Rect(enemy3Pos.x, enemy3Pos.y, objectSize, objectSize);

	if (Input::KeyShift.pressed && Input::KeyO.clicked)
	{
		haveItem = 8;
	}

	if (player_collider.intersects(item_collider))
	{
		pickup_se.play();
		itemNum = Random(0, 7);
		haveItem++;



		if (haveItem == 8)
		{
			itemPos = Vec2(-100, -100);
		}
		else
		{
			itemPos = Vec2(Random(50.0f, (float)misc.WIDTH - 50.0f), Random(50.0f, (float)misc.HEIGHT - 50.0f));
		}
		
		
	}

	if (enemy_collision())
	{
		damage_se.play();
		hitCount++;
		playerPos.x = misc.WIDTH / 2;
		playerPos.y = 100;
		enemy3Pos = Vec2(misc.WIDTH / 2, 700);
	}

	//カウントアップ&動作制限
	if (haveItem != goalItem)
	{
		game_bgm.play();

		playerMove(playerPos);
		enemyMove(Vec2(50, 50), Vec2(700, 700), enemy1Pos, 240, enemy_flag);
		enemyMove(Vec2(700, 50), Vec2(50, 700), enemy2Pos, 240, enemy_flag);
		enemyMove(enemy3Pos, playerPos, enemy3Pos, 240, dummy_flug);
		score++;
	}
	else
	{
		game_bgm.pause(3.0s);
		angle++;
	}

	if (angle > 255)
	{
		return true;
	}
	return false;


	if (debug)
	{
		Debug();
	}
}

void CStage::drawGame(int score, bool debug)
{
	misc.drawModel(stageObj, Vec3(0, 0, 0), Vec3(0, 0, 0));

	//画像表示
	//texture_gameBG.resize(misc.WIDTH, misc.HEIGHT).draw();
	texture_player(((animation / 60) % 3) * 24, playerMode * 32, 24, 32).resize(playerSize.x, playerSize.y).draw(playerPos);
	texture_item(itemNum * 32, (itemNum % 4) * 32, 32, 32).resize(objectSize, objectSize).draw(itemPos);
	texture_enemy.resize(objectSize, objectSize).draw(enemy1Pos);
	texture_enemy.resize(objectSize, objectSize).draw(enemy2Pos);
	texture_enemy.resize(objectSize, objectSize).draw(enemy3Pos);

	//テキスト表示
	textWindow.draw(Color(255, 255, 255, 100));
	misc.font(L"Time : ", score / 60).draw(10, 5, Color(0, 0, 0));
	misc.font(L"GetItem : ", haveItem, L"/", goalItem).draw(misc.WIDTH / 2, 5, Color(0, 0, 0));
	
	//画面遷移用
	rect_result.draw(Color(Palette::White, angle));

	animation++;
	playerMode = playerMove(Vec2(0, 0));
}

void CStage::Debug()
{
	//プレイヤーの当たり判定を表示
	player_collider.draw(Color(Palette::Red, 100));

	//球8個取得
	if (Input::KeyP.clicked)
	{
		haveItem = 8;
	}
}

int CStage::playerMove(Vec2& pos)
{
	if (pos.y < (misc.HEIGHT - playerSize.y) && (Input::KeyDown.pressed || Input::KeyS.pressed))
	{
		pos.y += move_speed;
		return 2;
	}
	if (pos.y > 0 && (Input::KeyUp.pressed || Input::KeyW.pressed))
	{
		pos.y -= move_speed;
		return 0;
	}
	if (pos.x > 0 && (Input::KeyLeft.pressed || Input::KeyA.pressed))
	{
		pos.x -= move_speed;
		return 3;
	}
	if (pos.x < (misc.WIDTH - playerSize.x) && (Input::KeyRight.pressed || Input::KeyD.pressed))
	{
		pos.x += move_speed;
		return 1;
	}

	return 2;
}

void CStage::enemyMove(Vec2 startPos, Vec2 targetPos, Vec2& enemyPos, int frame, bool& flug)
{

	Vec2 move(targetPos.x - startPos.x, targetPos.y - startPos.y);

	if (move.x > 0)
	{
		if (enemyPos.x > targetPos.x) flug = true;
		else if (enemyPos.x < startPos.x) flug = false;
	}
	else if (move.x < 0)
	{
		if (enemyPos.x < targetPos.x) flug = true;
		else if (enemyPos.x > startPos.x) flug = false;
	}
	if (flug) move = -move;

	enemyPos += Vec2((move.x / frame), (move.y / frame));

}

bool CStage::enemy_collision()
{
	if (player_collider.intersects(enemy1_collider) ||
		player_collider.intersects(enemy2_collider) ||
		player_collider.intersects(enemy3_collider))
	{
		return true;
	}

	return false;
}

