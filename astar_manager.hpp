#ifndef _ASTAR_MANAGER_
#define _ASTAR_MANAGER_

#include "logger.hpp"

class AStar_Manager {
public:
	AStar_Manager(Logger* inLogger);
private:
	Logger* myLogger;
};

#endif