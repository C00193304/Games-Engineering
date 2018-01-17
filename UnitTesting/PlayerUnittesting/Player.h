#pragma once
#include <iostream>

class Player
{

private:
	double velocity;
	double position;
	bool speedBoost;


public:
	Player();
	~Player();
	void Update();
	void VelocityInc();
	void SpeedBoost();
	void UpdatePosition();


};