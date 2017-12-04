#include "Goal.h"

Goal::Goal(b2World* world, Renderer& r, Rect rect)
{
	type = "Goal";

	// Define Goals's position, width and height
	GoalRect = rect;
	AnimationRect = Rect(0.0f, 0.0f, 52.0f, 16.0f);

	CycleRight = true;

	timer = 0.0f;

	// Create Body definition
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(GoalRect.pos.x, GoalRect.pos.y);
	GoalBody = world->CreateBody(&bodyDef);

	// Creat Shape polygon
	b2PolygonShape Shape;
	Shape.SetAsBox(GoalRect.size.w / 2, (GoalRect.size.h / 2), b2Vec2(GoalRect.size.w / 2, GoalRect.size.h / 2), 0);
	GoalBody->CreateFixture(&Shape, 10.0f);

	GoalBody->GetFixtureList()->SetFriction(0.2f);
	GoalBody->GetFixtureList()->SetRestitution(0.2f);

	GoalSprite.Init("Assets/Images/Portal.png", r, AnimationRect, GoalRect);
}

void Goal::Update(unsigned int dt)
{
	timer += dt / 60.0f;

	if (timer > 1.0f)
	{
		if (CycleRight)
		{
			AnimationRect.pos.x += AnimationRect.size.w;

			if (AnimationRect.pos.x >= AnimationRect.size.w * 6)
			{
				CycleRight = false;
			}
		}
		else
		{
			AnimationRect.pos.x -= AnimationRect.size.w;
			if (AnimationRect.pos.x <= 0)
			{
				CycleRight = true;
			}
		}

		timer = 0.0f;
	}

	GoalSprite.setSheetPosition(AnimationRect);

}

void Goal::Render(Renderer& r)
{
	GoalSprite.Render(r);
}