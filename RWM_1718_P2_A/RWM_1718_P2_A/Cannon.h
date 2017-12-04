#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Cannon : public GameObject
{
private:
	b2Body* CannonBody;
	Rect CannonRect;
	int angle;
	int power;
	float totalRotation;
	float desiredAngleVelocity;
	float impulse;
	float desiredAngle;

	Sprite CannonSprite;

public:
	Cannon() {};
	Cannon(b2World*);
	Cannon(Renderer&);
	~Cannon() {};
	void RotateLeft();
	void RotateRight();
	void IncreasePower();
	void DecreasePower();

	void Render(Renderer& r);
	void Update(unsigned int deltaTime);

	void GetBodyPosition();

	// Set Variables
	void SetType(std::string t) { type = t; };

	// Get Variables
	b2Body* GetBody() { return CannonBody; };
	std::string GetType() { return type; };
	int GetPower() { return power; };
	int GetAngle() { return angle; };
	Rect GetRect() { return CannonRect; };
};