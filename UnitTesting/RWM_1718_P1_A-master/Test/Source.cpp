#include "ThomasWasAlone\Player.h"
#include <stdio.h>
#include <assert.h>

int main()
{
	Player* player = new Player();
	int playerPos = player->GetPos().x;

	assert(playerPos != NULL);
	std::cout << playerPos << std::endl;
}