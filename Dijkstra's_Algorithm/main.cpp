/* 

NOTE: When trying to debug with the raylib lib you need to link the the same depdencies
If your app uses libraries, make sure that you link to the same C runtime library(CRT)
(e.g. if it uses Multithreaded DLL you too need to link the same CRT with your app).Otherwise, 
you will get access violation errors.

Since the 3rd party DLL must be a release build DLL, it must have been linked to release version of CRT.While, 
in debug build, your app will link to debug version of CRT.Ask the supplier of the DLL to provide you with a 
debug version of their library also.In debug build, you can link it to the debug version of their DLL.
*/


#include <raylib.h>

#include "Graph.h"
#include <list>
#include "MapReader.h"
#include "MakeNodeGrid.h"
#include <iostream>

using Path = std::list<Node*>;

Path dijkstrasSearch(Node* startNode, Node* endNode);

void DrawPath(const Path& path){
	if (path.size() < 2)
		return;

	for (auto j = path.begin(), i = std::next(j); i != path.end(); ++i ,++j) {
		DrawLine((*i)->position.x, (*i)->position.y, (*j)->position.x, (*j)->position.y, Color{ 255,128,64,255 });
	}
}

void ResetGraph(Node* start, Node* end) {
	for (; start != end; ++start){
		start->gscore = 100000000;
	}
}


int main()
{
	std::cout << "Start Program" << std::endl;
	int screenWidth = 800;
	int screenHeight = 450;
	int tz = 32;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window"); // DJ BUG 1 - Missing ini of window

	//DJ BUG 2 - location of map file was incorrect
	auto mp = ReadaMapInfo("D:/Andrew/AIE/Diploma of Digital and Interactive Games/Subjects/AI for Games/AI_Game/Dijkstra's_Algorithm/Map.map"); //Load in map.
	std::cout << "Start Load Texture" << std::endl;
	//DJ BUG 3 - location of map file was incorrect
	mp.tile_atlas = LoadTexture("D:/Andrew/AIE/Diploma of Digital and Interactive Games/Subjects/AI for Games/AI_Game/textures/forest_tiles.png");
	std::cout << "LoadTexture Done" << std::endl;
	mp.tilesize = tz;
	
	Rectangle rectarray[] = {
		{0,0,tz,tz},
		{13*tz,7*tz,tz,tz},
		{14*tz,7*tz,tz,tz},
		{5*tz, 8*tz,tz,tz}
	};

	mp.rectanglemap = rectarray; //DJ Bug 4 need to set the rectarry into the mp.rectanglemap 
	float terrain_difficulty[] = {1,2,4,impassable };
	auto graph = BuildmodeGraph(mp,tz, terrain_difficulty);
	
	ResetGraph(&graph[0],&graph[graph.size()-1]);

	int start = 0;
	int end = 46;

	auto path = dijkstrasSearch(&graph[start], &graph[end]);

	//InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window"); //DJ Bug 1 This is in the wrong spot see bug 1 above for correct spot

	SetTargetFPS(75);
	
	while (!WindowShouldClose()){ // DJ Bug 6 needs to be WindowShouldClose() as a function not just a var
		auto p = GetMousePosition();
		p.x = (int)(p.x / tz);
		p.y = (int)(p.y / tz);
		int tileid = p.x + p.y * mp.x;
		
		bool moused = false;
		if(IsMouseButtonPressed(0)){
			start = tileid;	
		}
		if (IsMouseButtonPressed(1)) {
			end = tileid;
			moused = true;
		}
		
		 if(moused)
			path = dijkstrasSearch(&graph[start], &graph[end]);
		
		
		std::cout << "Start Begin Drawing" << std::endl;
		BeginDrawing();
		std::cout << "Start ClearBackground" << std::endl;
		ClearBackground(RAYWHITE);
		std::cout << "Start Draw" << std::endl;
		mp.Draw();
		DrawPath(path);
		//Draw hovered tile 
		DrawRectangleLines(p.x * tz, p.y * tz, tz, tz, Color{ 64,255,128,255 });
		std::cout << "Start EndDrawing" << std::endl;
		EndDrawing();
	}
	
	
	CloseWindow(); 
	
	return 0;
}