#pragma once
#include <iostream>
#include "Character.h"
using namespace std;

class Factory 
{
public: 
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;
};
