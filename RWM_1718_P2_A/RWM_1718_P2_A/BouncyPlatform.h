#pragma once
#include "GameObject.h"

class BouncyPlatform : public GameObject
{
private:
	b2Body* BouncyPlatformBody;
	Rect BouncyPlatformRect;
	Sprite BouncyPlatformSprite;

public:
	BouncyPlatform() {};
	BouncyPlatform(b2World*, Renderer&, Rect);
	~BouncyPlatform() {};

	void Render(Renderer& r);
	void Update(unsigned int deltaTime) {};

	// Set Variables
	void SetType(std::string t) { type = t; };

	// Get Variables
	b2Body* GetBody() { return BouncyPlatformBody; };
	std::string GetType() { return type; };
};