//#include <iostream>
#include "Save.h"

Save::Save()
{
	saveData1 = "res/save1.ini";
	saveData2 = "res/save2.ini";
	saveData3 = "save3.ini";
}

//void Saving(string, string, int);
void SaveOverWrite(string, string);
void SaveDelete(string);

void Save::SaveManager(string name, int level)
{
	string saveData1 = "res/save1.ini";
	string saveData2 = "res/save2.ini";
	string saveData3 = "save3.ini";


	string mode;
	//cout << format("%1%%2%%3%") % "save/セーブ\n" % "copy/セーブデータのコピー\n" % "delete/セーブデータの削除\n" << endl;
	//cin >> mode;

	Saving(saveData1, name, level);
	cout << "セーブしました。" << endl;

	if (mode == "save")
	{
		Saving(saveData1, name, level);
	}

}


void Save::Saving(string saveFile_name, string player_name, int level)
{
	namespace propertyTree = boost::property_tree;

	propertyTree::ptree pt;


	pt.put("Data.Name", player_name);
	pt.put("Data.Level", level);

	write_ini(saveFile_name, pt);

}

void SaveOverWrite(string origin_save, string copy_save)
{


	const fs::path path(origin_save);
	const fs::path dest(copy_save);

	try
	{
		fs::copy_file(path, dest);
	}
	catch (fs::filesystem_error& ex)
	{
		string flag;
		cout << "ファイルが既にあるけど上書きする？ y/n";
		cin >> flag;
		if (flag == "y")
		{
			fs::copy_file(path, dest, fs::copy_option::overwrite_if_exists);
			cout << format("%1% %2% %3% %4%") % origin_save % "を" % copy_save % "に上書きしました。" << endl;
		}
		else
		{
			cout << "キャンセルしました。" << endl;
		}

		//throw;
	}
}

void SaveDelete(string savePath)
{
	string flag;

	const fs::path path(savePath);

	cout << format("%1% %2%") % savePath % "を削除しますか y/n" << endl;
	cin >> flag;

	if (flag == "y")
	{
		fs::remove(path);
		cout << format("%1% %2%") % savePath % "を削除しました。" << endl;
	}
	else
	{
		cout << "キャンセルしました。" << endl;
	}

}