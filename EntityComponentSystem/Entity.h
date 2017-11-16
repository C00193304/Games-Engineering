#pragma once
#include "Component.h"
#include "Health.h"
#include "Position.h"
#include "Control.h"
#include <vector>

class Entity
{
private:

	std::vector<Component*> component;
public:
	Entity() {}
	~Entity() {}

	Entity(std::string string)
	{
	}

	void Entity::addComponent(Component *comp)
	{
		component.push_back(comp);
	}

	std::vector<Component*> getComponent()
	{
		return component;
	}
};