#include "type_node.hpp"

node::node(int inTerrainType, bool inIsPassable, int inDrawX, int inDrawY) {
	TerrainType = inTerrainType;
	isPassable = inIsPassable;
	distance = -1;
	DrawX = inDrawX;
	DrawY = inDrawY;
	cartesianGridX = -1;
	cartesianGridY = -1;
}

void node::addConnectedNode(node* inNode) {
	myConnectedNodes.push_back(inNode);
}

/*
int terrainType;
bool isPassable;
std::vector<node> myConnectedNodes;*/