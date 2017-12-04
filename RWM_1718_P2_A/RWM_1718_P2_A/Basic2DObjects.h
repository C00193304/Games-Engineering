#pragma once
#include "GameObject.h"

class Ground : public GameObject
{
private:
	b2Body* GroundBody;
	Rect GroundRect;
	Sprite GroundSprite;

public:
	Ground() {};
	Ground(b2World*, Renderer&, Rect);
	~Ground() {};

	void Render(Renderer& r);
	void Update(unsigned int deltaTime) {};

	// Set Variables
	void SetType(std::string t) { type = t; };

	// Get Variables
	b2Body* GetBody() { return GroundBody; };
	std::string GetType() { return type; };
};
