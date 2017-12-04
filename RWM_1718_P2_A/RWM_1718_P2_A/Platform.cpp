#include "Platform.h"


Platform::Platform(b2World* world, Renderer& r, Rect rect)
{
	type = "Ground";

	// Define Cannon's position, width and height
	PlatformRect = rect;

	// Create Body definition
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(PlatformRect.pos.x, PlatformRect.pos.y);
	PlatformBody = world->CreateBody(&bodyDef);

	// Creat Shape polygon
	b2PolygonShape Shape;
	Shape.SetAsBox(PlatformRect.size.w / 2, (PlatformRect.size.h / 2), b2Vec2(PlatformRect.size.w / 2, PlatformRect.size.h / 2), 0);
	PlatformBody->CreateFixture(&Shape, 10.0f);

	PlatformBody->GetFixtureList()->SetFriction(0.2f);
	PlatformBody->GetFixtureList()->SetRestitution(0.2f);

	PlatformSprite.Init("Assets/Images/Platform.png", r, Rect(0, 0, 512, 512), PlatformRect);
}

void Platform::Render(Renderer& r)
{
	PlatformSprite.Render(r);
}