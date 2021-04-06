#include <raylib.h>

#include "Graph.h"
#include <list>
#include "MapReader.h"
#include "MakeNodeGrid.h"
using Path = std::list<Node*>;

Path dijkstrasSearch(Node* startNode, Node* endNode);

void ResetGraph(Node* start, Node* end) {
	for (; start != end; ++start){
		start->gscore = 100000000;
	}
}


int main()
{
	auto mp = ReadaMapInfo("Map.txt"); //Load in map.

	float terrain_difficulty[] = {1,2,4,impassable };
	auto graph = BuildmodeGraph(mp, terrain_difficulty);
	
	ResetGraph(&graph[0],&graph[graph.size() - 1]);
	auto path = dijkstrasSearch(&graph[0], &graph[60]);
	//Node map[9];
	//enum {A,B,C,D,E,F,G,H,I};
	//
	//map[A] = { 'A',{ {&map[B],1},{&map[F],2}, {&map[E],3} } };
	//map[B] = { 'B',{ {&map[A],1},{&map[C],1} } };
	//map[C] = { 'C',{ {&map[B],1},{&map[D],1} } };
	//map[D] = { 'D',{ {&map[D],1},{&map[E],3},{&map[I],2} }};
	//map[E] = { 'E',{ {&map[F],3},{&map[I],3},{&map[A],3},{&map[D]} } };
	//map[F] = { 'F',{ {&map[A],2},{&map[G],1} ,{&map[E],3} } };
	//map[G] = { 'G',{ {&map[F],1},{&map[H],1} } };
	//map[H] = { 'H',{ {&map[G],1},{&map[I],1} } };
	//map[I] = { 'I',{ {&map[H],1},{&map[D],2},{&map[E],3} } };
	////Reset graph before perform search.
	//ResetGraph(&map[0], &map[8]);
	//
	//auto path = dijkstrasSearch(&map[A], &map[D]);

	//CloseWindow(); 
	
	return 0;
}