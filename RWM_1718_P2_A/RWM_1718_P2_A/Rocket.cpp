#include "Rocket.h"

Rocket::Rocket(b2World* world, Renderer &renderer, b2Vec2 position)
{
	type = "Rocket";

	m_Rect = Rect(position.x, position.y, 24,32);

	if (!m_sprite.Init("Assets/Images/Rocket.png", renderer, Rect(0, 0, 275, 277), m_Rect))
	{
		cout << "Unable to load rocket sprite" << endl;
	}

	b2BodyDef m_bodyDef;
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(m_Rect.pos.x, m_Rect.pos.y);
	m_bodyDef.awake = true;
	m_body = world->CreateBody(&m_bodyDef);

	b2PolygonShape m_shape;
	m_shape.SetAsBox(m_Rect.size.w / 2, m_Rect.size.h / 2, b2Vec2(m_Rect.size.w / 2, m_Rect.size.h / 2), 0);
	m_body->CreateFixture(&m_shape, 0.5f);

	m_body->GetFixtureList()->SetFriction(0.0f);
	m_body->GetFixtureList()->SetRestitution(0.0f);
	m_acceleration = 2;
}

void Rocket::Render(Renderer & renderer)
{
	m_sprite.Render(renderer);
}

void Rocket::Update(unsigned int DeltaTime)
{
	if (m_body->GetMass() <= 1)
	{
		m_Active = false;
	}
	if (m_Active)
	{
		cout << "Mass of rocket: " << m_body->GetMass() << endl;
		m_body->GetFixtureList()->SetDensity(m_body->GetFixtureList()->GetDensity() / 1.02);
		m_body->ResetMassData();
		b2Vec2 x = m_body->GetWorldCenter();
		m_body->ApplyLinearImpulse(b2Vec2(0, -m_acceleration), x, true);

	}
	m_Rect.pos.x = m_body->GetPosition().x;
	m_Rect.pos.y = m_body->GetPosition().y;
	m_sprite.setPosition(m_Rect);
	
}

b2Body* Rocket::GetBody()
{
	return m_body;
}

void Rocket::SetType(string t)
{
	type = t;
}
string Rocket::GetType()
{
	return type;
}

void Rocket::SetActive(bool active)
{
	m_Active = true;
}