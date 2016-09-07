/*
タイトル処理
*/
#pragma once
#include "Misc.h"

class CTitle
{
private:
	CMisc misc;

	void Draw();

	//フォント背景
	const Rect textWindow = Rect(0, 5, misc.WIDTH, 60);

	////データロード用
	//INIReader scoreRead = INIReader(L"res/ESGame/HiScore.ini");

	//画像の用意
	const Texture texture_titleBG = Texture(L"res/ESGame/image/title.png");
	const Texture texture_titleLogo = Texture(L"res/ESGame/image/titlelogo.png");
	const Texture texture_cloud = Texture(L"res/ESGame/image/kumo.png");

	//音の用意
	const Sound title_bgm = Sound(L"res/ESGame/audio/title.mp3");

	//モデル
	//Model stageObj = Model(L"res/obj/stage.obj");

	//ハイスコア
	//int hiScore;
	//int hiHitCount;

	bool sceneMoveFlug;
	int count;
	int cloudAngle;

	const int SCENE_MOVE_TIME = 60 * 4;

public:
	CTitle();
	~CTitle();

	void Reset();
	
	bool Title(int hiScore, int hiHitCount);
};
