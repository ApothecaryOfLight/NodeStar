#ifndef _DRAW_MANAGER_
#define _DRAW_MANAGER_

#include "logger.hpp"

#include <SDL.h>

#include "map_manager.hpp"
#include "astar_manager.hpp"

class DrawManager {
public:
	DrawManager(Logger* inLogger, MapManager* inMapManager, AStarManager* inAStarManager, SDL_Renderer* inRenderer);
	~DrawManager();
	void doLoadImages();
	void doDraw();
	void doDrawTerrain();
	void doDrawEndpoints();
	void doDrawPath();
private:
	Logger* myLogger;
	MapManager* myMapManager;
	AStarManager* myAStarManager;
	SDL_Renderer* myRenderer;
	SDL_Texture* mySpriteAtlas;
};

#endif