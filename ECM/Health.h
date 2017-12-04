#pragma once
#include "Component.h"

class Health : public Component
{
private:
	int health;

public:
	Health() : health(100) {}
	~Health() {};
	int getHealth()
	{
		return health;
	}
	void setHealth(int health)
	{
		this->health = health;
	}

};