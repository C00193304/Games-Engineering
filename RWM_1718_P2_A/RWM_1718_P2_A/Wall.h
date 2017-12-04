#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
private:
	b2Body* WallBody;
	Rect WallRect;
	Sprite WallSprite;

public:
	Wall() {};
	Wall(b2World*, Renderer&, Rect);
	~Wall() {};

	void Render(Renderer& r);
	void Update(unsigned int deltaTime) {};

	// Set Variables
	void SetType(std::string t) { type = t; };

	// Get Variables
	b2Body* GetBody() { return WallBody; };
	std::string GetType() { return type; };
};