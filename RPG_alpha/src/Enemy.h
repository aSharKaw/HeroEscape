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

	//エネミーネームの取得
	string getEnemyName(string);
	//エネミーステータスの取得
	int getEnemyStatus(string);
};

