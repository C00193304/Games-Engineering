#include "map.h"

SDL_sem* lock;
int wall;
std::vector<Tiles*>* tiles;

Map::Map(EventListener *event)
{
	setUpMap();
	m_grid.SetNodes(36);
	m_grid.AddArcs();

	tiles = &m_tiles;
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
}

void Map::draw(SDL_Renderer * renderer)
{
	for (int i = 0; i < m_tiles.size(); i++)
	{
		m_tiles.at(i)->draw(renderer);
	}
}
