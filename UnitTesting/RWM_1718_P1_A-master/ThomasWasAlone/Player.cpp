#include "stdafx.h"
#include "Player.h"
#include <iostream>

Player::Player()
{
	rect = Rect(500, 0, 20, 40);
	Point2D p = rect.pos;//current position
	velocity = 0.0;
	velocityY = 0.0f;
	maxVelocity = 5;
	acceleration = 0.5;
	counterF = (maxVelocity / acceleration);
	rightReleased = false;
	leftReleased = false;
	right = false;
	left = false;
	isFalling = false;
	gravity = 10.0f;
	nextRectangleX = rect;
	nextRectangleY = rect;
	jump = false;
	jumpReleased = false;
	jumpAcceleration = 3;
	onBottom = false;
}

Player::Player(Rect set)
{
	rect = set;
	Point2D p = rect.pos;//current position
	velocity = 0.0;
	velocityY = 0.0f;
	maxVelocity = 3;
	acceleration = 0.5;
	counterF = (maxVelocity / acceleration);
	rightReleased = false;
	leftReleased = false;
	right = false;
	left = false;
	isFalling = false;
	gravity = 10.0f;
	nextRectangleX = rect;
	nextRectangleY = rect;
	jump = false;
	jumpReleased = false;
	jumpAcceleration = 3;
	onBottom = false;
}

Player::~Player()
{
}


void Player::Render(Renderer& r)
{
	r.drawWorldRect(rect, col);
}

