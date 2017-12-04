#pragma once
#include "Renderer.h"
#include "InputManager.h"
#include "stdafx.h"
#include "GameObject.h"

#define WIDTH  800.0f
#define HEIGHT 600.0f

class Scene
{
public:
	virtual ~Scene() {};
	virtual void Init(Renderer& r) = 0;
	virtual void Update(unsigned int) = 0;
	virtual void Draw(Renderer& renderer) = 0;
	virtual void Event() = 0;
	virtual bool GetQuit() = 0;
	virtual bool GetCompleted() = 0;

protected:
	Scene() {};
	bool quit;
	bool complete;
	
};