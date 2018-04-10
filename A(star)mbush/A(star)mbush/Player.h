#pragma once
#include "BasicTypes.h"
#include "EventListener.h"

class Player : public BasicTypes
{
private:
	SDL_Point m_velocity{0,0};
	EventListener* m_eventListener;

public:
	Player() {}
	Player(SDL_Point position, int width, int height, SDL_Color colour, EventListener *evtListener);
	void setSpeed(float x, float y);
	void update(float dTime);
	SDL_Point getSpeed() { return m_velocity; }
};