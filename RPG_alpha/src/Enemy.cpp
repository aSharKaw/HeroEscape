#include "Enemy.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

string Enemy::getEnemyName(string data_tag)
{
	propertyTree::ptree pt;
	read_ini("res/Enemy/enemy.ini", pt);

	if (boost::optional<string> value = pt.get_optional<string>(data_tag))
	{
		//cout << "Name : " << value.get() << endl;
		return value.get();
	}
	else
	{
		//cout << "Name : データ無し" << endl;
	}
}

int Enemy::getEnemyStatus(string data_tag)
{
	propertyTree::ptree pt;
	read_ini("res/Enemy/enemy.ini", pt);

	if (boost::optional<int> value = pt.get_optional<int>(data_tag))
	{
		//cout << data_tag << " : " << value.get() << endl;
		return value.get();
	}
	else
	{
		//cout << data_tag << " : データ無し" << endl;
	}
}