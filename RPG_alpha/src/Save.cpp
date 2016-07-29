#include "Save.h"

Save::Save()
{
}

//Score.HiScore
//Score.hiHitCount

//‚±‚ê‚µ‚©Žg‚Á‚Ä‚È‚¢‚Ì‚ÅˆÚ“®‚·‚é
void Save::Saving(string saveFile_name, string data, int value, string data2, int value2)
{
	namespace propertyTree = boost::property_tree;

	propertyTree::ptree pt;


	//pt.put("Score.HiScore", player_name);
	pt.put(data, value);
	pt.put(data2, value2);


	write_ini(saveFile_name, pt);

}
