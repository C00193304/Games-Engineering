#pragma once
#include "Renderer.h"

#define WIDTH  800.0f
#define HEIGHT 600.0f

class Scene
{
public:
	bool quit;

	virtual ~Scene() {};

	virtual void Update(unsigned int) = 0;
	virtual void Draw(Renderer& renderer) = 0;
	virtual void Event() = 0;
	virtual bool GetQuit() = 0;

protected:
	Scene() {};
	
};