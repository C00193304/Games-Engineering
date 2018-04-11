#include "map.h"

SDL_sem* lock;
int wall;
std::vector<Tiles*>* tiles;
Player* player;
BasicTypes* enemy;


Map::Map(EventListener *event)
{
	setUpMap();
	m_grid.SetNodes(100);
	m_grid.AddArcs();
	enemyPool = new Enemy();
	m_player = Player{ SDL_Point{ 50,50 }, 20, 20, SDL_Color{ 255,0,0,255 }, event };
	spawnEnemies();

	lock = SDL_CreateSemaphore(1);
	wall = -1;
	tiles = &m_tiles;
	player = &m_player;
	
}
void Map::setUpMap()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i == 0)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, 10, 10, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, "wall");
			}
			else if (j == 0)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, 10, 10, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, "wall");
			}
			else if (i == 99)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, 10, 10, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, "wall");
			}
			else if (j == 99)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, 10, 10, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, "wall");
			}
			else if (i > 20 && i < 22 && j > 0 && j <= 90)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, 10, 10, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, "wall");
			}
			else
			{
				m_grid.AddNode(SDL_Point{ i * (int)10.0f, j * (int)10.0f }, "ground");
			}
		}
	}
}

void Map::update(float dTime)
{
	m_player.update(dTime);
}

void Map::draw(SDL_Renderer * renderer)
{
	for (int i = 0; i < m_tiles.size(); i++)
	{
		m_tiles.at(i)->draw(renderer);
	}

	m_player.draw(renderer);
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies.at(i)->draw(renderer);
	}
}

void Map::spawnEnemies()
{
	srand(SDL_GetTicks());
	for (int i = 0; i < 6; i++)
	{
		switch (rand() % 3 + 1)
		{
		case 1:
			m_enemies.push_back(enemyPool->smallEnemy({ rand() % 1920, rand() % 1080 }, 10, 10, { 255,0,0,255 }));
			break;
		case 2:
			m_enemies.push_back(enemyPool->normalEnemy({ rand() % 1920, rand() % 1080 }, 20, 20, { 255,0,0,255 }));
			break;
		case 3:
			m_enemies.push_back(enemyPool->bigEnemy({ rand() % 1920, rand() % 1080 }, 30, 30, { 255,0,0,255 }));
			break;
		default:
			break;
		}
	}
}

int collisions(void*)
{
	int  wallI = -1;

	while (true)
	{
		SDL_SemWait(lock);
		wall++;
		if (wall >= tiles->size())
		{
			wall = 0;
		}
		wallI = wall;
		if (wallI >= tiles->size())
		{
			wallI = 0;
		}

		SDL_SemPost(lock);

		SDL_Rect tempRect = { 0,0,0,0 };
		if (SDL_IntersectRect(&player->GetRect(), &tiles->at(wallI)->GetRect(), &tempRect))
		{
			//top half collision code
			if (tempRect.w > tempRect.h)
			{
				if (player->GetPosition().y > tiles->at(wallI)->GetPosition().y)
				{
					//set the player position back to the temp rect plus the x position stays the same
					player->setPosition(SDL_Point{ player->GetPosition().x, player->GetRect().y + tempRect.h });
				}
				else
				{
					player->setPosition(SDL_Point{ player->GetPosition().x, player->GetRect().y - tempRect.h });
				}
				player->setSpeed(player->getSpeed().x, 0);
			}
			else
			{
				if (player->GetPosition().x > tiles->at(wallI)->GetPosition().x)
				{
					player->setPosition(SDL_Point{ player->GetRect().x + tempRect.w, player->GetPosition().y });
				}
				else
				{
					player->setPosition(SDL_Point{ player->GetRect().x - tempRect.w, player->GetPosition().y });
				}
				player->setSpeed(0, player->getSpeed().y);
			}
		}
	}
	return 0;
}
