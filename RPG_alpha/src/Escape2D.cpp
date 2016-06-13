//#include "stdafx.h"
#include "Escape2D.h"


CEscape2D::CEscape2D()
{
	reset();

	//乱数シード値を時間から取得
	Reseed(DateTime::Now().second);

	ITEM item_info[]
	{
		{}
	};
}


CEscape2D::~CEscape2D()
{
}

void CEscape2D::reset()
{
	mode = 0;
	angle = 0;

	player_size = Window::WIDTH / 16.0f;
	player_x = Window::WIDTH / 2;
	player_y = Window::HEIGHT / 2;
	move_speed = 5.0f;
	//player_collider = Rect(player_x, player_y, player_size, player_size);


	if (!FontManager::Register(L"res/font/PixelMplus12-Regular.ttf"))
	{
		font = Font(30);
		return;
	}
	else
	{
		font = Font(30, L"PixelMplus12");
	}


	score = 0;
	//hiScore = 0;

	haveItem = 0;
	goalItem = 8;

	textWindow = Rect(0, 5, Window::WIDTH, 60);
}

void CEscape2D::main()
{

	switch (mode)
	{
	case 0:
		if (Input::KeySpace.clicked)
		{
			angle = 0;
			mode = 1;
		}
		title();
		break;
	case 1:
		game();
		if (Input::KeySpace.clicked) haveItem = goalItem;
		if (haveItem == goalItem) mode = 2;
		break;
	case 2:
		result();
		break;
	default:
		break;
	}
}

void CEscape2D::title()
{
	texture_titleBG.resize(Window::WIDTH, Window::HEIGHT).draw();
	texture_cloud(angle, angle, Window::WIDTH, Window::HEIGHT)/*.uv(angle, angle, Window::WIDTH, Window::HEIGHT)*/
		.resize(Window::WIDTH, Window::HEIGHT).draw();
	texture_titleLogo.resize(Window::WIDTH, Window::HEIGHT).draw();
	
	//テキスト表示
	textWindow.draw(Color(255, 255, 255, 100));
	font(L"HiScore : ", hiScore).draw(10, 5, Color(0, 0, 0));

	//font(DateTime::Now()).draw(50, 50, Color(Palette::Black));

	//雲移動
	angle++;
}

void CEscape2D::game()
{
	texture_gameBG.resize(Window::WIDTH, Window::HEIGHT).draw();
	texture_player.resize(player_size, player_size).draw(player_x, player_y);

	//テキスト表示
	textWindow.draw(Color(255, 255, 255, 100));
	font(L"Time : ", score / 60).draw(10, 5, Color(0, 0, 0));
	font(L"GetItem : ", haveItem, L"/", goalItem).draw(Window::WIDTH / 2, 5, Color(0, 0, 0));
	//if (texture_player.intersects(rect));

	//当たり判定の更新
	player_collider = Rect(player_x, player_y, player_size, player_size);
	item_collider = Circle(100, 100, 30);
	item_collider.draw(Color(Palette::White));

	playerMove(player_x, player_y);

	if (player_collider.intersects(item_collider))
	{
		haveItem++;
		item_collider = Circle(200, 100, 30);
	}

	//カウントアップ
	score++;
}

