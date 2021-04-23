#include "MapReader.h"
#include "Graph.h"
#include "MakeNodeGrid.h"
#include "vector"
#include <iostream>


std::vector<Node> BuildmodeGraph(const MapObject& mo, int tilesize, float* terrain) { 
	std::vector<Node> graph;
	graph.resize(mo.info.size());
	
	for (int id = 0; id < mo.info.size(); ++id) { // DJ BUG 5 the map file had a new line at the end making it 101 in size and going behond vector length
		const int x = id % mo.x;
		const int y = id / mo.x;

		bool addLeft = x > 0;
		bool addRight = x < mo.x - 1;
		bool addUp = y < mo.y - 1;
		bool addDown = y > 0;

		int goLeft = -1;
		int goRight = 1;
		int goUp = mo.x;
		int goDown = -mo.x;

		bool addupLeft = addLeft && addUp;
		bool addupRight = addRight && addUp;
		bool adddownleft = addDown && addLeft;
		bool adddownright = addDown && addRight;

		int goUpLeft = goLeft + goUp;
		int goUpRight = goUp + goRight;
		int goDownLeft = goDown + goLeft;
		int goDownRight = goDown + goRight;

		std::cout << "graph[id]" << id;
		std::cout << "graph size" << graph.size();
		
		if (id < graph.size() -1)
		{

			graph[id].name = id;
			graph[id].position = glm::vec2{ x * tilesize + tilesize / 2, y * tilesize + tilesize / 2 };

			auto AddConnection = [&](bool canDirection, int offest, float distance = 1.0f) {
				if (canDirection) {
					float weight = terrain[mo.info[id + 0]];
					if (weight != impassable) {
						graph[id].outgoing_edges.push_back(Edge{ &graph[id + offest] , distance * weight });
					}
				}
			};

			AddConnection(addLeft, goLeft);
			AddConnection(addRight, goRight);
			AddConnection(addUp, goUp);
			AddConnection(addDown, goDown);

			AddConnection(addupLeft, goUpLeft);
			AddConnection(addupRight, goUpRight);
			AddConnection(adddownleft, goDownLeft);
			AddConnection(adddownright, goDownRight);
		}
		else
		{
			std::cout << "Error your reading off the array!" << std::endl;
			std::cout << "graph[id]" << id;
			std::cout << "graph size" << graph.size();
		}
	}
	
	std::cout << "DONE!" << std::endl;
	return graph;
}