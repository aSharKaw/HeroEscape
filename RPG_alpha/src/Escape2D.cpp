//#include "stdafx.h"
#include "Escape2D.h"


CEscape2D::CEscape2D()
{
	reset();

	//音の準備
	title_bgm.setLoop(true);
	title_bgm.setVolume(bgmValue);
	game_bgm.setLoop(true);
	game_bgm.setVolume(bgmValue);
	result_bgm.setLoop(true);
	result_bgm.setVolume(bgmValue);

	result_se.setVolume(bgmValue);

}


CEscape2D::~CEscape2D()
{
}

void CEscape2D::reset()
{
	//乱数シード値を時間から取得
	Reseed(DateTime::Now().second);

	mode = 0;
	angle = 0;
	count = 0;

	flug = false;

	player_size = Window::WIDTH / 16.0f;
	playerPos = Vec2(Window::WIDTH / 2, Window::HEIGHT / 2);
	move_speed = 5.0f;

	if (!FontManager::Register(L"res/font/PixelMplus12-Regular.ttf"))
	{
		font = Font(30);
		bigFont = Font(50);
		return;
	}
	else
	{
		font = Font(30, L"PixelMplus12");
		bigFont = Font(50, L"PixelMplus12");
	}

	itemNum = Random(0, 7);
	itemPos = Vec2(Random(50.0f, (float)Window::WIDTH - 50.0f), Random(50.0f, (float)Window::HEIGHT - 50.0f));
	//Item = item_info[itemNum];

	enemy1Pos = Vec2(50, 50);
	enemy2Pos = Vec2(700, 50);
	enemy3Pos = Vec2(Window::WIDTH / 2, 700);

	enemy_flag = false;
	dummy_flug = false;

	score = 0;
	//hiScore = 0;
	hitCount = 0;

	haveItem = 0;
	goalItem = 8;

	bgmValue = 0.8f;

	textWindow = Rect(0, 5, Window::WIDTH, 60);
}

void CEscape2D::main()
{
	//メインループ
	switch (mode)
	{
	case 0:
		if (count > 60 * 4)
		{
			mode = 1;
			count = 0;
			angle = 0;
			flug = false;
		}
		title();
		break;
	case 1:
		game();
		if (angle > 255)
		{
			angle = 0;
			mode = 2;
		}
		break;
	case 2:
		result();
		
		if (count > 60 * 4)
		{
			reset();
		}

		break;
	default:
		break;
	}
}

void CEscape2D::title()
{
	result_bgm.stop();


	//ハイスコアのロード
	hiScore = scoreRead.getOr<int>(L"Score.hiScore", 99 * 60);
	hiHitCount = scoreRead.getOr<int>(L"Score.hiHitCount", 99);


	//画像表示
	texture_titleBG.resize(Window::WIDTH, Window::HEIGHT).draw();
	texture_cloud(angle, angle, Window::WIDTH, Window::HEIGHT)
		.resize(Window::WIDTH, Window::HEIGHT).draw();
	texture_titleLogo.resize(Window::WIDTH, Window::HEIGHT).draw();

	//テキスト表示
	textWindow.draw(Color(255, 255, 255, 100));
	font(L"HiScore:", hiScore / 60, L"sec").draw(10, 5, Color(0, 0, 0));
	font(L"EnemyHit:", hiHitCount).draw(Window::WIDTH / 2, 5, Color(0, 0, 0));

	//雲移動
	angle++;

	if (Input::AnyKeyClicked())
	{
		flug = true;
		//angle = 0;
	}

	if (flug)
	{
		count++;
		title_bgm.pause(3.0s);
		
		angle += count / 60;

		//angle += angle;
		texture_cloud(angle + angle, angle + angle + 50, Window::WIDTH, Window::HEIGHT)
			.resize(Window::WIDTH, Window::HEIGHT).draw(Color(Palette::White, count));
		texture_cloud(angle + angle / 2, angle + 100, Window::WIDTH, Window::HEIGHT)
			.resize(Window::WIDTH, Window::HEIGHT).draw(Color(Palette::White, count));
	}
	else
	{
		
		title_bgm.play();
	}

}

