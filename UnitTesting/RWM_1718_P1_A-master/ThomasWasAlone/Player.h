#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include "EventListener.h"
#include "LTimer.h"

class Player
{
private:
	Rect rect;
	Colour col;

	double velocity;
	float velocityY;
	double maxVelocity;
	double acceleration;
	double counterF;
	Point2D position;
	float gravity;
	Rect nextRectangleX;
	Rect nextRectangleY;
	Point2D pNext;
	bool isFalling;
	SDL_Rect playerCollider;

	LTimer timer;
	double time;

public:
	Player();
	Player(Rect);
	~Player();
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void CheckCollision(GameObject* boxes);
	Rect GetRect()
	{
		return rect;
	}
	void SetPos(Point2D pos)
	{
		rect.pos = pos;
	}
	Colour GetColour()
	{
		return col;
	}
	void SetColour(Colour colour)
	{
		col = colour;
	}
	Point2D GetPos()
	{
		return rect.pos;
	}
	bool right;
	bool left;
	bool rightReleased;
	bool leftReleased;
	bool onBottom;
	bool jump;
	bool jumpReleased;

	double jumpAcceleration;

	void Jumping(unsigned int deltaTime);

	void SpacePressed();
};
