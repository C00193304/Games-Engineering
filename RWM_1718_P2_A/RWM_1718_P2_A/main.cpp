
#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
	Game game;
	cout << "Initialising Game" << endl;
	if (!game.init())
	{
		cout << "Failed to init game" << '\n';
	}
	
	//run the game loop
	game.loop();

	game.destroy();
	return 0;
}