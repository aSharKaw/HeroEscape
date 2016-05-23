#pragma once
#include <iostream>
#include <boost/format.hpp>

using namespace std;
using namespace boost;


class Player
{
public:
	Player();
	~Player();

	//プレイヤーステータス
	string player_name;
	int player_level;
	int player_maxhp;
	int player_hp;
	int player_maxmp;
	int player_mp;
	int player_exp;
};

