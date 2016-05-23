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

//namespace fs = boost::filesystem;

class Load
{
public:
	Load();
	~Load();

	void LoadManager(string);

	string getName();
	int getLevel();

};

