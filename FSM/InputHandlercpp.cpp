#include "InputHandler.h"
#include <iostream>
#include <SDL.h>

void InputHandler::handleInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.key.keysym.sym)
	{
	case SDLK_x:
		std::cout << "X IS PRESSED OBAMA" << std::endl;
		//buttonX_->execute();
		break;
	//case SDLK_y:
	//	buttonY_->execute();
	//case SDLK_a:
	//	buttonA_->execute();
	//case SDLK_b:
	//	buttonB_->execute();

	}
}