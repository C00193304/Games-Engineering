#pragma once
#include "Node.h"
#include "Tiles.h"
#include "NodeHolder.h"
#include "EventListener.h"

extern SDL_sem* lock;
extern int wall;
extern std::vector<Tiles*>* tiles;

class Map
{
private:
	std::vector<Tiles*> m_tiles;
	NodeHolder m_grid;
	void setUpMap();
public:
	Map() {};
	Map(EventListener *event);
	void update(float dTime);
	void draw(SDL_Renderer *renderer);
};