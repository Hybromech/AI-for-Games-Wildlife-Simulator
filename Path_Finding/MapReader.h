#pragma once
#include <string>
#include <vector>
#include <raylib.h>

struct MapObject
{
	const int x;
	const int y;
	std::vector<char>info; 
	
	Texture tile_atlas;
	Rectangle* rectanglemap;
	int tilesize;

	void Draw() {
		for (int i = 0; i < x; ++i){
			for (int j = 0; j < y; ++j) {
				int id = i + j * x;
				int mapinfo = info[id];
				Rectangle src = rectanglemap[mapinfo];
				Rectangle dest{ i * tilesize, j * tilesize,tilesize,tilesize };
				DrawTexturePro(tile_atlas, src, dest, Vector2{ 0,0 }, 0, Color{ 255,255,255,255 });
			}
		}
	};
};
MapObject ReadaMapInfo(std::string filename);