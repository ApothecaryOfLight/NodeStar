#include "map_manager.hpp"

MapManager::MapManager(Logger* inLogger) {
	myLogger = inLogger;

	InitializeCartesianGrid();
	BuildCartesianGridConnectivity(true);
}

void MapManager::InitializeCartesianGrid() {
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			node* myNode = new node(
				0,
				true,
				32*x,
				32*y
			);
			myNode->cartesianGridX = x;
			myNode->cartesianGridY = y;
			myMap.push_back(myNode);
		}
	}

	myMap[20]->TerrainType = 1;
	myMap[20]->isPassable = false;

	myMap[25]->TerrainType = 1;
	myMap[25]->isPassable = false;

	myMap[45]->TerrainType = 1;
	myMap[45]->isPassable = false;

	myMap[65]->TerrainType = 1;
	myMap[65]->isPassable = false;

	myMap[85]->TerrainType = 1;
	myMap[85]->isPassable = false;

	myMap[105]->TerrainType = 1;
	myMap[105]->isPassable = false;

	myMap[125]->TerrainType = 1;
	myMap[125]->isPassable = false;


	myMap[44]->TerrainType = 1;
	myMap[44]->isPassable = false;

	myMap[55]->TerrainType = 1;
	myMap[55]->isPassable = false;

	myMap[66]->TerrainType = 1;
	myMap[66]->isPassable = false;

	myMap[77]->TerrainType = 1;
	myMap[77]->isPassable = false;

	myMap[88]->TerrainType = 1;
	myMap[88]->isPassable = false;

	myMap[99]->TerrainType = 1;
	myMap[99]->isPassable = false;

	myMap[79]->TerrainType = 1;
	myMap[79]->isPassable = false;

	myMap[80]->TerrainType = 1;
	myMap[80]->isPassable = false;

	myMap[81]->TerrainType = 1;
	myMap[81]->isPassable = false;

	myMap[111]->TerrainType = 1;
	myMap[111]->isPassable = false;

	myMap[112]->TerrainType = 1;
	myMap[112]->isPassable = false;

	myMap[113]->TerrainType = 1;
	myMap[113]->isPassable = false;

	myMap[122]->TerrainType = 1;
	myMap[122]->isPassable = false;

	myMap[142]->TerrainType = 1;
	myMap[142]->isPassable = false;

	myMap[143]->TerrainType = 1;
	myMap[143]->isPassable = false;

	myMap[133]->TerrainType = 1;
	myMap[133]->isPassable = false;

	myMap[134]->TerrainType = 1;
	myMap[134]->isPassable = false;

	myMap[135]->TerrainType = 1;
	myMap[135]->isPassable = false;

	myMap[144]->TerrainType = 1;
	myMap[144]->isPassable = false;

	myMap[164]->TerrainType = 1;
	myMap[164]->isPassable = false;

}

void MapManager::BuildCartesianGridConnectivity(bool withDiagonal) {
	//Build connectivity between nodes
	std::vector<node*>::iterator myIter = myMap.begin(), myEnd = myMap.end();
	while (myIter != myEnd) {
		if ((*myIter)->cartesianGridY > 0) {
			node* node_north = getCartesianNode((*myIter)->cartesianGridX, (*myIter)->cartesianGridY - 1);
			if (node_north->isPassable) {
				(*myIter)->addConnectedNode(node_north);
			}
		}
		if ((*myIter)->cartesianGridX < 19) {
			node* node_east = getCartesianNode((*myIter)->cartesianGridX + 1, (*myIter)->cartesianGridY);
			if (node_east->isPassable) {
				(*myIter)->addConnectedNode(node_east);
			}
		}
		if ((*myIter)->cartesianGridY < 19) {
			node* node_south = getCartesianNode((*myIter)->cartesianGridX, (*myIter)->cartesianGridY + 1);
			if (node_south->isPassable) {
				(*myIter)->addConnectedNode(node_south);
			}
		}
		if ((*myIter)->cartesianGridX > 0) {
			node* node_west = getCartesianNode((*myIter)->cartesianGridX - 1, (*myIter)->cartesianGridY);
			if (node_west->isPassable) {
				(*myIter)->addConnectedNode(node_west);
			}
		}
		if (withDiagonal) {
			if ((*myIter)->cartesianGridY > 0 && (*myIter)->cartesianGridX > 0) {
				node* node_north_west = getCartesianNode((*myIter)->cartesianGridX - 1, (*myIter)->cartesianGridY - 1);
				if (node_north_west->isPassable) {
					(*myIter)->addConnectedNode(node_north_west);
				}
			}
			if ((*myIter)->cartesianGridY > 0 && (*myIter)->cartesianGridX < 19) {
				node* node_north_east = getCartesianNode((*myIter)->cartesianGridX + 1, (*myIter)->cartesianGridY - 1);
				if (node_north_east->isPassable) {
					(*myIter)->addConnectedNode(node_north_east);
				}
			}
			if ((*myIter)->cartesianGridY < 19 && (*myIter)->cartesianGridX < 19) {
				node* node_south_east = getCartesianNode((*myIter)->cartesianGridX + 1, (*myIter)->cartesianGridY + 1);
				if (node_south_east->isPassable) {
					(*myIter)->addConnectedNode(node_south_east);
				}
			}
			if ((*myIter)->cartesianGridY < 19 && (*myIter)->cartesianGridX > 0 ) {
				node* node_south_west = getCartesianNode((*myIter)->cartesianGridX - 1, (*myIter)->cartesianGridY + 1);
				if (node_south_west->isPassable) {
					(*myIter)->addConnectedNode(node_south_west);
				}
			}
		}
		++myIter;
	}
}

bool MapManager::cartesianIsPassable(int inGridX, int inGridY) {
	std::vector<node*>::iterator myIter = myMap.begin(), myEnd = myMap.end();
	while (myIter != myEnd) {
		if ((*myIter)->cartesianGridX == inGridX && (*myIter)->cartesianGridY == inGridY) {
			return (*myIter)->isPassable;
		}
		++myIter;
	}
}

node* MapManager::getCartesianNode(int inGridX, int inGridY) {
	std::vector<node*>::iterator myIter = myMap.begin(), myEnd = myMap.end();
	while (myIter != myEnd) {
		if ((*myIter)->cartesianGridX == inGridX && (*myIter)->cartesianGridY == inGridY) {
			return (*myIter);
		}
		++myIter;
	}
	return NULL;
}