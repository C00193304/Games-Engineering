#ifndef LEVEL2_H
#define LEVEL2_H

#include "SceneManager.h"
#include "Scene.h"
#include "GameData.h"
#include "World.h"
#include "Cannon.h"
#include "Mixer.h"
#include "Sounds.h"
#include "Basic2DObjects.h"
#include "Cannonball.h"
#include "Windmill.h"
#include "Wall.h"
#include "Goal.h"
#include "stdafx.h"
#include "Wall.h"
#include "Particles.h"
#include "Platform.h"
#include "UIText.h"

class Level2 : public Scene, public EventListener
{
public:
	Level2();
	~Level2();

	void Update(unsigned int);
	void Draw(Renderer& renderer);
	void Event();
	bool GetQuit();
	void Init(Renderer& r);
	void onEvent(EventListener::Event evt);
	void AddCannonBall(Renderer&);
	bool GetCompleted();

private:
	vector<UIText*> UIList;
	InputManager input;
	World BoxWorld;
	Cannon* Player;
	Windmill* mill;
	vector<GameObject*> Objects;
	bool addBall;
	bool reset;
	int ballcounter = 0;
	Particles* particles;
};

#endif // !LEVEL1_H

