#pragma once
#include "A-Star.h"
#include "Spawner.h"

class Enemy : public Spawner
{
public:
	Enemy() {}
	~Enemy() {};
	BasicTypes* smallEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder &grid, SDL_Point* playerPosition);
	BasicTypes* bigEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder &grid, SDL_Point* playerPosition);
	BasicTypes* normalEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder &grid, SDL_Point* playerPosition);

private:
	BasicTypes * enemyType;
	SDL_Point m_position;
	SDL_Rect m_rect;
	SDL_Color m_colour;
};