#include "Load.h"



Load::Load()
{
}


Load::~Load()
{
}

void Load::LoadManager(string data_name)
{
	propertyTree::ptree pt;
	read_ini("res/save1.ini", pt);

	if (boost::optional<any> value = pt.get_optional<any>(data_name))
	{
		//return value.get();
	}
	else
	{
		cout << "Name : データ無し" << endl;
	}

	cout << "ロードしました。" << endl;
}

string Load::getName()
{
	propertyTree::ptree pt;
	read_ini("res/save1.ini", pt);

	if (boost::optional<string> value = pt.get_optional<string>("Data.Name"))
	{
		return value.get();
	}
	else
	{
		cout << "Name : データ無し" << endl;
	}
}

int Load::getLevel()
{
	propertyTree::ptree pt;
	read_ini("res/save1.ini", pt);

	if (boost::optional<int> value = pt.get_optional<int>("Data.Level"))
	{
		return value.get();
	}
	else
	{
		cout << "Level : データ無し" << endl;
	}
}

/*
void SaveLoader(string, string);
template <class T> T SaveLoader(string saveFile_name, string LoadData, T out)
{
	namespace propertyTree = boost::property_tree;

	propertyTree::ptree pt;
	read_ini(saveFile_name, pt);

	if (boost::optional<T> value = pt.get_optional<T>(LoadData))
	{
		cout << "Name : " << value.get() << endl;
		 = value.get();
		out = value.get();
		return out;
	}
	else
	{
		cout << LoadData << "データ無し" << endl;
	}

}
*/