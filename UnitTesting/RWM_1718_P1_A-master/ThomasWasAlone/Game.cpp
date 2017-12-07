#include "stdafx.h"

#include <iostream>
using namespace std;



#include "LTimer.h"
#include "Box.h"
#include "Sprite.h"
#include "Game.h"
#include "Player.h"

const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{
	pause = false;
	quit = false;
}


Game::~Game()
{
}


bool Game::init() 
{	
	Size2D winSize(800,600);
	//creates our renderer, which looks after drawing and the window
	renderer.init(winSize,"Simple SDL App");

	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth /aspectRatio);
	Point2D vpBottomLeft( -vpSize.w / 2, - vpSize.h / 2);

	Rect vpRect(vpBottomLeft,vpSize);
	renderer.setViewPort(vpRect);
	//create Game objects


	//add game objects to the world


	lastTime = LTimer::gameTime();

	m_manager = SceneManager(renderer);

	return true;

}


void Game::destroy()
{
	//empty out the game object vector before quitting
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++)
	{
		delete *i;
	}

	gameObjects.clear();
	renderer.destroy();
}

//** calls update on all game entities*/
void Game::update()
{

	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;//time since last update
	//call update for the game objects

	m_manager.UpdateScene(deltaTime);
	//save the curent time for next frame
	lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{
	renderer.clear(Colour(153,176,255));// prepare for new frame
								  //render every object
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(), e = gameObjects.end(); i != e; i++) 
	{
		(*i)->Render(renderer);
	}

	m_manager.DrawScene(renderer);


	renderer.present();// display the new frame (swap buffers)
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate

	int frameNum = 0;
	while (!quit) 
	{ //game loop
		capTimer.start();

		quit = m_manager.getScene()->GetQuit();
		m_manager.EventScene();

		if (!pause) //in pause mode don't bother updateing
		{
			update();
		}
		render();

		int frameTicks = capTimer.getTicks();//time since start of frame
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time before going to next frame
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

void Game::onEvent(EventListener::Event evt) 
{
	switch (evt) 
	{
	case EventListener::Event::QUIT:
		quit = true;
		break;
	case EventListener::Event::QUITEND:
		if (m_manager.GetCurrentState() == m_manager.end)
		{
			quit = true;
		}
		break;
	case EventListener::Event::AnyKey:
		if (m_manager.GetCurrentState() == m_manager.start)
		{
			m_manager.ChangeStates(m_manager.level1);
		}
		else if (m_manager.GetCurrentState() == m_manager.end)
		{
			m_manager.ChangeStates(m_manager.start);
		}
		break;
	}
	
	if (evt == EventListener::Event::QUIT)
	{
		quit=true;
	}
	if (evt == EventListener::Event::LEVEL1)
	{
		m_manager.ChangeStates(m_manager.level1);
	}
	if (evt == EventListener::Event::LEVEL2)
	{
		m_manager.ChangeStates(m_manager.level2);
	}
	if (evt == EventListener::Event::LEVEL3)
	{
		m_manager.ChangeStates(m_manager.level3);
	}
	if (evt == EventListener::Event::LEVEL4)
	{
		m_manager.ChangeStates(m_manager.level4);
	}
	if (evt == EventListener::Event::ENDSCENE)
	{
		m_manager.ChangeStates(m_manager.end);
	}
	if (evt == EventListener::Event::STARSCENE)
	{
		m_manager.ChangeStates(m_manager.start);
	}
}
