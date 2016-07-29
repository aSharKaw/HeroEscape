#pragma once
//#include <boost/assert.hpp>
//#include <boost/filesystem.hpp>

//#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
using namespace std;
using namespace boost;

//namespace fs = boost::filesystem;


class Save
{
public:
	Save();
	
	void Saving(string saveFile_name, string data, int value, string data2, int value2);

};