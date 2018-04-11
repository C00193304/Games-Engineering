#pragma once
#include "A-Star.h"
#include "Spawner.h"

class Enemy : public Spawner
{
public:
	Enemy() {};

	~Enemy() {};
	BasicTypes* smallEnemy(SDL_Point position, int width, int height, SDL_Color colour);
	BasicTypes* bigEnemy(SDL_Point position, int width, int height, SDL_Color colour);
	BasicTypes* normalEnemy(SDL_Point position, int width, int height, SDL_Color colour);

private:
	BasicTypes * enemyType;
	SDL_Point m_position;
	SDL_Rect m_rect;
	SDL_Color m_colour;
};