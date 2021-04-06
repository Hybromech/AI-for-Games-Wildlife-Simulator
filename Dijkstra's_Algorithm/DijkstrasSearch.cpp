#include "Graph.h"
#include <list>
#include <stdexcept>
#include <unordered_set>
#include<algorithm>
#include <queue>
using Path = std::list<Node*>;

Path dijkstrasSearch(Node* startNode, Node* endNode)
{
	if (!startNode || !endNode)
		throw std::runtime_error("Null nodes supplied");

	if (startNode == endNode) {
		return Path();
	} 

	startNode->gscore = 0;
	startNode->parent = nullptr;

	std::vector<Node*> openList;
	std::unordered_set<Node*> closedList;

	//Add startNode to the openList
	openList.push_back(startNode);

	//While openList is not empty
	while (!openList.empty()) {
		//Sort openlist by Gscore
		auto sortByGScore = [](const Node* l, const Node* r) {
			return l->gscore < r->gscore;
		};
		std::sort(openList.begin(), openList.end(), sortByGScore);

		auto currentNode = openList.front();
		if (currentNode == endNode)
			break;//Found the end.

		openList.erase(openList.begin());

		closedList.insert(currentNode);
		
		for (auto& e : currentNode->outgoing_edges) {
			if (std::find(closedList.begin(), closedList.end(), e.target) == closedList.end()) {
				float gscore = currentNode->gscore + e.cost;

				if (std::find(openList.begin(), openList.end(), e.target) == openList.end()) {
					e.target->gscore = gscore;
					openList.push_back(e.target);
					e.target->parent = currentNode;
				}
				else if (gscore < e.target->gscore){
					e.target->gscore = gscore;
					e.target->parent = currentNode;
				}
			}
		}
	}
	//Build the path and return
	Path path;
	Node* current_node = endNode;
	if (!endNode->parent)
		return path;

	while (current_node){
		path.push_front(current_node);
		current_node = current_node->parent;
	}
	return path;
}