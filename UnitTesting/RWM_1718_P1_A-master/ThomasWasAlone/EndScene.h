#ifndef ENDSCENE_H
#define ENDSCENE_H


#include "Scene.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "SDL_ttf.h"
#include "InputManager.h"

class EndScene : public Scene, public EventListener
{
private:
	Sprite Image;
	TTF_Font* Font;
	SDL_Surface* TextSurface_01;
	SDL_Texture* Text_01;
	SDL_Rect Position_01;

	SDL_Surface* TextSurface_02;
	SDL_Texture* Text_02;
	SDL_Rect Position_02; 

	InputManager inputManager;

	bool KeyReleased;
	bool KeyPressed;

public:
	EndScene(Renderer& renderer);

	~EndScene() {};
	virtual void Draw(Renderer & renderer);
	virtual void Update(unsigned int DeltaTime) {};
	virtual void Event();
	virtual bool GetQuit() { return quit; };
	void onEvent(EventListener::Event evt);
};

#endif // !ENDSCENE_H