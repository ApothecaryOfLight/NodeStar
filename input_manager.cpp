#include "input_manager.hpp"

#include "logger.hpp"

#include <SDL.h>

InputManager::InputManager(Logger* inLogger, MapManager* inMapManager, AStarManager* inAStarManager) {
	myLogger = inLogger;
	myMapManager = inMapManager;
	myAStarManager = inAStarManager;
	isQuit = false;
}

void InputManager::processInput(SDL_Event* inEvent) {
	SDL_GetMouseState(&MousePosX, &MousePosY);
	while (SDL_PollEvent(inEvent)) {
		if (inEvent->type == SDL_KEYDOWN) {
			switch (inEvent->key.keysym.sym) {
			case SDLK_ESCAPE:
				isQuit = true;
				break;
			}
		}
		if (inEvent->type == SDL_MOUSEBUTTONDOWN) {
			if (inEvent->button.button == SDL_BUTTON_LEFT) {
				myAStarManager->setStart(
					(MousePosX - (MousePosX % 32)) / 32,
					(MousePosY - (MousePosY % 32)) / 32
				);
			}
			if (inEvent->button.button == SDL_BUTTON_RIGHT) {
				myAStarManager->setEnd(
					(MousePosX - (MousePosX % 32)) / 32,
					(MousePosY - (MousePosY % 32)) / 32
				);
			}
		}
	}
}