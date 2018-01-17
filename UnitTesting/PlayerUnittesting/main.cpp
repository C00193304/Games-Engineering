#define SDL_MAIN_HANDLED

#include "Player.h"
#include "ExternalLibraries\SDL2-2.0.7\include\SDL.h"
int main()
{
	Player player;
	int timer = 0;
	while (1 != 0)
	{
		if (timer <= 0)
		{
			player.Update();
			timer = 100000000000000;
		}
		else
		{
			timer--;
		}


	}


	//system("PAUSE");

	return 0;
}
