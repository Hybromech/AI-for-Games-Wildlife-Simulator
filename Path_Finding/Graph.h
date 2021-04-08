#pragma once
#include <glm/glm.hpp>
#include <vector>
#include<list>

struct Edge
{
	struct Node* target;
	float cost;
};

struct Node
{
	unsigned int name;
	std::vector<Edge> outgoing_edges;
	glm::vec2 position;
	float gscore = 0; // running cost to get to this node
	Node* parent = nullptr; 
}; 

using Path = std::list<Node*>;