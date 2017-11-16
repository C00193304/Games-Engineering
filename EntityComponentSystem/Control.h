#pragma once
#include "Component.h"

class Control : public Component
{
private:
	SDL_Point velocity = { 0,0 };
	
public:
	Control() {};
	~Control() {};

	SDL_Point getPoint()
	{
		return velocity;
	}
	void setPoint(SDL_Point position)
	{ 
		(this->velocity = position);
	}
	void setComponentInt(int value)
	{
	}

	int getComponentInt()
	{
		return 0;
	}


};