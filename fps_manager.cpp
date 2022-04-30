#include "fps_manager.hpp"

FPS_Manager::FPS_Manager() {
	isStarted = false;
	myStartTicks = 0;
}

void FPS_Manager::doStart() {
	myStartTicks = SDL_GetTicks();
	isStarted = true;
}

Uint32 FPS_Manager::getTicks() {
	return (Uint32)(SDL_GetTicks() - myStartTicks);
}