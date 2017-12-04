#define SDL_MAIN_HANDLED

#include <iostream>
#include "SDL.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "Entity.h"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window * window = SDL_CreateWindow("ECS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	Entity* player = new Entity("Player");

	player->addComponent(new Position());
	player->addComponent(new Control());
	player->addComponent(new Health);

	RenderSystem renderSystem;

	renderSystem.addEntity(*player);
	SDL_Event event;
	while (1 != 0)
	{
		SDL_PollEvent(&event);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		renderSystem.Update(renderer);
		SDL_RenderPresent(renderer);
	}
	return 0;
}
