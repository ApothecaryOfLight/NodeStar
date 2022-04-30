#ifndef _TYPE_NODE_
#define _TYPE_NODE_

#include <vector>

class node {
public:
	node(int inTerrainType, bool inIsPassable, int inDrawX, int inDrawY);
	void addConnectedNode(node* inNode);
	int TerrainType;
	int distance;
	bool isPassable;
	int DrawX, DrawY;
	int cartesianGridX, cartesianGridY;
	std::vector<node*> myConnectedNodes;
};

#endif