#include "Wall.h"


Wall::Wall(b2World* world, Renderer& r, Rect rect)
{
	type = "Wall";

	// Define Cannon's position, width and height
	WallRect = rect;

	// Create Body definition
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(WallRect.pos.x, WallRect.pos.y);
	WallBody = world->CreateBody(&bodyDef);

	// Creat Shape polygon
	b2PolygonShape Shape;
	Shape.SetAsBox(WallRect.size.w / 2, (WallRect.size.h / 2), b2Vec2(WallRect.size.w / 2, WallRect.size.h / 2), 0);
	WallBody->CreateFixture(&Shape, 10.0f);

	WallBody->GetFixtureList()->SetFriction(0.2f);
	WallBody->GetFixtureList()->SetRestitution(0.1f);

	WallSprite.Init("Assets/Images/Wall.png", r, Rect(0, 0, 512, 512), WallRect);
}

void Wall::Render(Renderer& r)
{
	WallSprite.Render(r);
}