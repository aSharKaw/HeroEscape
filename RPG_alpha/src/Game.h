#pragma once
#include <iostream>
#include <boost/format.hpp>
#include <random>

using namespace std;
using namespace boost;

class Game
{
public:
	Game();
	~Game();

	void Title();
	void Buttle();

private:
	//�v���C���[�X�e�[�^�X
	string player_name;
	int player_level;
	int player_maxhp;
	int player_hp;
	int player_maxmp;
	int player_mp;
	int player_exp;

	//�G�l�~�[�X�e�[�^�X
	string enemy_name;
	int enemy_hp;
	int enemy_mp;
	int enemy_exp;

};

