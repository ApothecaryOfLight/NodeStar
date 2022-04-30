#include "astar_manager.hpp"

#include "logger.hpp"

#include "map_manager.hpp"

#include <vector>
#include <deque>

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
	node* thisNode = myMapManager->getCartesianNode(inXGrid, inYGrid);
	if (thisNode->isPassable) {
		myStart.x = inXGrid;
		myStart.y = inYGrid;
		hasStart = true;
		startNode = thisNode;
		resetDistances();
		if (hasStart && hasEnd) {
			RunAStar();
		}
	}
}

void AStarManager::setEnd(int inXGrid, int inYGrid) {
	node *thisNode = myMapManager->getCartesianNode(inXGrid, inYGrid);
	if (thisNode->isPassable) {
		myEnd.x = inXGrid;
		myEnd.y = inYGrid;
		hasEnd = true;
		endNode = thisNode;
		resetDistances();
		if (hasStart && hasEnd) {
			RunAStar();
		}
	}
}

void AStarManager::resetDistances() {
	std::vector<node*>::iterator myIter = myMapManager->myMap.begin();
	std::vector<node*>::iterator myEnd = myMapManager->myMap.end();
	while (myIter != myEnd) {
		(*myIter)->distance = -1;
		++myIter;
	}
}

bool AStarManager::SetAdjacentDistances(node* inThisNode, std::deque<node*> *inNextNodes) {
	std::vector<node*>::iterator myIter = inThisNode->myConnectedNodes.begin();
	std::vector<node*>::iterator myEnd = inThisNode->myConnectedNodes.end();
	//myLogger->log("setting adjacent distances");
	while (myIter != myEnd) {
		if ((*myIter)->distance == -1) {
			(*myIter)->distance = inThisNode->distance + 1;
			if ((*myIter) == endNode) {
				return true;
			}
			inNextNodes->push_back((*myIter));
		}
		++myIter;
	}
	return false;
	//myLogger->log("set adjacent distances");
}

void AStarManager::RunAStar() {
	std::deque<node*> next_nodes;
	startNode->distance = 0;
	next_nodes.push_back(startNode);

	myLogger->log("running a star");
	while (!next_nodes.empty()) {
		if( SetAdjacentDistances(next_nodes.front(), &next_nodes) ) {
			myLogger->log("found path");
			myPath.clear();
			createPath(endNode);
			hasPath = true;
			break;
		}
		next_nodes.pop_front();
	}
}

void AStarManager::createPath(node *inNode) {
	myLogger->log(inNode->cartesianGridX);
	myLogger->log(inNode->cartesianGridY);
	myLogger->log((int)inNode->myConnectedNodes.size());
	myPath.push_back(inNode);
	std::vector<node*>::iterator myIter = inNode->myConnectedNodes.begin();
	std::vector<node*>::iterator myEnd = inNode->myConnectedNodes.end();
	while (myIter != myEnd) {
		if ((*myIter)->distance != -1) {
			if ((*myIter)->distance < inNode->distance) {
				myLogger->log("Adding node to path.");
				createPath((*myIter));
				break;
			}
		}
		++myIter;
	}	
}