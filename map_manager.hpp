#ifndef _MAP_MANAGER_
#define _MAP_MANAGER_

#include <vector>

#include "logger.hpp"

#include "type_node.hpp"

class MapManager {
public:
	MapManager(Logger* inLogger);

	void InitializeCartesianGrid();
	void BuildCartesianGridConnectivity( bool withDiagonal );

	bool cartesianIsPassable(int inGridX, int inGridY);
	node* getCartesianNode(int inGridX, int inGridY);

	std::vector<node*> myMap;
private:
	Logger* myLogger;
};

#endif