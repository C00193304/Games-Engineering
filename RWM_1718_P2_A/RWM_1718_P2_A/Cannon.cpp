#include "Cannon.h"

Cannon::Cannon(b2World * world)
{
	type = "Cannon";

	// Define Cannon's position, width and height
	CannonRect = Rect(50.0f, 50.0f, 50.0f, 15.0f);

	// Create Body definition
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(CannonRect.pos.x, CannonRect.pos.y);
	CannonBody = world->CreateBody(&bodyDef);

	// Creat Shape polygon
	b2PolygonShape Shape;
	Shape.SetAsBox(25.0f, 7.5f);
	CannonBody->CreateFixture(&Shape, 0.0f);
	angle = CannonBody->GetAngle();
}

Cannon::Cannon(Renderer & renderer)
{
	type = "Cannon";

	// Define Cannon's position, width and height
	CannonRect = Rect(50.0f, 535.0f, 75.0f, 20.0f);

	CannonSprite.Init("Assets/Images/Cannon.png", renderer, Rect(0,0,274,128), CannonRect);
	CannonSprite.setOrigin(Point2D(CannonRect.size.w / 4, CannonRect.size.h / 2));

	power = 300;
}

void Cannon::Render(Renderer& r)
{
	CannonSprite.Render(r, angle + 270);
}

void Cannon::Update(unsigned int DeltaTime)
{
	GetBodyPosition();
}

void Cannon::GetBodyPosition()
{
	CannonSprite.setPosition(CannonRect.pos);
}

void Cannon::RotateLeft()
{
	if (angle <= 0)
	{
		angle = 1;
	}
	else
	{
		angle -= 1;
	}
	
}

void Cannon::RotateRight()
{
	if (angle >= 90)
	{
		angle = 89;
	}
	else
	{
		angle += 1;
	}
}

void Cannon::IncreasePower()
{
	if (power >= 800)
	{
		power = 800;
	}
	else
	{
		power += 10;
	}
}

void Cannon::DecreasePower()
{
	if (power <= 300)
	{
		power = 300;
	}
	else
	{
		power -= 10;
	}
}