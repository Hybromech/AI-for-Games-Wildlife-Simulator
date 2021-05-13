#pragma once
#include <glm/glm.hpp>
#include <vector>
#include<list>
///An edge consisting a target node and a cost.
struct Edge
{
	//!The target node.
	struct Node* target;
	//!The cost assosiated with the edge.
	float cost;
};

//!A Point in the graph
struct Node
{
	//!The name of the node.
	unsigned int name;
	//!An array of edges that have not been consumed.
	std::vector<Edge> outgoing_edges;
	//!The position of the node.
	glm::vec2 position;
	//!The current gscore. 
	float gscore = 0; // running cost to get to this node
	//!The parrent of this node.
	Node* parent = nullptr; 
}; 

using Path = std::list<Node*>;