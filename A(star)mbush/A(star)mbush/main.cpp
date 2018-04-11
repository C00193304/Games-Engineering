#define SDL_MAIN_HANDLED

#include "map.h"
#include "SDL_thread.h"

int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("A*mbush", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Event *e = new SDL_Event();
	EventListener *eventListener = new EventListener;
	Input input(eventListener);

	Map map(eventListener);
	
	SDL_Thread* t1 = SDL_CreateThread(collisions, "Thread no.1", (void*)"Thread no.1");
	SDL_Thread* t2 = SDL_CreateThread(collisions, "Thread no.2", (void*)"Thread no.2");

	bool running = true;
	const float FPS = 60;
	const float timePerFrame = 1.0f / FPS;
	float currentTime = 0;
	float lastTime = 0;
	float deltaTime = 0;

	while (running)
	{
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - lastTime) / 1000;

		if (deltaTime > timePerFrame)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			input.inputHandl(e);

			map.draw(renderer);
			map.update(deltaTime);

			lastTime = currentTime;
		}

		SDL_RenderPresent(renderer);
	}
	SDL_WaitThread(t1, NULL);
	SDL_WaitThread(t2, NULL);

	return 0;
}