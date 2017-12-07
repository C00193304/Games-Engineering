#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::AddListener(EventListener::Event evt,EventListener *listener)
{
	if (listeners.find(evt) == listeners.end()) 
	{
		//event not in map add it.
		listeners[evt] = new std::vector<EventListener*>();
	}
	listeners[evt]->push_back(listener);
}

//Send the events to interested objects
void InputManager::Dispatch(EventListener::Event evt)
{
	if (listeners.find(evt) != listeners.end()) 
	{
		for (auto const &listener : *listeners[evt])
		{ //go through all listeners for this event
			listener->onEvent(evt); //Call on event for the listener
		}
	}
}


//Genereate events
void InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{
			/* Keyboard event */
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_d:
					Dispatch(EventListener::Event::RIGHT);
					break;
				case SDLK_a:
					Dispatch(EventListener::Event::LEFT);
					break;
				case SDLK_SPACE:
					Dispatch(EventListener::Event::SPACE);
					break;
				}
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.sym)
				{
				case SDLK_d:
					Dispatch(EventListener::Event::RIGHTR);
					break;
				case SDLK_a:
					Dispatch(EventListener::Event::LEFTR);
					break;
				case SDLK_q:
					Dispatch(EventListener::Event::QUITEND);
					break;
				case SDLK_SPACE:
					Dispatch(EventListener::Event::SPACER);
					break;
				}
				Dispatch(EventListener::Event::AnyKey);
				break;
			
			/* SDL_QUIT event (window close) */
			case SDL_QUIT:
				Dispatch(EventListener::Event::QUIT);
				break;
			default:
				break;
			}
	}
	//check for exit
}
