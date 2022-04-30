#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#include "logger.hpp"

#include "map_manager.hpp"
#include "astar_manager.hpp"

#include <SDL.h>

class InputManager {
public:
	InputManager(Logger* inLogger, MapManager* inMapManager, AStarManager* inAStarManager);
	void processInput(SDL_Event* inEvent);
	bool isQuit;
private:
	Logger* myLogger;
	MapManager* myMapManager;
	AStarManager* myAStarManager;
	int MousePosX, MousePosY;
};

#endif