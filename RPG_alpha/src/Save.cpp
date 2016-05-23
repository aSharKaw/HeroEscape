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
	//cout << format("%1%%2%%3%") % "save/�Z�[�u\n" % "copy/�Z�[�u�f�[�^�̃R�s�[\n" % "delete/�Z�[�u�f�[�^�̍폜\n" << endl;
	//cin >> mode;

	Saving(saveData1, name, level);
	cout << "�Z�[�u���܂����B" << endl;

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
		cout << "�t�@�C�������ɂ��邯�Ǐ㏑������H y/n";
		cin >> flag;
		if (flag == "y")
		{
			fs::copy_file(path, dest, fs::copy_option::overwrite_if_exists);
			cout << format("%1% %2% %3% %4%") % origin_save % "��" % copy_save % "�ɏ㏑�����܂����B" << endl;
		}
		else
		{
			cout << "�L�����Z�����܂����B" << endl;
		}

		//throw;
	}
}

void SaveDelete(string savePath)
{
	string flag;

	const fs::path path(savePath);

	cout << format("%1% %2%") % savePath % "���폜���܂��� y/n" << endl;
	cin >> flag;

	if (flag == "y")
	{
		fs::remove(path);
		cout << format("%1% %2%") % savePath % "���폜���܂����B" << endl;
	}
	else
	{
		cout << "�L�����Z�����܂����B" << endl;
	}

}