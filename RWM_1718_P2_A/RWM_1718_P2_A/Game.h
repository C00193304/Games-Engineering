#pragma once

#include "Renderer.h"
#include "EventListener.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "LevelLoader.h"
#include "Mixer.h"

class Game : public EventListener
{
	LevelLoader loader;
	InputManager inputManager;
	Renderer renderer;
	SceneManager m_manager;
	Mixer* MusicBG;

	unsigned int lastTime;//time of last update;
	bool pause;
	bool quit;
public:
	Game();
	~Game();
	bool init();
	void destroy();

	void update();
	void render();
	void loop();

	void onEvent(EventListener::Event);
};