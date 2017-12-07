#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Box.h"
#include "Player.h"
#include "InputManager.h"
#include <vector>
#include <iostream>

using namespace std;

class Level6 : public Scene, public EventListener
{
private:
	vector<GameObject*> GameObjects;
	Player* player = nullptr;
	InputManager inputManager;

public:
	Level6();

	void init();
	void Update(unsigned int);
	void Event();
	bool CheckCenter(Rect player, Rect gate);
	void onEvent(EventListener::Event evt);
	bool GetQuit();
	void Draw(Renderer& renderer);
};
