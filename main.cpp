#include "SDL.h"
#include "SDL_image.h"

#include "logger.hpp"

#include "type_node.hpp"
#include "draw_manager.hpp"
#include "astar_manager.hpp"
#include "input_manager.hpp"

int main(int argc, char *argv[]) {
	Logger* myLogger = new Logger;
	myLogger->log( "Initialized!" );

	//Create classes
	Draw_Manager* myDrawManager = new Draw_Manager(myLogger);
	AStar_Manager* myAStar_Manager = new AStar_Manager(myLogger);
	Input_Manager* myInputManager = new Input_Manager(myLogger);


	//Create SDL pointers
	SDL_Window* myWindow = NULL;
	SDL_Surface* myScreen = NULL;
	SDL_Surface* mySpriteAtlas = NULL;

	SDL_Renderer* myRenderer = NULL;


	//Set up SDL
	SDL_Init(SDL_INIT_VIDEO);

	myWindow = SDL_CreateWindow(
		"NodeStar",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		600,
		SDL_WINDOW_SHOWN
	);

	myRenderer = SDL_CreateRenderer(
		myWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	SDL_SetWindowResizable(myWindow, SDL_TRUE);
	SDL_Event mySDLEvent;


	//Create images
	mySpriteAtlas = IMG_Load("../../NodeStar/media/sprite_atlas.png");
	if (!mySpriteAtlas) {
		myLogger->log(IMG_GetError());
	}
	SDL_Texture* myTexture = SDL_CreateTextureFromSurface(
		myRenderer,
		mySpriteAtlas
	);
	SDL_FreeSurface(mySpriteAtlas);
	SDL_Rect mySrc;
	mySrc.x = 0;
	mySrc.y = 0;
	mySrc.w = 32;
	mySrc.h = 32;


	//Draw loop
	while (!myInputManager->isQuit) {
		myInputManager->processInput(&mySDLEvent);
		SDL_RenderClear(myRenderer);
		SDL_RenderCopy(
			myRenderer,
			myTexture,
			&mySrc,
			&mySrc
		);
		SDL_RenderPresent(myRenderer);
	}


	//Cleanup
	SDL_FreeSurface(myScreen);
	SDL_DestroyTexture(myTexture);
	SDL_DestroyRenderer(myRenderer);
	SDL_DestroyWindow(myWindow);
	SDL_Quit();
	myLogger->log("Shutting down.");
	return 0;
}