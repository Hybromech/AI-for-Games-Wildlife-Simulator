#pragma once

#include "Graph.h"
#include <vector>
#include "MapReader.h"
//!variable to store an impassable value.
const float impassable = -1;
//!Builds a Graph of nodes
std::vector<Node> BuildmodeGraph(const MapObject& mo, int tilesize, float* terrain);