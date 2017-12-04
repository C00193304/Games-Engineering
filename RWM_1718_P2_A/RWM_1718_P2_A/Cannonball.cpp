#include "Cannonball.h"

Cannonball::Cannonball(b2World * world, Renderer & r, Cannon* c)
{

	angle = c->GetAngle();
	power = c->GetPower();


	type = "CannonBall";
	
	CannonBallRect = Rect(c->GetRect().pos.x + c->GetRect().size.w/4 -5, c->GetRect().pos.y + c->GetRect().size.h /2 -1 , 10.0f, 10.0f);


	if (!CannonBallSprite.Init("Assets/Images/Ball.png", r, Rect(0, 0, 275, 277), CannonBallRect))
	{
		cout << "Failed to load image..." << endl;
	}

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(CannonBallRect.pos.x, CannonBallRect.pos.y);
	bodyDef.awake = true;
	CannonBallBody = world->CreateBody(&bodyDef);

	b2CircleShape shape;
	shape.m_p.Set(CannonBallRect.size.w / 2, CannonBallRect.size.h / 2);
	shape.m_radius = 5.0f;
	CannonBallBody->CreateFixture(&shape, 50);

	CannonBallBody->GetFixtureList()->SetRestitution(0.0f);
	CannonBallBody->GetFixtureList()->SetFriction(0.0f);

	Sounds sound = Sounds::Sounds("Assets/Audio/CannonBall.wav");
	sound.Play();

	fired = false;
};

void Cannonball::Render(Renderer& r)
{
	CannonBallSprite.Render(r);
}

void Cannonball::GetBodyPosition()
{
	CannonBallRect.pos.x = CannonBallBody->GetPosition().x;
	CannonBallRect.pos.y = CannonBallBody->GetPosition().y;

	CannonBallSprite.setPosition(CannonBallRect);
}

void Cannonball::Update(unsigned int DeltaTime)
{
	GetBodyPosition();

	if (!fired)
	{
		Shooting();
	}
}

void Cannonball::Shooting()
{

	if (velocityX == 0 && velocityY == 0)
	{
		float angleRad = angle * 3.14 / 180;


		float velY = cos(angleRad)*power;
		float velX = sin(angleRad)*power;

		velocity.x = velX*500;
		velocity.y = -velY*500;
	}

	b2Vec2 x = CannonBallBody->GetWorldCenter();
	CannonBallBody->ApplyLinearImpulse(velocity, x, true);

	fired = true;
}