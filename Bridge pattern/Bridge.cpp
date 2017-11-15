#include <iostream>
#include "DrawImplh.h"
using namespace std;
int main()
{	
	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	cin.get();
	system("PAUSE");
}