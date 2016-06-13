#include "Load.h"
//#include "Game.h"
#include "Escape2D.h"
//#include "Misc.h"
#include "TopMenu.h"

#include <boost\dynamic_bitset.hpp>
#include <boost\lexical_cast.hpp>

#include <Siv3D.hpp>

//any,signal,optional使ってみる

using namespace std;
//using namespace boost;


void Main(/*int args, char* argv[]*/)
{
	CEscape2D ESGame2D;

	CTopMenu top;
	//CMisc misc;

	Camera camera;


	// カメラの注視点
	camera.lookat = Vec3(0, 1.2, 300);

	// カメラの位置
	camera.pos = Vec3(0, 4.5, -24);

	//ゲーム時lookat(0, 5, 1000)pos(0, 8, -10)


	Window::Resize(800, 800);
	Graphics::SetBackground(Color(80, 160, 230));


	const Texture textureGround(L"Example/ground.jpg", TextureDesc::For3D);
	const Mesh meshGround(MeshData::Plane(30, 30, { 6, 6 }));

	bool camera_mode = false;
	bool power = true;
	int titleMode = 1;
	int mode = 0;

	Mat3x2 transform;

	while (System::Update())
	{
		Graphics3D::SetCamera(camera);



		switch (mode)
		{
		case 0:
			//トップメニュー表示
			//2D座標の一括変更
			transform = Mat3x2::Rotate(0, Vec2::Zero)
				.scale(Vec2(0.41, 0.41), Vec2(800 / 2, 140));
			Graphics2D::SetTransform(transform);
			//Mouse::SetTransform(transform);

			////カメラ注視点
			//camera.lookat = Vec3(0, 1.2, 300);

			//// カメラの位置
			//camera.pos = Vec3(0, 4.5, -24);

			top.draw(titleMode, mode, power);
			if (!power)
			{
				ESGame2D.reset();
			}
			
			if (titleMode == 1)
			{
				ESGame2D.title();
			}

			break;

		case 1:
			//ゲームが選択されたら2D表示サイズを変更して対応ゲーム起動
			transform = Mat3x2::Rotate(0, Vec2::Zero)
				.scale(Vec2(1, 1), Vec2(800 / 2, 800 / 5));
			Graphics2D::SetTransform(transform);


			////カメラ注視点
			//camera.lookat = Vec3(0, 5, 1000);

			//// カメラの位置
			//camera.pos = Vec3(0, 8, -10);

			ESGame2D.main();
			break;

		default:
			break;
		}


	}

}

void Debug(Camera camera)
{
	ClearPrint();
	Println(1_dp, L"lookat: ", camera.lookat);
	Println(1_dp, L"pos: ", camera.pos);

	//if (Input::KeyA.pressed)
	//{
	//	camera.pos.x -= 0.1;
	//	camera.lookat.x -= 0.1;
	//}
	//if (Input::KeyD.pressed)
	//{
	//	camera.pos.x += 0.1;
	//	camera.lookat.x += 0.1;
	//}
	//if (Input::KeyW.pressed)
	//{
	//	camera.pos.y += 0.1;
	//	camera.lookat.y += 0.1;
	//}
	//if (Input::KeyS.pressed)
	//{
	//	camera.pos.y -= 0.1;
	//	camera.lookat.y -= 0.1;
	//}
	//if (Input::KeyE.pressed)
	//{
	//	camera.pos.z += 0.1;
	//	camera.lookat.z += 0.1;
	//}
	//if (Input::KeyC.pressed)
	//{
	//	camera.pos.z -= 0.1;
	//	camera.lookat.z -= 0.1;
	//}

	//if (Input::KeyUp.pressed)
	//{
	//	//camera.pos.z += 0.1;
	//	camera.lookat.z += 0.5;
	//}
	//if (Input::KeyDown.pressed)
	//{
	//	//camera.pos.z -= 0.1;
	//	camera.lookat.z -= 0.5;
	//}
}


//int SaveConfirmation(string saveFile_name, string player_name, int player_level)
//{
//	namespace propertyTree = boost::property_tree;
//
//	propertyTree::ptree pt;
//	read_ini(saveFile_name, pt);
//
//	if (boost::optional<string> value = pt.get_optional<string>("Data.Name"))
//	{
//		cout << "Name : " << value.get() << endl;
//		player_name = value.get();
//		//return player_level;
//	}
//	else
//	{
//		cout << "Name : データ無し" << endl;
//	}
//	if (boost::optional<int> value = pt.get_optional<int>("Data.Level"))
//	{
//		cout << "Level : " << value.get() << endl;
//		player_level = value.get();
//		//return player_level;
//	}
//	else
//	{
//		cout << "Level : データ無し" << endl;
//	}
//}

/*

class EnemyAnimation
{
public:
//EnemyAnimation(Texture, エネミー番号, エネミー画像横コマ, アニメフレーム数)
EnemyAnimation(const Texture& texture, int enemyNum,int size, int frame) :
_texture(texture),
_enemyNum(enemyNum),
_size(size),
_frame(frame),
_index(0),
_count(0){}

void update()
{
++_count;

if (_count > _frame)
{
_count = 0;
++_index;

if (_index >= _size)
{
_index = 0;
}
}
}

void draw(const Vec2& pos) const
{
_texture.uv(static_cast<double>(_index) / _size, 0.25 * _enemyNum, 1.0 / _size, 0.25).resize(50, 50).draw(pos);
}

private:
Texture _texture;
int _enemyNum;
int _size;
int _frame;
int _index;
int _count;
};

void Main()
{
Texture texture(L"Example/enemy.png");
Texture player_texture(L"Example/player.png");

EnemyAnimation enemy1(texture, 0, 2, 10);
EnemyAnimation enemy2(texture, 1, 2, 10);
EnemyAnimation enemy3(texture, 2, 2, 10);

const Font font(30);

//Vec2 enemy_size = Vec2(50, 50);
Vec2 enemy_cutSize = Vec2(400, 400);

int player_x = 0;
int player_y = 0;

while (System::Update())
{
enemy1.update();
enemy2.update();
enemy3.update();
for (int i = 0; i < 10; i++)
{
enemy1.draw(Vec2(50 * i, 0));
}
for (int i = 0; i < 10; i++)
{
enemy2.draw(Vec2(50 * i, 50));
}
for (int i = 0; i < 10; i++)
{
enemy3.draw(Vec2(50 * i, 100));
}


player_texture.uv(0, 0, 1, 1).resize(50, 50).draw(player_x, player_y);

if (Input::KeyLeft.pressed)
{
player_x = 100;
}

}
}

*/