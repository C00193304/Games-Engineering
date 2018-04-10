#pragma once
#include "BasicTypes.h"

class Spawner
{

public:
	virtual BasicTypes* smallEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder &grid, SDL_Point* playerPosition) = 0;
	virtual BasicTypes* bigEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder &grid, SDL_Point* playerPosition) = 0;
	virtual BasicTypes* normalEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder &grid, SDL_Point* playerPosition) = 0;

protected:

	Spawner() {};
	~Spawner() {};

};