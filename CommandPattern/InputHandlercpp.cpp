#include "InputHandler.h"
#include <SDL.h>
void InputHandler::handleInput()
{
	SDL_Event event;
	switch (event.key.keysym.sym)
	{
	case SDLK_x:
		buttonX_->execute();
	case SDLK_y:
		buttonY_->execute();
	case SDLK_a:
		buttonA_->execute();
	case SDLK_b:
		buttonB_->execute();

	}
}