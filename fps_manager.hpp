#ifndef _FPS_MANAGER_
#define _FPS_MANAGER_

#include <SDL.h>

class FPSManager {
public:
	FPSManager();
	void doStart();
	Uint32 getTicks();
	bool isStarted;
private:
	Uint32 myStartTicks;
};

#endif