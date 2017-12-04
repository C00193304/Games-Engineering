#pragma once
#include "GameObject.h"

class Windmill : public GameObject
{
public:
	Windmill() {};
	Windmill(b2World*, Renderer&, Rect);
	~Windmill() {};
	void Update(unsigned int deltaTime);
	void Render(Renderer&);
	void SetType(string t) { type = t; };
	b2Body* GetBody() { return m_Mainbody; };
	string GetType() { return type; };
	void SetActive(bool);
	bool GetActive();
private:
	b2Body* m_Mainbody;
	b2Body* m_bladeBody;
	b2Vec2 m_velocity;
	Rect m_mainrect;
	Rect m_bladeRect;
	Sprite m_mainsprite;
	Sprite m_bladeSprite;
	b2RevoluteJoint* m_revoJoint;
	b2RevoluteJointDef* m_rjd;
	bool m_isActive;
};