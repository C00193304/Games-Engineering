#pragma once

#include <SDL.h>
#include <string>
#include "Sprite.h"
#include <vector>
#include "Box2D\Box2D.h"
#include "BasicTypes.h"
#include "SDL_ttf.h"
using namespace std;

class UIText
{
public:
	UIText(int x, int y, int w, int h, string word, Renderer&r);
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	bool CheckEvents();
	void Update(string word);
private:
	TTF_Font* m_font;
	SDL_Color m_colour;
	SDL_Surface* m_surfaceMessage;
	SDL_Texture* m_message;
	SDL_Rect m_messageRect;
	string m_word;

};
