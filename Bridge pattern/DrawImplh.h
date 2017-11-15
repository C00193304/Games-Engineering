#pragma once
#include <iostream>
#include "DrawAPI.h"
#include "Player.h"

using namespace std;

class DrawImpl : public DrawAPI
{
public:
	void Draw() { cout << "Draw Impl" << endl; }
};