void CEscape2D::game()
{
	title_bgm.stop();

	//画像表示
	texture_gameBG.resize(Window::WIDTH, Window::HEIGHT).draw();
	texture_player.resize(player_size, player_size).draw(playerPos);
	texture_item(itemNum * 32, (itemNum % 4) * 32, 32, 32).resize(player_size, player_size).draw(itemPos);
	texture_enemy.resize(player_size, player_size).draw(enemy1Pos);
	texture_enemy.resize(player_size, player_size).draw(enemy2Pos);
	texture_enemy.resize(player_size, player_size).draw(enemy3Pos);

	//テキスト表示
	textWindow.draw(Color(255, 255, 255, 100));
	font(L"Time : ", score / 60).draw(10, 5, Color(0, 0, 0));
	font(L"GetItem : ", haveItem, L"/", goalItem).draw(Window::WIDTH / 2, 5, Color(0, 0, 0));
	//if (texture_player.intersects(rect));

	//音の再生準備




	//画面遷移用
	rect_result.draw(Color(Palette::White, angle));;

	//当たり判定の更新
	player_collider = Rect(playerPos.x, playerPos.y, player_size, player_size);
	item_collider = Circle(itemPos.x + (player_size / 2), itemPos.y + (player_size / 2), player_size / 3);
	enemy1_collider = Rect(enemy1Pos.x, enemy1Pos.y, player_size, player_size);
	enemy2_collider = Rect(enemy2Pos.x, enemy2Pos.y, player_size, player_size);
	enemy3_collider = Rect(enemy3Pos.x, enemy3Pos.y, player_size, player_size);
	//item_collider.draw(Color(Palette::White));


	if (player_collider.intersects(item_collider))
	{
		pickup_se.play();
		itemNum = Random(0, 7);
		itemPos = Vec2(Random(50.0f, (float)Window::WIDTH - 50.0f), Random(50.0f, (float)Window::HEIGHT - 50.0f));
		haveItem++;
		//item_collider = Circle(200, 100, 30);
	}

	if (enemy_collision())
	{
		damage_se.play();
		hitCount++;
		playerPos.x = Window::WIDTH / 2;
		playerPos.y = 100;
		enemy3Pos = Vec2(Window::WIDTH / 2, 700);
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
		
}

void CEscape2D::result()
{
	game_bgm.stop();

	if(angle == 0)result_se.play();

	rect_result.draw(Color(Palette::Black));

	bigFont(L"エスケープ成功！").drawCenter(Window::WIDTH / 2, 100);

	if (angle > 60 * 4) font(L"Time : ", score / 60).draw(Window::WIDTH / 5, 250);
	if(angle == 60 * 4) score_se.play();

	if (angle > 60 * 5) font(L"EnemyHit : ", hitCount).draw(Window::WIDTH / 5, 300);
	if(angle == 60 * 5) score_se.play();
		

	String text = L"ハイスコア更新!!";
	if (angle > 60 * 7 && score < hiScore) 
	{
		for (size_t i = 0; i < text.length; ++i)
		{
			font(text[i]).draw(200 + 60 * i, 500, HSV(i * 20 + angle));
		}

		scoreWrite.write(L"Score", L"hiScore", score);
		scoreWrite.write(L"Score", L"hiHitCount", hiHitCount);
	}
	if(angle == 60 * 7 && score < hiScore) 	hiscore_se.play();


	if (angle > 60 * 9)result_bgm.play();

	if (Input::AnyKeyClicked())flug = true;

	angle++;

	if (flug)
	{
		count++;
	
		result_bgm.pause(3.0s);
		rect_result.draw(Color(Palette::White, count));
	}
}

void CEscape2D::playerMove(Vec2& pos)
{
	if (pos.y < (Window::HEIGHT - player_size) && Input::KeyDown.pressed)pos.y += move_speed;
	if (pos.y > 0 && Input::KeyUp.pressed)pos.y -= move_speed;
	if (pos.x > 0 && Input::KeyLeft.pressed)pos.x -= move_speed;
	if (pos.x < (Window::WIDTH - player_size) && Input::KeyRight.pressed)pos.x += move_speed;
}

void CEscape2D::enemyMove(Vec2 startPos, Vec2 targetPos, Vec2& enemyPos, int frame, bool& flug)
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

bool CEscape2D::enemy_collision()
{
	if (player_collider.intersects(enemy1_collider) ||
		player_collider.intersects(enemy2_collider) ||
		player_collider.intersects(enemy3_collider))
	{
		return true;
	}

	return false;
}

