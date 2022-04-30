#include "type_node.hpp"

node::node(int inTerrainType, bool inIsPassable, int inDrawX, int inDrawY) {
	TerrainType = inTerrainType;
	isPassable = inIsPassable;
	distance = 0;
	DrawX = inDrawX;
	DrawY = inDrawY;
}

void node::addConnectedNode(node* inNode) {
	myConnectedNodes.push_back(inNode);
}

/*
int terrainType;
bool isPassable;
std::vector<node> myConnectedNodes;*/