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
	return true;
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