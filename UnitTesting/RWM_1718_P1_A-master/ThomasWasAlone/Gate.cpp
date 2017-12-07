#include "Gate.h"

Gate::Gate()
{
	type = "Gate";
}

Gate::Gate(Rect r)
	: m_rect(r)
{
	type = "Gate";
}

Gate::~Gate()
{
}

//Draw object
void Gate::Render(Renderer & r)
{
	r.drawWorldRect(m_rect, m_col);
}

//Update for object(not usually needed)
void Gate::Update(unsigned int deltaTime)
{
}


