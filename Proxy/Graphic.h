#pragma once
#include <iostream>
#include "IGraphic.h"

using namespace std;
class Graphic : public IGraphic
{
public:
	Graphic();
	~Graphic();
	void Draw();
};

Graphic::Graphic() {

}

Graphic::~Graphic()
{

}

void Graphic::Draw()
{
	cout << "Drawing Grpahic Object" << endl;
}