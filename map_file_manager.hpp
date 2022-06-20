#ifndef _MAP_FILE_MANAGER_
#define _MAP_FILE_MANAGER_

#include "logger.hpp"

#include "map_manager.hpp"

class MapFileManager {
public:
	MapFileManager(Logger *myLogger, MapManager *inMapManager);
	node* NodifyString(std::string inStringNode);
	void LoadMap(std::string inMapName);

	std::string itoa(int inInteger);
	std::string btoa(bool inBoolean);
	std::string stringifyNode(node* inNode);
	void SaveMap(std::string outMapName);
private:
	Logger* myLogger;
	MapManager *myMapManager;
};

#endif