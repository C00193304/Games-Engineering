#pragma once

#include <vector>
#include "Scene.h"
#include "EventListener.h"
#include "Button.h"

class StartScene : public Scene, public EventListener
{
public:
	StartScene();
	~StartScene();

	void Update(unsigned int);
	void Draw(Renderer& renderer);
	void Event();
	bool GetQuit();
	void Init(Renderer& r);
	void onEvent(EventListener::Event evt);
	void Init();
	bool GetCompleted();

private:
	InputManager input;
	vector<Button*>  buttonList;
	int currentbutton;
	int maxButtons;
	Rect Size;
	Sprite BackgroundSprite;
};

