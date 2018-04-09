#include "BasicTypes.h"

BasicTypes::BasicTypes(SDL_Point position, int width, int height, SDL_Color colour)
{
	m_position = position;
	m_rect.x = position.x;
	m_rect.y = position.y;
	m_rect.w = width;
	m_rect.h = height;
	m_colour = colour;
}

void BasicTypes::setPosition(SDL_Point position)
{
	m_position = position;
	m_rect.x = position.x;
	m_rect.y = position.y;
}

void BasicTypes::draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, m_colour.r, m_colour.g, m_colour.b, m_colour.a);
	SDL_RenderFillRect(renderer, &m_rect);
}
