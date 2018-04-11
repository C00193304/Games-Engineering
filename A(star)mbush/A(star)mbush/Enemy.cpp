#include "Enemy.h"

BasicTypes * Enemy::smallEnemy(SDL_Point position, int width, int height, SDL_Color colour)
{
	enemyType = new BasicTypes(position, 10, 10, colour);

	return enemyType;
}

BasicTypes * Enemy::bigEnemy(SDL_Point position, int width, int height, SDL_Color colour)
{
	enemyType = new BasicTypes(position, 30, 30, colour);


	return enemyType;
}

BasicTypes * Enemy::normalEnemy(SDL_Point position, int width, int height, SDL_Color colour)
{
	enemyType = new BasicTypes(position, 20, 20, colour);


	return enemyType;
}