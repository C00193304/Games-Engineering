#pragma once

#include <SDL.h>
#include <string>
#include "Sprite.h"
#include <vector>
#include "Box2D\Box2D.h"
#include "BasicTypes.h"
#include "SDL_ttf.h"
using namespace std;

class Button
{
public:
	Button(int x, int y, int w, int h, string word, Renderer&r);
	void Render(Renderer & r);
	void Render(Renderer & r, bool isSelected);
	void Update(unsigned int deltaTime);
	bool CheckEvents();

private:
	TTF_Font* m_font;
	SDL_Color m_colour;
	SDL_Color m_selectColour;
	SDL_Surface* m_surfaceMessage;
	SDL_Texture* m_message;
	SDL_Rect m_messageRect;

	Rect m_boxRect;
	Sprite m_sprite;
	string m_word;
	
};
