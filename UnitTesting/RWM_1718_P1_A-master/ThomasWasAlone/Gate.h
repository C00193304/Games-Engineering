#pragma once
#include "GameObject.h"
#include "BasicTypes.h"

class Gate : public GameObject
{
public:
	Gate();
	Gate(Rect r);
	~Gate();

	void Render(Renderer & r);
	void Update(unsigned int deltaTime);

	void SetType(std::string t)
	{
		type = t;
	};
	std::string GetType()
	{
		return type;
	};
	Rect getRect()
	{
		return m_rect;
	};

private:

	Rect m_rect;
	Colour m_col;
};