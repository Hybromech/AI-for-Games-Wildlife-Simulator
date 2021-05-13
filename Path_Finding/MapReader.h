#pragma once
#include <string>
#include <vector>
#include <raylib.h>

///Reads in infomation from a text file and draws textures.

struct MapObject
{
	//X dimension of the grid.
	const int x;
	//Y dimension of the grid.
	const int y;
	//Array of chars to store the map positions.
	std::vector<char>info; 
	//Texture tile to be drawn.
	Texture tile_atlas;
	//Rectange that the texture is drawn into.
	Rectangle* rectanglemap;
	//The size of a tile.
	int tilesize;
	//!Draws the textures on the map
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
//!Reads information from the map file.
MapObject ReadaMapInfo(std::string filename);