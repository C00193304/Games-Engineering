#pragma once
#include "Node.h"
#include "Tiles.h"
#include "NodeHolder.h"
#include "Player.h"
#include "Input.h"
#include "Enemy.h"

extern SDL_sem* lock;
extern int wall;
extern std::vector<Tiles*>* tiles;
extern Player* player;
extern int collisions(void*);

class Map
{
private:
	std::vector<Tiles*> m_tiles;
	NodeHolder m_grid;
	Player m_player;
	std::vector<BasicTypes*> m_enemies;

	void setUpMap();
public:
	Map() {};
	Map(EventListener *event);
	void update(float dTime);
	void draw(SDL_Renderer *renderer);
	void spawnEnemies();
	Spawner* enemyPool;
};