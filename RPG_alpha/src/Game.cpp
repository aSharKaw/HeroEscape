#include "Game.h"
#include "Enemy.h"
#include "Save.h"
#include "Load.h"

Game::Game()
{
	player_name = "";
	player_level = player_maxhp = player_hp = player_maxmp = player_mp = player_exp = 0;
	

}

Game::~Game()
{
}

Enemy enemy;


void Game::Title()
{
	Save save;
	Load load;

	string _mode;

		const Font font(30);
	
		font(L"Title").draw();


	//cout << format("%1%%2%%3%") 
	//	% "-------\n" 
	//	% " Title\n" 
	//	% "-------\n\n";
	//cout << format("%1%%2%") 
	//	% "・New  Game\n" 
	//	% "・Load Game\n";


	//cout << "Select Menu->(n/l)" << endl;
	//cin >> _mode;

	//if (_mode == "n")
	//{
	//	std::system("cls");


	//	cout << format("%1%%2%%3%")
	//		% "Welcome World!!\n\n"
	//		% "Create Player\n"
	//		% "Player Name? ->";
	//	cin >> player_name;


	//	cout << format("%1%")
	//		% "...OK!";

	//	save.Saving("res/save1.ini", player_name, 1);
	//}
	//else if (_mode == "l")
	//{
	//	std::system("cls");

	//	
	//	player_name = load.getName();
	//	player_level = load.getLevel();

	//	//player_name = load.LoadManager("Data.Name");
	//	//player_level = load.LoadManager("Data.level");

	//	
	//	cout << format("%1%%2%%3%%4%")
	//		% "Loaded \nPlayerName : "
	//		% player_name
	//		% "\nPlayerLevel : "
	//		% player_level << endl;
	//}
	
}

void Game::Buttle()
{
	string command;

	//敵のロード
	enemy_name = enemy.getEnemyName("Enemy1.Name");
	enemy_hp = enemy.getEnemyStatus("Enemy1.hp");
	enemy_mp = enemy.getEnemyStatus("Enemy1.mp");
	enemy_exp = enemy.getEnemyStatus("Enemy1.exp");



	cout << format("%1%%2%%3%")
		% "\n\nEncount "
		% enemy_name
		% "!!\n";


	cout << format("%1%")
		% "Command? ->";
	cin >> command;



}