#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#include "logger.hpp"

#include <SDL.h>

class Input_Manager {
public:
	Input_Manager(Logger* inLogger);
	void processInput(SDL_Event* inEvent);
	bool isQuit;
private:
	Logger* myLogger;
};

#endif