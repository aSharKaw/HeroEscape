/*
�G���ȏ����͂����ł܂Ƃ߂�
*/
#pragma once
#include <Siv3D.hpp>
#include <boost/property_tree/ini_parser.hpp>
using namespace std;

class CMisc
{
public:
	CMisc();
	~CMisc();

	enum Window
	{
		WIDTH = 800,
		HEIGHT = 800
	};

	float bgmValue = 0.8f;

	//���f���f�[�^�ǂݍ���(ModelPath)
	void createModel(Model model);
	//���f���`��(ModelPath, ���W)
	void drawModel(Model model, Vec3 pos, Vec3 rot);
	//�Z�[�u�}�l�[�W���[(FilePath, �i�[��, �Z�[�u�l, �i�[��2, �Z�[�u�l2)
	void saveManager(string saveFileName, string dataName, int value, string dataName2, int value2);
	//���[�h�}�l�[�W���[(FilePath, �i�[��)
	int loadManager(string loadFileName, string dataName);

	Font font;
	Font bigFont;

private:
	
};

