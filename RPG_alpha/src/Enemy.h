#pragma once
#include <iostream>
#include <boost/format.hpp>

#include <boost/filesystem.hpp>
//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

using namespace std;
using namespace boost;

namespace propertyTree = boost::property_tree;

class Enemy
{
public:
	Enemy();
	~Enemy();

	//�G�l�~�[�l�[���̎擾
	string getEnemyName(string);
	//�G�l�~�[�X�e�[�^�X�̎擾
	int getEnemyStatus(string);
};

