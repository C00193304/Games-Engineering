#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "Cannon.h"
#include "Sounds.h"

class Cannonball : public GameObject
{
private:
	b2Body* CannonBallBody;
	Rect CannonBallRect;
	Sprite CannonBallSprite;
	b2Vec2 velocity;
	
	bool fired;
	int velocityY;
	int velocityX;
	int power;
	int angle;

public:
	Cannonball() {};
	Cannonball(b2World*, Renderer & r, Cannon* c);
	~Cannonball() {};

	void Render(Renderer& r);
	void Update(unsigned int deltaTime);

	void GetBodyPosition();

	//set Variables
	void SetType(string t) { type = t; };

	void Collision() {};

	void Shooting();

	//Get Variables
	b2Body* GetBody() { return CannonBallBody; };
	string GetType() { return type; };

	
};