void CEscape2D::result()
{
	rect_result.draw(Color(Palette::Black));

	//		//リザルト
	//		{
	//			music.stop();
	//			music_easy.stop();
	//			result.play();
	//			//結果画面の画像
	//			Texture result("res/result.png");
	//			Texture result1("res/result1.png");
	//
	//			int end_count = 0;
	//			float alpha = 0;
	//			//メインループ
	//			while (1) {
	//
	//				//ウインドウが閉じられたら終了
	//				if (!app_env.isOpen()) return 0;
	//
	//
	//				//描画準備
	//				app_env.setupDraw();
	//
	//				end_count += 1;
	//				alpha += 0.01;
	//
	//				//リザルトイメージ表示
	//				drawTextureBox(-512, -512, 1024, 1024,
	//					0, 0, 1024, 1024,
	//					result1,
	//					Color(1, 1, 1, alpha));
	//
	//
	//				if (end_count >= 120) {
	//
	//					if (app_env.isPushKey('A'))  break;				//タイトルに戻る
	//					if (app_env.isPushKey('Q')) return 0;			//終了
	//
	//					drawTextureBox(-512, -512, 1024, 1024, 0, 0, 1024, 1024,
	//						result,
	//						Color(1, 1, 1));
	//
	//					//タイム表示
	//					if (play_time >= 1) {
	//						NUMBER Count = number_info[count_index];
	//						NUMBER Count10 = number_info[count_index_ten];
	//
	//						drawTextureBox(-440, 450, Count.texture_width, Count.texture_height, Count.texture_x, Count.texture_y,
	//							Count.texture_width, Count.texture_height,
	//							number_image,
	//							Color(1, 1, 1));
	//
	//						count_index = play_time / 60;
	//
	//						drawTextureBox(-472, 450, Count10.texture_width, Count10.texture_height, Count10.texture_x, Count10.texture_y,
	//							Count10.texture_width, Count10.texture_height,
	//							number_image,
	//							Color(1, 1, 1));
	//
	//						count_index_ten = play_time / 60 / 10;
	//					}
	//					//タイム表示(イージー)
	//					if (play_time_easy >= 1) {
	//						NUMBER Count = number_info[count_index];
	//						NUMBER Count10 = number_info[count_index_ten];
	//
	//						drawTextureBox(-440, 450, Count.texture_width, Count.texture_height, Count.texture_x, Count.texture_y,
	//							Count.texture_width, Count.texture_height,
	//							number_image,
	//							Color(1, 1, 1));
	//
	//						count_index = play_time_easy / 60;
	//
	//						drawTextureBox(-472, 450, Count10.texture_width, Count10.texture_height, Count10.texture_x, Count10.texture_y,
	//							Count10.texture_width, Count10.texture_height,
	//							number_image,
	//							Color(1, 1, 1));
	//
	//						count_index_ten = play_time_easy / 60 / 10;
	//					}
	//				}
}

void CEscape2D::playerMove(float& x, float& y)
{
	if (y < (Window::HEIGHT - player_size) && Input::KeyDown.pressed)y += move_speed;
	if (y > 0 && Input::KeyUp.pressed)y -= move_speed;
	if (x > 0 && Input::KeyLeft.pressed)x -= move_speed;
	if (x < (Window::WIDTH - player_size) && Input::KeyRight.pressed)x += move_speed;
}

void CEscape2D::enemyMove()
{
	//				//敵
	//				{
	//					enemy_x += v;
	//
	//					drawTextureBox(enemy_x, enemy_y, 64, 64, 0, 0, 64, 64,
	//						enemy_image,
	//						Color(1, 1, 1));
	//
	//					if (enemy_x > 400) {
	//						v = -v;
	//					}
	//					if (enemy_x < -400) {
	//						v = -v;
	//					}
	//				}
	//
	//				//敵2
	//				{
	//					enemy2_x -= v;
	//					enemy2_y -= v;
	//					drawTextureBox(enemy2_x, enemy2_y, 64, 64, 0, 0, 64, 64,
	//						enemy_image,
	//						Color(1, 1, 1));
	//
	//					if (enemy2_x > 200) {
	//						v = -v;
	//					}
	//					if (enemy2_x < -200) {
	//						v = -v;
	//					}
	//					if (enemy2_y > 50) {
	//						v = -v;
	//					}
	//					if (enemy2_y < -200) {
	//						v = -v;
	//					}
	//				}
	//
	//				//敵3
	//				{
	//					enemy3_x += v;
	//					enemy3_y -= v;
	//					drawTextureBox(enemy3_x, enemy3_y, 64, 64, 0, 0, 64, 64,
	//						enemy_image,
	//						Color(1, 1, 1));
	//
	//					if (enemy3_x > 200) {
	//						v = -v;
	//					}
	//					if (enemy3_x < -200) {
	//						v = -v;
	//					}
	//					if (enemy3_y > 50) {
	//						v = -v;
	//					}
	//					if (enemy3_y < -200) {
	//						v = -v;
	//					}
	//				}
}

