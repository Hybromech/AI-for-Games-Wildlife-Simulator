#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "MapReader.h"

MapObject ReadaMapInfo(std::string filename) {
	std::fstream filein(filename);
	if (!filein.is_open())
		return MapObject();

	std::string line;


	//get header for the size values.
	std::getline(filein, line);
	std::istringstream is{ line };

	//dimension variable
	int x;
	int y;

	is >> x;
	is >> y;


	MapObject mapinfo{ x,y };

	mapinfo.info.reserve(x * y);

	while (!filein.eof()) {
		std::getline(filein, line);
		std::istringstream is{ line };

		while (!is.eof()) {
			std::string tv;
			is >> tv;
			mapinfo.info.push_back(atoi(tv.c_str()));
		}
	}

	return mapinfo;
}