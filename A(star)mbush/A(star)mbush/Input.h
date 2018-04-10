#pragma once
#include <SDL.h>
#include "EventListener.h"

class Input
{
public:
	Input(EventListener *evt);
	void inputHandl(SDL_Event *evt);
private:
	EventListener * m_eventListener;



};