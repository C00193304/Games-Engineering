#pragma once
#include <iostream>

class Character {
public:
	Character() {}
	virtual ~Character() {}
	virtual void draw() = 0;
};