bool CEscape2D::RectCollision(Rect& obj1, Rect& obj2)
{

	//当たり判定
	//					bool on_player = false;
	//					//1匹目
	//					if ((X + 40) > enemy_x)
	//					{
	//						if (X < (enemy_x + 40))
	//						{
	//							if ((Y + 40) > enemy_y)
	//							{
	//								if (Y < (enemy_y + 40))
	//								{
	//									on_player = true;
	//								}
	//							}
	//						}
	//					}
	//					//2匹目
	//					if ((X + 40) > enemy2_x)
	//					{
	//						if (X < (enemy2_x + 40))
	//						{
	//							if ((Y + 40) > enemy2_y)
	//							{
	//								if (Y < (enemy2_y + 40))
	//								{
	//									on_player = true;
	//								}
	//							}
	//						}
	//					}
	//					//3匹目
	//					if ((X + 40) > enemy3_x)
	//					{
	//						if (X < (enemy3_x + 40))
	//						{
	//							if ((Y + 40) > enemy3_y)
	//							{
	//								if (Y < (enemy3_y + 40))
	//								{
	//									on_player = true;
	//								}
	//							}
	//						}
	//					}
	//
	//					//当たり判定結果
	//					if (on_player == true) {
	//						X = 0, Y = -100;
	//						play_point = 0;
	//						damege.play();
	//					}



	return false;
}



//
//
//int main() {
//
//	while (1) {
//
//		//ランダム
//		int random_count = 0;
//
//		/*
//
//		struct NUMBER
//		{
//			float texture_x, texture_y;						//切り取り位置
//			float texture_width, texture_height;		//切り取り幅
//
//			int number;			//数字
//		};
//
//		NUMBER number_info[] =
//		{
//			{ 0 * 32, 0, 32, 64, 0 },
//			{ 1 * 32, 0, 32, 64, 1 },
//			{ 2 * 32, 0, 32, 64, 2 },
//			{ 3 * 32, 0, 32, 64, 3 },
//			{ 4 * 32, 0, 32, 64, 4 },
//			{ 5 * 32, 0, 32, 64, 5 },
//			{ 6 * 32, 0, 32, 64, 6 },
//			{ 7 * 32, 0, 32, 64, 7 },
//			{ 8 * 32, 0, 32, 64, 8 },
//			{ 9 * 32, 0, 32, 64, 9 },
//			{ 0 * 32, 0, 32, 64, 0 },
//			{ 1 * 32, 0, 32, 64, 1 },
//			{ 2 * 32, 0, 32, 64, 2 },
//			{ 3 * 32, 0, 32, 64, 3 },
//			{ 4 * 32, 0, 32, 64, 4 },
//			{ 5 * 32, 0, 32, 64, 5 },
//			{ 6 * 32, 0, 32, 64, 6 },
//			{ 7 * 32, 0, 32, 64, 7 },
//			{ 8 * 32, 0, 32, 64, 8 },
//			{ 9 * 32, 0, 32, 64, 9 },
//			{ 0 * 32, 0, 32, 64, 0 },
//			{ 1 * 32, 0, 32, 64, 1 },
//			{ 2 * 32, 0, 32, 64, 2 },
//			{ 3 * 32, 0, 32, 64, 3 },
//			{ 4 * 32, 0, 32, 64, 4 },
//			{ 5 * 32, 0, 32, 64, 5 },
//			{ 6 * 32, 0, 32, 64, 6 },
//			{ 7 * 32, 0, 32, 64, 7 },
//			{ 8 * 32, 0, 32, 64, 8 },
//			{ 9 * 32, 0, 32, 64, 9 },
//			{ 0 * 32, 0, 32, 64, 0 }
//		};
//		Texture number_image("res/number.png");
//
//		struct ITEM
//		{
//			//画像からの切り抜き情報
//			float texture_x, texture_y;						//切り取り位置
//			float texture_width, texture_height;		//切り取り幅
//		};
//
//		ITEM item_info[] =
//		{
//			{ 0 * 32, 0 * 32, 32, 32 },				//(切り取り位置x,y,幅x,y)
//			{ 1 * 32, 0 * 32, 32, 32 },
//			{ 2 * 32, 0 * 32, 32, 32 },
//			{ 3 * 32, 0 * 32, 32, 32 },
//			{ 0 * 32, 1 * 32, 32, 32 },
//			{ 1 * 32, 1 * 32, 32, 32 },
//			{ 2 * 32, 1 * 32, 32, 32 },
//			{ 3 * 32, 1 * 32, 32, 32 },
//			{ 0 * 32, 0 * 32, 32, 32 },				//(切り取り位置x,y,幅x,y)
//			{ 1 * 32, 0 * 32, 32, 32 },
//			{ 2 * 32, 0 * 32, 32, 32 },
//			{ 3 * 32, 0 * 32, 32, 32 },
//			{ 0 * 32, 1 * 32, 32, 32 },
//			{ 1 * 32, 1 * 32, 32, 32 },
//			{ 2 * 32, 1 * 32, 32, 32 },
//			{ 3 * 32, 1 * 32, 32, 32 },
//			{ 0 * 32, 0 * 32, 32, 32 },				//(切り取り位置x,y,幅x,y)
//			{ 1 * 32, 0 * 32, 32, 32 },
//			{ 2 * 32, 0 * 32, 32, 32 },
//			{ 3 * 32, 0 * 32, 32, 32 },
//			{ 0 * 32, 1 * 32, 32, 32 },
//			{ 1 * 32, 1 * 32, 32, 32 },
//			{ 2 * 32, 1 * 32, 32, 32 },
//			{ 3 * 32, 1 * 32, 32, 32 }
//		};
//		//アイテムの画像を読み込む
//		Texture item_image("res/item.png");
//
//		//アイテムをシャッフル
//		int i = 0;
//		while (i < 8)
//		{
//			std::swap(item_info[i],
//				item_info[app_env.random().fromZeroToLast(8)]);
//			i += 1;
//		}
//
//		*/
//
//		//ゲームで使う様々な変数
//		float angle = 0;
//		float X = 0;
//		float Y = -100;
//		int play_time = 0;
//		int play_time_easy = 0;
//		float enemy_x = -100;
//		float enemy_y = -250;
//		float enemy2_x = 0;
//		float enemy2_y = 0;
//		float enemy3_x = 0;
//		float enemy3_y = 0;
//		int item_index = 0;
//		int count_index = 0;
//		int count_index_ten = 0;
//		float x = 0;
//		float y = 0;
//		float v = 5;
//		bool easy;
//		int play_point = 0;
//		float haikei_action = 1;
//		float haikei_alpha = 1;
//		float effect_time = 30;
//		int GetRandom(int min, int max);
//		x = GetRandom(-400, 400);
//		y = GetRandom(-400, 30);
//
//
//		if (app_env.isPushButton(GLFW_MOUSE_BUTTON_LEFT)) {
//			// メインループ　　ここからステージ
//			music.play();
//
//			app_env.bgColor(Color(1, 1, 1));
//
//			// ウインドウが開いている間はずっとこの中を繰り返す
//			while (app_env.isOpen()) {
//
//				// 描画準備
//				app_env.setupDraw();
//
//				//ランダム
//				app_env.random().setSeed(random_count);

