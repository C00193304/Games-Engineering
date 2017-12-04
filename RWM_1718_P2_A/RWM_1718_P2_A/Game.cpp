#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Game.h"
#include "LTimer.h"

const int SCREEN_FPS = 300;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

Game::Game(): loader("GeneralGameData.json")
{
	pause = false;
	quit = false;
}


Game::~Game()
{
}


bool Game::init()
{
	Size2D winSize(800, 600);
	//creates our renderer, which looks after drawing and the window
	renderer.init(winSize, "Simple SDL App");

	SDL_Init(SDL_INIT_AUDIO);

	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth / aspectRatio);
	Point2D vpBottomLeft(-vpSize.w / 2, -vpSize.h / 2);

	Rect vpRect(vpBottomLeft, vpSize);
	renderer.setViewPort(vpRect);

	m_manager = SceneManager(renderer);

	std::cout << "Player X before json loading: " << GameData::m_playerX << std::endl;
	loader.getGameData(1);
	std::cout << "Player X after json loading: " << GameData::m_playerX << std::endl;
	m_manager.getScene()->Init(renderer);
	MusicBG = new Mixer("Assets/Audio/Music.ogg");
	return true;

}

void Game::destroy()
{
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

void Game::render()
{
	renderer.clear(Colour(0, 0, 0));// prepare for new frame
										  //render every object

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
		//capTimer.start();

		quit = m_manager.getScene()->GetQuit();
		m_manager.EventScene();

		if (!pause) //in pause mode don't bother updateing
		{
			update();
		}

		if (m_manager.getScene()->GetCompleted())
		{
			switch (m_manager.GetCurrentState())
			{
			case SceneManager::Scenes::start:
				loader.loadLevelData(1);
				SceneManager::ChangeStates(SceneManager::Scenes::level1);
				break;
			case SceneManager::Scenes::level1:
				loader.loadLevelData(2);
				SceneManager::ChangeStates(SceneManager::Scenes::level2);
				break;
			case SceneManager::Scenes::level2:
				loader.loadLevelData(3);
				SceneManager::ChangeStates(SceneManager::Scenes::level3);
				break;
			case SceneManager::Scenes::level3:
				SceneManager::ChangeStates(SceneManager::Scenes::end);
				break;
			case SceneManager::Scenes::end:
				SceneManager::ChangeStates(SceneManager::Scenes::start);
				break;
			default:
				break;
			}
			m_manager.getScene()->Init(renderer);
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
		quit = true;
	}
	if (evt == EventListener::Event::LEVEL1)
	{
		loader.getGameData(1);
		m_manager.ChangeStates(m_manager.level1);
		m_manager.getScene()->Init(renderer);
	}
	if (evt == EventListener::Event::LEVEL2)
	{
		loader.getGameData(2);
		m_manager.ChangeStates(m_manager.level2);
		m_manager.getScene()->Init(renderer);
	}
	if (evt == EventListener::Event::LEVEL3)
	{
		loader.getGameData(3);
		m_manager.ChangeStates(m_manager.level3);
		m_manager.getScene()->Init(renderer);
	}
	if (evt == EventListener::Event::LEVEL4)
	{
		loader.getGameData(4);
		m_manager.ChangeStates(m_manager.level4);
		m_manager.getScene()->Init(renderer);
	}
	if (evt == EventListener::Event::ENDSCENE)
	{
		loader.getGameData(1);
		m_manager.ChangeStates(m_manager.end);
		m_manager.getScene()->Init(renderer);
	}
	if (evt == EventListener::Event::STARSCENE)
	{
		loader.getGameData(1);
		m_manager.ChangeStates(m_manager.start);
		m_manager.getScene()->Init(renderer);
	}
}
