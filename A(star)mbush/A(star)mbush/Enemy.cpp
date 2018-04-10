#include "Enemy.h"

BasicTypes * Enemy::smallEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder & grid, SDL_Point * playerPosition)
{
	enemyType = new BasicTypes(position, width, height, colour);
	m_position = position;

	m_rect.x = position.x;
	m_rect.y = position.y;
	m_rect.w = width;
	m_rect.h = height;

	m_colour = colour;

	return enemyType;
}

BasicTypes * Enemy::bigEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder & grid, SDL_Point * playerPosition)
{
	enemyType = new BasicTypes(position, width, height, colour);
	m_position = position;

	m_rect.x = position.x;
	m_rect.y = position.y;
	m_rect.w = width;
	m_rect.h = height;

	m_colour = colour;

	return enemyType;
}

BasicTypes * Enemy::normalEnemy(SDL_Point position, int width, int height, SDL_Color colour, NodeHolder & grid, SDL_Point * playerPosition)
{
	enemyType = new BasicTypes(position, width, height, colour);
	m_position = position;

	m_rect.x = position.x;
	m_rect.y = position.y;
	m_rect.w = width;
	m_rect.h = height;

	m_colour = colour;

	return enemyType;
}
