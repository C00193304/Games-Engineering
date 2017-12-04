#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Goal : public GameObject
{
private:
	b2Body* GoalBody;
	Rect GoalRect;
	Rect AnimationRect;
	Sprite GoalSprite;

	float timer;
	bool CycleRight;

public:
	Goal() {};
	Goal(b2World*, Renderer&, Rect);
	~Goal() {};

	void Render(Renderer& r);
	void Update(unsigned int deltaTime);

	// Set Variables
	void SetType(std::string t) { type = t; };

	// Get Variables
	b2Body* GetBody() { return GoalBody; };
	std::string GetType() { return type; };
};
