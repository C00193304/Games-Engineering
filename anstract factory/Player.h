#pragma once
#include "Character.h"
using namespace std;

class Player : public Character
{
public:
	void draw() 
	{
		cout << "Draw Player" << endl;
	}
};