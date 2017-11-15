#pragma once
#include "Graphic.h"
#include "IGraphic.h"

class GraphicProxy : public IGraphic
{
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw();
private:
	Graphic* graphic;
	Graphic* getInstance(void);
};

GraphicProxy::GraphicProxy()
{
	this->graphic = 0;
}
GraphicProxy::~GraphicProxy()
{
	if (graphic)
		delete graphic;
}
Graphic* GraphicProxy::getInstance(void)
{
	if (!graphic)
		graphic = new Graphic();
	return graphic;
}
void GraphicProxy::Draw()
{
	getInstance()->Draw();
}

