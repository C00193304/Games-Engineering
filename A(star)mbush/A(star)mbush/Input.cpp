#include "Input.h"

Input::Input(EventListener *evt)
{
	m_eventListener = evt;
}

void Input::inputHandl(SDL_Event * evt)
{
	while (SDL_PollEvent(evt))
	{
		switch (evt->type)
		{
			//makes sure only the correct key is pressed and will effect the player at one time
		case SDL_KEYDOWN:
			if (!evt->key.repeat)
			{
				switch (evt->key.keysym.sym)
				{
				case SDLK_w:
					m_eventListener->up = true;
					break;
				case SDLK_s:
					m_eventListener->down = true;
					break;
				case SDLK_a:
					m_eventListener->left = true;
					break;
				case SDLK_d:
					m_eventListener->right = true;
					break;
					
				}
				break;
			}
			//stop the key been pressed hundred of times in between each tick
		case SDL_KEYUP:
			if (!evt->key.repeat)
			{
				switch (evt->key.keysym.sym)
				{
				case SDLK_w:
					m_eventListener->up = false;
					break;
				case SDLK_s:
					m_eventListener->down = false;
					break;
				case SDLK_a:
					m_eventListener->left = false;
					break;
				case SDLK_d:
					m_eventListener->right = false;
					break;

				}
				break;
			}
		}
	}
}
