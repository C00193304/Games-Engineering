#include "Basic2DObjects.h"

Ground::Ground(b2World* world, Renderer& r, Rect rect)
{
	type = "Ground";

	// Define Cannon's position, width and height
	GroundRect = rect;

	// Create Body definition
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(GroundRect.pos.x, GroundRect.pos.y);
	GroundBody = world->CreateBody(&bodyDef);

	// Creat Shape polygon
	b2PolygonShape Shape;
	Shape.SetAsBox(GroundRect.size.w / 2, (GroundRect.size.h / 2) - 5, b2Vec2(GroundRect.size.w / 2, GroundRect.size.h / 2), 0);
	GroundBody->CreateFixture(&Shape, 10.0f);

	GroundBody->GetFixtureList()->SetFriction(0.2f);
	GroundBody->GetFixtureList()->SetRestitution(0.2f);

	GroundSprite.Init("Assets/Images/Ground.png", r, Rect(0, 0, 274, 128), GroundRect);
}

void Ground::Render(Renderer& r)
{
	GroundSprite.Render(r);
}
