#pragma once
#include <SDL.h>

class BasicTypes
{
public:
	BasicTypes() {}
	BasicTypes(SDL_Point position, int width, int height, SDL_Color colour);

	void setPosition(SDL_Point position);
	void draw(SDL_Renderer *renderer);
	SDL_Point GetPosition() { return m_position; };
	SDL_Rect GetRect() { return m_rect; };

protected:
	SDL_Point m_position;
	SDL_Rect m_rect;
	SDL_Color m_colour;
};