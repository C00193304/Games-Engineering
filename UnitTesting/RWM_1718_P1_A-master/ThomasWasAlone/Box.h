#ifndef BOX_H
#define BOX_H

#include "GameObject.h"
#include "BasicTypes.h"

/**define a box that spins aronf the centre*/
class Box : public GameObject
{
private:
	Rect rect;
	Colour col;
	float boxWidth;
	float boxHeight;

public:
	Box(Rect r);
	Box();
	~Box();

	void Render(Renderer & r);
	void Update(unsigned int deltaTime);

	Rect GetRect()
	{
		return rect;
	};
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
		return rect;
	};
	void SetPos(Point2D pos)
	{
		rect.pos = pos;
	}
	Colour GetColour()
	{
		return col;
	}
	void SetColour(Colour colour)
	{
		col = colour;
	}
};

#endif // !BOX_H