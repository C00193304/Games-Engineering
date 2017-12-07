//#include "Player.h"
#include <stdio.h>
#include <assert.h>
#include "ThomasWasAlone\Player.h"
int main()
{
	Player* player = new Player();
	player->SetPos(Point2D(10, 0));
	int playerPos = player->GetPos().x;

	assert(playerPos != NULL);
	std::cout << playerPos << std::endl;
}