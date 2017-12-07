#pragma once
#include "stdafx.h"
#include "Renderer.h"



/*Base class for all in game objects*/
class GameObject
{

public:
	GameObject() {};
	virtual ~GameObject() {};


	virtual void Render(Renderer& r)=0;
	virtual void Update(unsigned int deltaTime)=0;
	virtual Rect getRect() = 0;


	virtual void SetType(std::string t)=0;
	virtual std::string GetType()=0;


protected:
	std::string type;
};

