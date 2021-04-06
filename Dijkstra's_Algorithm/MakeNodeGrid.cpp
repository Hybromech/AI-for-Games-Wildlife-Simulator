#include "MapReader.h"
#include "Graph.h"
#include "MakeNodeGrid.h"
#include "vector"

std::vector<Node> BuildmodeGraph(const MapObject& mo, float* terrain) { 
	std::vector<Node> graph;
	graph.resize(mo.info.size());
	
	for (int id = 0; id < mo.info.size(); ++id){
		const int x = id % mo.x;
		const int y = id / mo.x;

		bool addLeft = x > 0;
		bool addRight = x < mo.x - 1;
		bool addUp = y < mo.y-1;
		bool addDown = y > 0;

		int goLeft = -1;
		int goRight = 1;
		int goUp = mo.x;
		int goDown = -mo.x;

		graph[id].name = id;

		auto AddConnection = [&](bool canDirection, int offest,float distance = 1.0f) {
			if (canDirection) { 
				float weight = terrain[mo.info[id + offest]];
				if (weight != impassable) {
					graph[id].outgoing_edges.push_back(Edge{ &graph[id + offest] , distance * weight });
				}
			}
		};

		AddConnection(addLeft, goLeft);
		AddConnection(addRight, goRight);
		AddConnection(addUp, goUp);
		AddConnection(addDown, goDown);
	}

	return graph;
}