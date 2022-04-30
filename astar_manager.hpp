#ifndef _ASTAR_MANAGER_
#define _ASTAR_MANAGER_

#include "logger.hpp"

#include "map_manager.hpp"

#include <vector>
#include <deque>

class coord {
public:
	coord();
	coord(int inX, int inY);
	int x, y;
};

class AStarManager {
public:
	AStarManager(Logger* inLogger, MapManager* inMapManager);
	void setStart(int inXGrid, int inYGrid);
	void setEnd(int inXGrid, int inYGrid);
	void resetDistances();

	bool SetAdjacentDistances(node* inThisNode, std::deque<node*> *inNextNodes);
	void RunAStar();
	void createPath(node *inNode);

	std::vector<node*> myPath;
	coord myStart, myEnd;
	bool hasStart, hasEnd, hasPath;
private:
	Logger* myLogger;
	MapManager* myMapManager;
	node *startNode, *endNode;
};

#endif