void Player::CheckCollision(GameObject* boxes)
{	//check if collision is happening between the two objects inside this will have all the collision code and its outputs on the x axis
	if (nextRectangleX.pos.x < boxes->getRect().pos.x + boxes->getRect().size.w &&
		nextRectangleX.pos.x + nextRectangleX.size.w > boxes->getRect().pos.x &&
		nextRectangleX.pos.y < boxes->getRect().pos.y + boxes->getRect().size.h &&
		nextRectangleX.pos.y + nextRectangleX.size.h > boxes->getRect().pos.y)
	{
		//this deals with the player hitting the left side of the wall

		if (nextRectangleX.pos.x < boxes->getRect().pos.x + boxes->getRect().size.w &&  nextRectangleX.pos.x > boxes->getRect().pos.x)
		{
			if (boxes->GetType() != "Gate")
			{
				nextRectangleX.pos.x = boxes->getRect().pos.x + boxes->getRect().size.w;
				velocity = 0.1;
				cout << "left" << endl;
			}

		}
		//this deals with the player hitting the right side of the wall
		else if (nextRectangleX.pos.x + nextRectangleX.size.w > boxes->getRect().pos.x &&
			nextRectangleX.pos.x + nextRectangleX.size.w < boxes->getRect().pos.x + boxes->getRect().size.w)
		{
			if (boxes->GetType() != "Gate")
			{
				nextRectangleX.pos.x = boxes->getRect().pos.x - nextRectangleX.size.w;
				velocity = 0;
				cout << "right" << endl;
			}
		}
	}
	//check collision for all the outputs with top and bottom 
	if (nextRectangleY.pos.x < boxes->getRect().pos.x + boxes->getRect().size.w &&
		nextRectangleY.pos.x + nextRectangleY.size.w > boxes->getRect().pos.x &&
		nextRectangleY.pos.y < boxes->getRect().pos.y + boxes->getRect().size.h &&
		nextRectangleY.pos.y + nextRectangleY.size.h > boxes->getRect().pos.y)
	{
		//bottom of the box collision 
		if (nextRectangleY.pos.y + nextRectangleY.size.h > boxes->getRect().pos.y &&
			nextRectangleY.pos.y + nextRectangleY.size.h < boxes->getRect().pos.y + boxes->getRect().size.h)
		{
			if (boxes->GetType() != "Gate")
			{
				nextRectangleY.pos.y = boxes->getRect().pos.y - nextRectangleY.size.h;
				velocityY = 0;
				onBottom = true;
				isFalling = false;
				//cout << "bottom" << endl;
			}
		}
		//collisions with the top of the box
		else if (nextRectangleY.pos.y < boxes->getRect().pos.y + boxes->getRect().size.h &&
			nextRectangleY.pos.y > boxes->getRect().pos.y)
		{
			if (boxes->GetType() != "Gate")
			{
				nextRectangleY.pos.y = boxes->getRect().pos.y + boxes->getRect().size.h;
				velocityY = 0;
				cout << "top" << endl;
			}
		}
	}
}
void Player::Update(unsigned int deltaTime)
{
	rect.pos.x = nextRectangleX.pos.x;
	rect.pos.y = nextRectangleY.pos.y;


	nextRectangleX = rect;
	nextRectangleY = rect;

	
	if (!isFalling)
	{
		if (right)
		{
			velocity += acceleration;
			if (velocity > maxVelocity)
			{
				velocity = maxVelocity;
			}
		}
		if (left)
		{
			velocity -= acceleration;
			if (velocity < -maxVelocity)
			{
				velocity = -maxVelocity;
			}
		}
		if (rightReleased)
		{
			if (velocity > 0.0)
			{
				velocity -= acceleration;
			}

		}
		if (leftReleased)
		{

			if (velocity > 0.0)
			{
				velocity = 0.0;
			}
			if (velocity < 0.0)
			{
				velocity += acceleration;
			}

		}
	}
	else if (isFalling)
	{
		if (right)
		{
			velocity += acceleration / 2;
			if (velocity > maxVelocity)
			{
				velocity = maxVelocity / 2;
			}
		}
		if (left)
		{
			velocity -= acceleration / 2;
			if (velocity < -maxVelocity)
			{
				velocity = -maxVelocity / 2;
			}
		}
		if (rightReleased)
		{
			if (velocity > 0.0)
			{
				velocity -= acceleration / 2;
			}

		}
		if (leftReleased)
		{

			if (velocity > 0.0)
			{
				velocity = 0.0;
			}
			if (velocity < 0.0)
			{
				velocity += acceleration / 2;
			}

		}
	}

	if (velocity == 0.0)
	{
		rightReleased = false;
		leftReleased = false;
	}

	if (velocity < 0.05 && velocity > -0.05)
	{
		velocity = 0;
	}

	if (!jump || (jump && !onBottom))
	{
		nextRectangleX.pos.x += velocity;
		velocityY += gravity * deltaTime / 1000;
		nextRectangleY.pos.y += velocityY;
	}

	if (jump)
	{
		Jumping(deltaTime);
	}
	if (!jump && jumpReleased)
	{
		jumpAcceleration = 3;
	}
	if (!jumpReleased && jump && !isFalling)
	{
		cout << timer.getTicks() << endl;
		cout << "injump" << endl;
		if ((timer.getTicks()) >= 200)
		{
    			velocityY -= jumpAcceleration /4 ;
			timer.stop();
			jumpReleased = false;
			isFalling = true;
		}
	}
	nextRectangleX.pos.x += velocity;
	nextRectangleY.pos.y += velocityY;
}

void Player::Jumping(unsigned int deltaTime)
{

	if (jump && onBottom)
	{

		velocityY -= gravity * deltaTime / 1000 + (jumpAcceleration);
		
		if (jumpAcceleration >= 0)
		{
			jumpAcceleration -= gravity *deltaTime / 1000;
		}
		if (jumpAcceleration <= 0)
		{
			jumpAcceleration = 3;
		}
		if (jumpReleased)
		{
			jumpAcceleration = 3;
		}
		onBottom = false;
	}
	if (jumpReleased)
	{
		isFalling = true;
		jump = false;
	}
}

void Player::SpacePressed()
{
	if (!jump)
	{
		jump = true;
		timer.start();
		time = timer.getTicks();
		cout << time << endl;
	}
	jump = true;
}



 