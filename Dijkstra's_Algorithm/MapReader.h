#pragma once
#include <string>
#include <vector>

struct MapObject
{
	int x;
	int y;
	std::vector<char>info; 
};
MapObject ReadaMapInfo(std::string filename);