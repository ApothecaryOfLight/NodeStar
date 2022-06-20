#include "SDL.h"
#include "SDL_image.h"

#include "logger.hpp"

#include "fps_manager.hpp"

#include "type_node.hpp"

#include "map_manager.hpp"
#include "map_file_manager.hpp"
#include "draw_manager.hpp"
#include "astar_manager.hpp"
#include "input_manager.hpp"

int main(int argc, char *argv[]) {
	Logger* myLogger = new Logger;
	myLogger->log( "Initialized!" );


	//Create SDL pointers
	SDL_Window* myWindow = NULL;
	SDL_Surface* myScreen = NULL;
	SDL_Renderer* myRenderer = NULL;


	//Set up SDL
	SDL_Init(SDL_INIT_VIDEO);
	myWindow = SDL_CreateWindow(
		"NodeStar",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		640,
		SDL_WINDOW_SHOWN
	);
	myRenderer = SDL_CreateRenderer(
		myWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	SDL_SetWindowResizable(myWindow, SDL_TRUE);
	SDL_Event mySDLEvent;


	//Create classes
	MapManager* myMapManager = new MapManager(myLogger);
	MapFileManager* myMapFileManager = new MapFileManager(myLogger, myMapManager);
	AStarManager* myAStarManager = new AStarManager(myLogger, myMapManager);
	DrawManager* myDrawManager = new DrawManager(myLogger, myMapManager, myAStarManager, myRenderer);
	InputManager* myInputManager = new InputManager(myLogger, myMapManager, myAStarManager);
	FPSManager* myFPSManager = new FPSManager;


	//Draw loop
	while (!myInputManager->isQuit) {
		//Start FPS monitoring for this draw loop.
		myFPSManager->doStart();

		//Manage the input.
		myInputManager->processInput(&mySDLEvent);

		//Draw to screen.
		myDrawManager->doDraw();

		//Rely on FPS to determine if the next frame should be drawn yet.
		int frameTicks = myFPSManager->getTicks();
		if (frameTicks < 42) {
			SDL_Delay(42 - frameTicks);
		}
	}

	myMapFileManager->SaveMap("default_map.txt");

	//Cleanup classes
	delete myInputManager;
	delete myDrawManager;
	delete myAStarManager;
	delete myMapFileManager;
	delete myMapManager;


	//Cleanup SDL
	SDL_FreeSurface(myScreen);
	SDL_DestroyRenderer(myRenderer);
	SDL_DestroyWindow(myWindow);
	SDL_Quit();


	//Log a clean exit.
	myLogger->log("Shutting down.");


	//Return from main.
	return 0;
}