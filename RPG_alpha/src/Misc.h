/*
雑多な処理はここでまとめて
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

	//モデルデータ読み込み(ModelPath)
	void createModel(Model model);
	//モデル描画(ModelPath, 座標)
	void drawModel(Model model, Vec3 pos, Vec3 rot);
	//セーブマネージャー(FilePath, 格納名, セーブ値, 格納名2, セーブ値2)
	void saveManager(string saveFileName, string dataName, int value, string dataName2, int value2);
	//ロードマネージャー(FilePath, 格納名)
	int loadManager(string loadFileName, string dataName);

	Font font;
	Font bigFont;

private:
	
};

