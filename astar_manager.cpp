#include "astar_manager.hpp"

#include "logger.hpp"

#include "map_manager.hpp"

coord::coord() {

}

coord::coord(int inX, int inY) {
	x = inX;
	y = inY;
}

AStarManager::AStarManager(Logger* inLogger, MapManager* inMapManager) {
	myLogger = inLogger;
	myMapManager = inMapManager;

	hasStart = false;
	hasEnd = false;
	hasPath = false;
}

void AStarManager::setStart(int inXGrid, int inYGrid) {
	myStart.x = inXGrid;
	myStart.y = inYGrid;
	hasStart = true;
}

void AStarManager::setEnd(int inXGrid, int inYGrid) {
	myEnd.x = inXGrid;
	myEnd.y = inYGrid;
	hasEnd = true;
}

void AStarManager::RunAStar() {

}