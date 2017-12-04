#pragma once
#include "GameObject.h"

class Platform : public GameObject
{
private:
	b2Body* PlatformBody;
	Rect PlatformRect;
	Sprite PlatformSprite;

public:
	Platform() {};
	Platform(b2World*, Renderer&, Rect);
	~Platform() {};

	void Render(Renderer& r);
	void Update(unsigned int deltaTime) {};

	// Set Variables
	void SetType(std::string t) { type = t; };

	// Get Variables
	b2Body* GetBody() { return PlatformBody; };
	std::string GetType() { return type; };
};