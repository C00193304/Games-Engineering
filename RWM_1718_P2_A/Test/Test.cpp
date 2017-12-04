#include <assert.h>
#include <Cannonball.h>
#include <Cannon.h>
#include <Box2D\Box2D.h>




int main()
{
	Cannon cannon;
	cannon.IncreasePower();
	
	assert(cannon.GetPower() != NULL);
	std::cout << cannon.GetPower() << std::endl;
}