#ifndef _ASTAR_MANAGER_
#define _ASTAR_MANAGER_

#include "logger.hpp"

#include "map_manager.hpp"

#include <vector>

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
	void RunAStar();

	std::vector<coord> myPath;
	coord myStart, myEnd;
	bool hasStart, hasEnd, hasPath;
private:
	Logger* myLogger;
	MapManager* myMapManager;
};

#endif