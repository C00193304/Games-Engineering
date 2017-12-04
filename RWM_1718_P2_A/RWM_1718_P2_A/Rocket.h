#pragma once
#include "GameObject.h"

class Rocket : public GameObject
{
public: 
	Rocket() {};
	~Rocket() {};
	Rocket(b2World*,Renderer&,b2Vec2);
	void Render(Renderer& r);
	void Update(unsigned int deltaTime);
	b2Body* GetBody();
	void SetType(std::string t);
	std::string GetType();
	void SetActive(bool active);

private:
	b2Body* m_body;
	Rect m_Rect;
	Sprite m_sprite;
	b2Vec2 m_velocity;
	float m_acceleration;
	bool m_Active;

};