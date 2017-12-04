#include "Windmill.h"


Windmill::Windmill(b2World *world, Renderer &r, Rect rect)
{

	type = "Windmill";

	b2BodyDef m_mainBodyDef, m_bladeBodyDef;
	m_mainBodyDef.type = b2_staticBody;
	m_bladeBodyDef.type = b2_dynamicBody;
	m_mainBodyDef.position.Set(rect.pos.x, rect.pos.y);
	m_bladeBodyDef.position.Set(rect.pos.x/2, rect.pos.y);
	m_Mainbody = world->CreateBody(&m_mainBodyDef);
	m_bladeBody = world->CreateBody(&m_bladeBodyDef);

	m_mainrect = rect;
	m_bladeRect = rect;
	m_bladeRect.pos.x -= 20;
	m_bladeRect.size.w = rect.pos.x /2 + m_mainrect.size.w;
	m_bladeRect.size.h = 5;

	b2PolygonShape m_mainShape;
	b2PolygonShape m_bladeShape;

	m_mainShape.SetAsBox(m_mainrect.size.w / 2, m_mainrect.size.h / 2, b2Vec2(m_mainrect.size.w / 2, m_mainrect.size.h / 2), 0);
	m_bladeShape.SetAsBox(m_bladeRect.size.w / 2, m_bladeRect.size.h / 2, b2Vec2(m_bladeRect.size.w / 2, m_bladeRect.size.h / 2), 0);
	m_Mainbody->CreateFixture(&m_mainShape, 100);
	m_bladeBody->CreateFixture(&m_bladeShape, 0.1);

	m_Mainbody->GetFixtureList()->SetFriction(0.2f);
	m_bladeBody->GetFixtureList()->SetFriction(0.2f);
	m_Mainbody->GetFixtureList()->SetRestitution(0.2f);
	m_bladeBody->GetFixtureList()->SetRestitution(0.2f);
	m_mainsprite.Init("Assets/Images/Mill.png", r, Rect(0, 0, 274, 128), m_mainrect);
	m_bladeSprite.Init("Assets/Images/Blade.png", r, Rect(0, 0, 274, 128), m_bladeRect);


	m_rjd = new b2RevoluteJointDef();
	m_rjd->Initialize(m_Mainbody, m_bladeBody, b2Vec2(m_mainrect.pos.x + m_mainrect.size.w/2, m_mainrect.pos.y));
	
	m_rjd->motorSpeed = 3.14152 * 2;
	m_rjd->maxMotorTorque = 500;
	m_rjd->enableMotor = false;
	m_revoJoint = (b2RevoluteJoint*)world->CreateJoint(m_rjd);
}

void Windmill::Update(unsigned int dt)
{
	m_bladeRect.pos.x = m_bladeBody->GetPosition().x;
	m_bladeRect.pos.y = m_bladeBody->GetPosition().y;

	m_bladeSprite.setPosition(m_bladeRect);
}

void Windmill::Render(Renderer & r)
{
	m_mainsprite.Render(r);
	m_bladeSprite.Render(r, (m_bladeBody->GetAngle() * (180.0/3.14159)));
}

void Windmill::SetActive(bool active)
{
	m_isActive = active;
}

bool Windmill::GetActive()
{
	return m_isActive;
}
