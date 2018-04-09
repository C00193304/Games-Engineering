#pragma once
#include "BasicTypes.h"
#include "stdafx.h"

class Tiles : public BasicTypes
{
public:
	Tiles() {};
	Tiles(SDL_Point position, int width, int height, SDL_Color colour, std::string tag);
	std::string getTag() { return m_tag; };
private:
	std::string m_tag;

};