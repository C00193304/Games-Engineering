#pragma once
#include "SDL_image.h"
#include "Renderer.h"
#include "BasicTypes.h"
#include <iostream>

using namespace std;

class Sprite 
{
private:
	SDL_Texture * Texture;
	SDL_Rect SheetRect;
	SDL_Rect ScreenRect;

public:
	Sprite() {};
	~Sprite() {};

	bool Init(string filepath, Renderer & renderer, Rect Source, Rect Screen);
	void Render(Renderer& r);

	// Set Position
	void setPosition(float x, float y);
	void setPosition(Rect rect);
	void setPosition(Point2D position);

	// Set Size
	void setSize(float x, float y);
	void setSize(Rect rect);
	void setSize(Size2D size);
};