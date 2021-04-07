#pragma once

#include "Graph.h"
#include <vector>
#include "MapReader.h"

const float impassable = -1;

std::vector<Node> BuildmodeGraph(const MapObject& mo, int tilesize, float* terrain);
