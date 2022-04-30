#ifndef _FPS_MANAGER_
#define _FPS_MANAGER_

#include <SDL.h>

class FPS_Manager {
public:
	FPS_Manager();
	void doStart();
	Uint32 getTicks();
	bool isStarted;
private:
	Uint32 myStartTicks;
};

#endif