//				ITEM Item = item_info[item_index];
//
//
//				//背景描画
//				drawTextureBox(0, 0, 1024, 1024, 0, 0, 1024, 1024, haikei, Color(1, 1, 1, haikei_alpha),
//					M_PI * 0.00, Vec2f(haikei_action, haikei_action), Vec2f(512, 512));
//
//				//アイテム準備
//				//
//				drawTextureBox(x, y, Item.texture_width, Item.texture_height, Item.texture_x, Item.texture_y,
//					Item.texture_width, Item.texture_height,
//					item_image,
//					Color(1, 1, 1));
//
//				bool on_item = false;
//				bool effect_active = false;
//

//
//				/*
//				//アイテム当たり結果
//				if (on_item == true) {
//					item_index += 1;
//					pickup_sound.play();
//					x = GetRandom(-400, 400);
//					y = GetRandom(-400, 30);
//					play_point += 1;
//					effect_time += 30;
//				}
//				if (effect_time > 30) {
//					haikei_action += 0.01;
//					haikei_alpha -= 0.01;
//					effect_active = true;
//					effect_time -= 1;
//				}
//				if (effect_time == 30) {
//					haikei_action = 1;
//					haikei_alpha = 1;
//				}
//				if (effect_active == true) {
//					drawTextureBox(X, Y, 64, 64, 0, 0, 64, 64,
//						effect,
//						Color(1, 1, 1),
//						M_PI * 0.00, Vec2f(1, 1), Vec2f(11, 10));
//				}
//
//				//
//
//

//
//				//ポイントが8でリザルトに
//				if (play_point == 8) {
//					break;
//				}
//
//				//ハイスコア更新チェック
//				if (play_time / 60 < hi_score) {
//					std::ofstream fstr("score.txt");
//					if (fstr) {
//						fstr << play_time / 60 << "秒" << std::endl;
//					}
//				}
//
//				//
//				// 画面を更新
//				app_env.update();
//			} //ここまでステージ
//		}
//
//
//	}
//	// アプリ終了
//}
