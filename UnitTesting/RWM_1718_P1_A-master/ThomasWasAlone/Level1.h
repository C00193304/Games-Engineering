#pragma once


#include "Scene.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Box.h"
#include "Player.h"
#include "Gate.h"
#include "InputManager.h"
#include <vector>
#include <iostream>

using namespace std;

class Level1 : public Scene, public EventListener
{
private:
	vector<GameObject*> GameObjects;
	Player* player = nullptr;
	InputManager inputManager;
	bool CheckCenter(Rect player, Rect gate);

public:
	Level1();
	void init();
	void Update(unsigned int);
	void Event();
	void onEvent(EventListener::Event evt);
	bool GetQuit();
	void Draw(Renderer& renderer);
};
