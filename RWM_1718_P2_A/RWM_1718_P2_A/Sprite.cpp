#include "stdafx.h"
#include "Sprite.h"

bool Sprite::Init(string filepath, Renderer & renderer, Rect Source, Rect Screen)
{
	Texture = IMG_LoadTexture(renderer.getRenderer(), filepath.c_str());

	if (Texture == nullptr)
	{
		return false;
	}

	SheetRect.x = Source.pos.x;
	SheetRect.y = Source.pos.y;
	SheetRect.w = Source.size.w;
	SheetRect.h = Source.size.h;

	ScreenRect.x = Screen.pos.x;
	ScreenRect.y = Screen.pos.y;
	ScreenRect.w = Screen.size.w;
	ScreenRect.h = Screen.size.h;

	Origin.x = 0;
	Origin.y = 0;
	Flip = SDL_FLIP_NONE;
	
	return true;
}

void Sprite::setOrigin(float x, float y)
{
	Origin.x = x;
	Origin.y = y;
}

void Sprite::setOrigin(Point2D origin)
{
	Origin.x = origin.x;
	Origin.y = origin.y;
}

void Sprite::Render(Renderer& r, int angle)
{
	SDL_RenderCopyEx(r.getRenderer(), Texture, &SheetRect ,&ScreenRect, angle, &Origin, Flip);
}


void Sprite::Render(Renderer& r)
{
	SDL_RenderCopy(r.getRenderer(), Texture, &SheetRect, &ScreenRect);
}

// Set position functions
void Sprite::setPosition(float x, float y)
{
	ScreenRect.x = x;
	ScreenRect.y = y;
}

void Sprite::setPosition(Rect rect)
{
	ScreenRect.x = rect.pos.x;
	ScreenRect.y = rect.pos.y;
}

void Sprite::setPosition(Point2D position)
{
	ScreenRect.x = position.x;
	ScreenRect.y = position.y;
}

// Set sheet position functions
void Sprite::setSheetPosition(float x, float y)
{
	SheetRect.x = x;
	SheetRect.y = y;
}

void Sprite::setSheetPosition(Rect rect)
{
	SheetRect.x = rect.pos.x;
	SheetRect.y = rect.pos.y;
}

void Sprite::setSheetPosition(Point2D position)
{
	SheetRect.x = position.x;
	SheetRect.y = position.y;
}

// set size functions
void Sprite::setSize(float x, float y)
{
	ScreenRect.w = x;
	ScreenRect.h = y;
}

void Sprite::setSize(Rect rect)
{
	ScreenRect.w = rect.size.w;
	ScreenRect.h = rect.size.h;
}

void Sprite::setSize(Size2D size)
{
	ScreenRect.x = size.w;
	ScreenRect.y = size.h;
}

void Sprite::setRotation(float angle)
{
	
}