#include "map.h"

SDL_sem* lock;
int wall;
std::vector<Tiles*>* tiles;
Player* player;

Map::Map(EventListener *event)
{
	setUpMap();
	m_grid.SetNodes(36);
	m_grid.AddArcs();
	m_player = Player{ SDL_Point{ 50,50 }, 20, 20, SDL_Color{ 255,0,0,255 }, event };

	lock = SDL_CreateSemaphore(1);
	wall = -1;
	tiles = &m_tiles;
	player = &m_player;
}
void Map::setUpMap()
{
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 36; j++)
		{
			if (i == 0)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, 20, 20, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, "wall");
			}
			else if (j == 0)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, 20, 20, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, "wall");
			}
			else if (i == 63)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, 20, 20, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, "wall");
			}
			else if (j == 35)
			{
				m_tiles.push_back(new Tiles(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, 20, 20, SDL_Color{ 255,255,255,255 }, "wall"));
				m_grid.AddNode(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, "wall");
			}
			else
			{
				m_grid.AddNode(SDL_Point{ i * (int)20.0f, j * (int)20.0f }, "ground");
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
