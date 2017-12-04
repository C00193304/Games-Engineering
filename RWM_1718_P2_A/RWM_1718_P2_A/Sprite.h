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
	SDL_Point Origin;
	SDL_RendererFlip Flip;

public:
	Sprite() {};
	~Sprite() {};

	bool Init(string filepath, Renderer & renderer, Rect Source, Rect Screen);

	// Set Origin
	void setOrigin(float x, float y);
	void setOrigin(Point2D origin);

	// Renderers
	void Render(Renderer& r, int angle);
	void Render(Renderer& r);

	// set sheetPosition
	void setSheetPosition(float x, float y);
	void setSheetPosition(Rect rect);
	void setSheetPosition(Point2D position);

	// Set Position
	void setPosition(float x, float y);
	void setPosition(Rect rect);
	void setPosition(Point2D position);

	void setRotation(float angle);

	// Set Size
	void setSize(float x, float y);
	void setSize(Rect rect);
	void setSize(Size2D size);
};