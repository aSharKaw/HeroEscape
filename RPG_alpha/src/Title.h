/*
�^�C�g������
*/
#pragma once
#include "Misc.h"

class CTitle
{
private:
	CMisc misc;

	void Draw();

	//�t�H���g�w�i
	const Rect textWindow = Rect(0, 5, misc.WIDTH, 60);

	////�f�[�^���[�h�p
	//INIReader scoreRead = INIReader(L"res/ESGame/HiScore.ini");

	//�摜�̗p��
	const Texture texture_titleBG = Texture(L"res/ESGame/image/title.png");
	const Texture texture_titleLogo = Texture(L"res/ESGame/image/titlelogo.png");
	const Texture texture_cloud = Texture(L"res/ESGame/image/kumo.png");

	//���̗p��
	const Sound title_bgm = Sound(L"res/ESGame/audio/title.mp3");

	//���f��
	//Model stageObj = Model(L"res/obj/stage.obj");

	//�n�C�X�R�A
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
