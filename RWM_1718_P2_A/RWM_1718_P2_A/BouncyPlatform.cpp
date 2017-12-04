#include "BouncyPlatform.h"


BouncyPlatform::BouncyPlatform(b2World* world, Renderer& r, Rect rect)
{
	type = "Ground";

	// Define Cannon's position, width and height
	BouncyPlatformRect = rect;

	// Create Body definition
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(BouncyPlatformRect.pos.x, BouncyPlatformRect.pos.y);
	BouncyPlatformBody = world->CreateBody(&bodyDef);

	// Creat Shape polygon
	b2PolygonShape Shape;
	Shape.SetAsBox(BouncyPlatformRect.size.w / 2, (BouncyPlatformRect.size.h / 2), b2Vec2(BouncyPlatformRect.size.w / 2, BouncyPlatformRect.size.h / 2), 0);
	BouncyPlatformBody->CreateFixture(&Shape, 10.0f);

	BouncyPlatformBody->GetFixtureList()->SetFriction(0.2f);
	BouncyPlatformBody->GetFixtureList()->SetRestitution(0.8f);

	BouncyPlatformSprite.Init("Assets/Images/Bouncy.png", r, Rect(0, 0, 512, 512), BouncyPlatformRect);
}

void BouncyPlatform::Render(Renderer& r)
{
	BouncyPlatformSprite.Render(r);
}