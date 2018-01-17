#include "Player.h"
#include <assert.h>
Player::Player()
{
	position = 0;
	velocity = 0;
	speedBoost = false;
}

Player::~Player()
{

}

void Player::Update()
{
	VelocityInc();
	UpdatePosition();
	if (position >= 75)
	{
		speedBoost = true;
		SpeedBoost();
	}

	assert(position <= 150);
}

void Player::VelocityInc()
{

	if (velocity < 0.9)
	{
		velocity += 0.01;
	}
	std::cout << "velocity is: " << velocity << std::endl;
}

void Player::SpeedBoost()
{
	if (speedBoost == true)
	{
		if (position <= 100)
		{
			if (velocity >= 1)
			{
				velocity = 1;
			}
			velocity += 0.1;
		}
		std::cout << "speed boost hit" << std::endl;
	}
}

void Player::UpdatePosition()
{
	position += velocity;
	std::cout << "position is: " << position << std::endl;
}
