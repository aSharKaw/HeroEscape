#include <iostream>
#include <conio.h>
#include <stdio.h>
//#include <boost/date_time/gregorian/gregorian.hpp>
//#include <boost/assert.hpp>
#include "Save.h"
#include "Load.h"
#include "Game.h"

#include <boost\dynamic_bitset.hpp>
#include <boost\lexical_cast.hpp>

//#include <GLFW\glfw3.h>




using namespace std;
//using namespace boost;


void main(int args, char* argv[])
{
	//if (!glfwInit()) return -1;



	//Save save;
	//Load load;
	Game game;

	string player;
	int level = 0;

	string mode;

	int input_key;

	while (1)
	{
		//if (_kbhit()) input_key = _getch();
		//cout << input_key << endl;
		

		game.Title();
		
		game.Buttle();


	}

}




//int SaveConfirmation(string saveFile_name, string player_name, int player_level)
//{
//	namespace propertyTree = boost::property_tree;
//
//	propertyTree::ptree pt;
//	read_ini(saveFile_name, pt);
//
//	if (boost::optional<string> value = pt.get_optional<string>("Data.Name"))
//	{
//		cout << "Name : " << value.get() << endl;
//		player_name = value.get();
//		//return player_level;
//	}
//	else
//	{
//		cout << "Name : �f�[�^����" << endl;
//	}
//	if (boost::optional<int> value = pt.get_optional<int>("Data.Level"))
//	{
//		cout << "Level : " << value.get() << endl;
//		player_level = value.get();
//		//return player_level;
//	}
//	else
//	{
//		cout << "Level : �f�[�^����" << endl;
//	}
//}





//void LastDay()
//{
//	int year = 0;
//	int month = 0;
//
//	using namespace gregorian;
//
//	cout << "����́H";
//	cin >> year;
//	cout << "���́H";
//	cin >> month;
//
//
//	BOOST_ASSERT_MSG(month < 12, "�s���Ȓl���́@�v���O�������I�����܂��B");
//
//
//	const int printDay = gregorian_calendar::end_of_month_day(year, month);
//	std::cout << format("%1% %2%�@%3% %4% %5%") % year % "�N" % month % "���̍ŏI����" % printDay << endl;
//
//}


/////////////////////////


//BOOST_ASSERT(1 == 1);

//�v���O�����G���[�ŏI��������
//BOOST_ASSERT(1 != 1);

//�����\��
//cout << format("%1%") % "Hello!!" << endl;
