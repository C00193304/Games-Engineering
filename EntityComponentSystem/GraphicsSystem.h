#pragma once
#include "Entity.h"
class RenderSystem
{
private:
	std::vector<Entity*> entity;
	SDL_Renderer * sysRenderer;
public:
	RenderSystem(SDL_Renderer* renderer){}
	~RenderSystem() {}

	void addEntity(Entity *ent)
	{
		entity.push_back(ent);
	}

	void Update()
	{
		for (int i = 0; i < entity.size(); i++)
		{
			for (int j = 0; j < entity.at(i)->getComponent().size(); j++)
			{
				if(entity.at(i)->getComponent().at(j))
			}
		}
	}
};