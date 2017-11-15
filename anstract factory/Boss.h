#pragma once
#include "Character.h"
using namespace std;

class Boss : public Character
{
public:
	void draw()
	{
		cout << "Draw Boss" << endl;
	}
};
