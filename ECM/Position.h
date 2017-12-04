#pragma once
#include "Component.h"

class Position : public Component
{
private:


public:
	Position() {};
	~Position() {};
	SDL_Point getPoint()
	{
		return position;
	}

	void setPoint(SDL_Point value)
	{
		this->position = value;
	}

	void setComponentInt(int value)
	{
		int values;
		values = value;
		value = 1;
	}
	int getComponentInt()
	{
		return 0;
	}
	SDL_Point position = { 0,0 };
	void setPosition(int x, int y);
};