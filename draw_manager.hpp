#ifndef _DRAW_MANAGER_
#define _DRAW_MANAGER_

#include "logger.hpp"

class Draw_Manager {
public:
	Draw_Manager(Logger* inLogger);
private:
	Logger* myLogger;
};

#endif