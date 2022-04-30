#include "input_manager.hpp"

#include "logger.hpp"

#include <SDL.h>

Input_Manager::Input_Manager(Logger* inLogger) {
	myLogger = inLogger;
	isQuit = false;
}

void Input_Manager::processInput(SDL_Event* inEvent) {
	while (SDL_PollEvent(inEvent)) {
		if (inEvent->type == SDL_KEYDOWN) {
			switch (inEvent->key.keysym.sym) {
			case SDLK_ESCAPE:
				isQuit = true;
				break;
			}
		}
	}
}