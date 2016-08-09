#include "Escape2D.h"
#include <Siv3D.hpp>
using namespace std;

void Debug(Camera camera);

void Main()
{
	CEscape2D ESGame2D;

	//Camera camera;

	// カメラの注視点
	//camera.lookat = Vec3(0, -70, 100);

	// カメラの位置
	//camera.pos = Vec3(0, 150, -200);


	//ゲーム時lookat(0, 5, 1000)pos(0, 8, -10)


	Window::SetTitle(L"Let's Go Escape!");
	Window::Resize(800, 800);
	Graphics::SetBackground(Color(Palette::Beige));



	//bool camera_mode = false;
	//bool power = true;
	//int titleMode = 1;
	//int mode = 1;

	Mat3x2 transform;

	while (System::Update())
	{

		//Graphics3D::SetCamera(camera);

		ESGame2D.main();

		//Debug(camera);

	}

}

void Debug(Camera camera)
{
	ClearPrint();
	Println(1_dp, L"lookat: ", camera.lookat);
	Println(1_dp, L"pos: ", camera.pos);

	if (Input::KeyA.pressed)
	{
		camera.pos.x -= 0.1;
		camera.lookat.x -= 0.1;
	}
	if (Input::KeyD.pressed)
	{
		camera.pos.x += 0.1;
		camera.lookat.x += 0.1;
	}
	if (Input::KeyW.pressed)
	{
		camera.pos.y += 0.1;
		camera.lookat.y += 0.1;
	}
	if (Input::KeyS.pressed)
	{
		camera.pos.y -= 0.1;
		camera.lookat.y -= 0.1;
	}
	if (Input::KeyE.pressed)
	{
		camera.pos.z += 0.1;
		camera.lookat.z += 0.1;
	}
	if (Input::KeyC.pressed)
	{
		camera.pos.z -= 0.1;
		camera.lookat.z -= 0.1;
	}

	if (Input::KeyUp.pressed)
	{
		//camera.pos.z += 0.1;
		camera.lookat.z += 0.5;
	}
	if (Input::KeyDown.pressed)
	{
		//camera.pos.z -= 0.1;
		camera.lookat.z -= 0.5;
	}
}
