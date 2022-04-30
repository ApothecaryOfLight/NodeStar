#include "draw_manager.hpp"

#include "logger.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include "map_manager.hpp"

DrawManager::DrawManager(Logger* inLogger, MapManager* inMapManager, AStarManager* inAStarManager, SDL_Renderer* inRenderer) {
	myLogger = inLogger;
	myMapManager = inMapManager;
	myAStarManager = inAStarManager;
	myRenderer = inRenderer;

	doLoadImages();
}

DrawManager::~DrawManager() {
	SDL_DestroyTexture(mySpriteAtlas);
}

void DrawManager::doLoadImages() {
	//Create images
	SDL_Surface* mySpriteAtlasSurface = NULL;
	mySpriteAtlasSurface = IMG_Load("../../NodeStar/media/sprite_atlas.png");
	if (!mySpriteAtlasSurface) {
		myLogger->log(IMG_GetError());
	}
	mySpriteAtlas = SDL_CreateTextureFromSurface(
		myRenderer,
		mySpriteAtlasSurface
	);
	SDL_FreeSurface(mySpriteAtlasSurface);
}

void DrawManager::doDraw() {
	SDL_RenderClear(myRenderer);

	doDrawTerrain();
	doDrawEndpoints();
	if (myAStarManager->hasPath) {
		doDrawPath();
	}

	SDL_RenderPresent(myRenderer);
}

void DrawManager::doDrawTerrain() {
	std::vector<node*>::iterator myIter = myMapManager->myMap.begin();
	std::vector<node*>::iterator myEnd = myMapManager->myMap.end();

	while (myIter != myEnd) {
		SDL_Rect mySrc;
		mySrc.x = 0;
		mySrc.y = 0;
		mySrc.w = 32;
		mySrc.h = 32;
		if ((*myIter)->TerrainType == 1) {
			mySrc.x = 32;
		}

		SDL_Rect myDst;
		myDst.x = (*myIter)->DrawX;
		myDst.y = (*myIter)->DrawY;
		myDst.w = 32;
		myDst.h = 32;

		SDL_RenderCopy(
			myRenderer,
			mySpriteAtlas,
			&mySrc,
			&myDst
		);

		if ((*myIter)->distance != -1) {
			SDL_Rect mySrc;
			mySrc.x = 32 * (*myIter)->distance;
			mySrc.y = 64;
			mySrc.w = 32;
			mySrc.h = 32;
			SDL_RenderCopy(
				myRenderer,
				mySpriteAtlas,
				&mySrc,
				&myDst
			);
		}

		++myIter;
	}
}

void DrawManager::doDrawEndpoints() {
	if (myAStarManager->hasStart) {
		SDL_Rect mySrc;
		mySrc.x = 0;
		mySrc.y = 32;
		mySrc.w = 32;
		mySrc.h = 32;

		SDL_Rect myDst;
		myDst.x = myAStarManager->myStart.x * 32;
		myDst.y = myAStarManager->myStart.y * 32;
		myDst.w = 32;
		myDst.h = 32;

		SDL_RenderCopy(
			myRenderer,
			mySpriteAtlas,
			&mySrc,
			&myDst
		);
	}
	if (myAStarManager->hasEnd) {
		SDL_Rect mySrc;
		mySrc.x = 32;
		mySrc.y = 32;
		mySrc.w = 32;
		mySrc.h = 32;

		SDL_Rect myDst;
		myDst.x = myAStarManager->myEnd.x * 32;
		myDst.y = myAStarManager->myEnd.y * 32;
		myDst.w = 32;
		myDst.h = 32;

		SDL_RenderCopy(
			myRenderer,
			mySpriteAtlas,
			&mySrc,
			&myDst
		);
	}
}

void DrawManager::doDrawPath() {
	std::vector<node*>::iterator myIter = myAStarManager->myPath.begin(), myEnd = myAStarManager->myPath.end();
	while (myIter != myEnd) {
		SDL_Rect mySrc;
		mySrc.x = 64;
		mySrc.y = 32;
		mySrc.w = 32;
		mySrc.h = 32;

		SDL_Rect myDst;
		myDst.x = (*myIter)->DrawX;
		myDst.y = (*myIter)->DrawY;
		myDst.w = 32;
		myDst.h = 32;

		SDL_RenderCopy(
			myRenderer,
			mySpriteAtlas,
			&mySrc,
			&myDst
		);

		++myIter;
	}
}