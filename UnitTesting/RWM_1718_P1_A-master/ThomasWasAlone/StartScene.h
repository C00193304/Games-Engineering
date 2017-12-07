#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "SDL_ttf.h"
#include "SceneManager.h"
#include "InputManager.h"

class StartScene : public Scene, public EventListener
{
private:
	Sprite Image;
	TTF_Font* Font;
	SDL_Surface* TextSurface;
	SDL_Texture* Text;
	SDL_Rect Position;

	InputManager inputManager;
	
	bool KeyReleased;
	bool KeyPressed;

public:
	StartScene(Renderer& renderer);

	~StartScene() {};
	void init();
	virtual void Draw(Renderer & renderer);
	void onEvent(EventListener::Event evt);
	virtual void Update(unsigned int DeltaTime);
	virtual void Event();
	virtual bool GetQuit() 
	{ 
		return quit; 
	};
};