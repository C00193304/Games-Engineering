#include "Tiles.h"

Tiles::Tiles(SDL_Point position, int width, int height, SDL_Color colour, std::string tag)
{
	m_position = position;
	m_colour = colour;
	m_rect.x = (int)position.x;
	m_rect.y = (int)position.y;
	m_rect.w = width;
	m_rect.h = height;
}
