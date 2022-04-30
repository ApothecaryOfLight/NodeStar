#include "SDL.h"

#include "logger.hpp"
#include "astar_manager.hpp"
#include "draw_manager.hpp"
#include "mouse_manager.hpp"
#include "type_node.hpp"

#undef main

int main(int argc, char *argv[]) {
	Logger* myLogger = new Logger;
	myLogger->log( "Initialized!" );
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Quit();
	myLogger->log("Shutting down.");
	return 0;
}