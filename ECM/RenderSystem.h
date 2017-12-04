#pragma once
#include "Entity.h"
#include "SDL.h"

class RenderSystem
{
private:
	std::vector<Entity*> entity;
	SDL_Renderer * sysRenderer;
public:
	RenderSystem();
	RenderSystem(SDL_Renderer* renderer) {}
	~RenderSystem() {}

	void addEntity(Entity &ent)
	{
		entity.push_back(&ent);
	}

	void Update(SDL_Renderer* renderer);
};