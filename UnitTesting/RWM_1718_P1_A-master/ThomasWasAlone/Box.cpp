#include "Box.h"


Box::Box()
{
	boxHeight = rect.size.h;
	boxWidth = rect.size.w;
}

Box::Box(Rect r):rect(r)
{
	type = "Box";
}

Box::~Box()
{
}

void Box::Render(Renderer& r) 
{
	r.drawWorldRect(rect,col);
}

void Box::Update(unsigned int deltaTime)
{
}
