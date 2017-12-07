#pragma once
#include "Scene.h"
class TestScene : public Scene
{
public:
	TestScene() {};
	~TestScene() {};

	virtual void Draw(Renderer& renderer) {};
	virtual void Update(unsigned int) {};
	virtual void Event() {};
	virtual bool GetQuit() 
	{ 
		return quit; 
	};
};