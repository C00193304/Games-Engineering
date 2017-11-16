#pragma once
#include "Entity.h"

class ControlSystem
{
private:
	std::vector<Entity*> entity;

public:
	ControlSystem() {}
	~ControlSystem() {}

	void addEntity(Entity *ent)
	{
		entity.push_back(ent);
	}

	void Update()
	{
		std::cout << "updating position" << std::endl;
	}

};