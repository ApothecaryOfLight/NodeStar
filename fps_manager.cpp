#include "fps_manager.hpp"

FPSManager::FPSManager() {
	isStarted = false;
	myStartTicks = 0;
}

void FPSManager::doStart() {
	myStartTicks = SDL_GetTicks();
	isStarted = true;
}

Uint32 FPSManager::getTicks() {
	return (Uint32)(SDL_GetTicks() - myStartTicks);
}