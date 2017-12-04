<<<<<<< HEAD
#pragma once
#include "Scene.h"
#include "World.h"
#include "Cannon.h"
#include "Mixer.h"
#include "Sounds.h"
#include "Basic2DObjects.h"
#include "Cannonball.h"
#include "Wall.h"
#include "Particles.h"

class TestScene : public Scene, public EventListener
{
private:
	InputManager input;
	World BoxWorld;
	Cannon* Player;
	Particles* particles;
	vector<GameObject*> Objects;
	bool addBall;
	int ballcounter = 0;
public:
	TestScene() 
	{
		quit = false;

		Player = new Cannon(BoxWorld.getWorld());

		input.AddListener(EventListener::Event::QUIT, this);
		input.AddListener(EventListener::Event::RIGHT, this);
		input.AddListener(EventListener::Event::LEFT, this);
		input.AddListener(EventListener::Event::POWERUP, this);
		input.AddListener(EventListener::Event::POWERDOWN, this);
		input.AddListener(EventListener::Event::SPACE, this);
	};

	TestScene(Renderer& renderer)
	{
		srand(NULL);

		quit = false;

		Player = new Cannon(renderer);

		particles = new Particles(BoxWorld.getWorld(), Player);
		
		Objects.push_back(new Ground(BoxWorld.getWorld(), renderer, Rect(0.0f, 550.0f, 125.0f, 50.0f)));
		Objects.push_back(new Ground(BoxWorld.getWorld(), renderer, Rect(150.0f, 300.0f, 125.0f, 50.0f)));
		Objects.push_back(new Wall(BoxWorld.getWorld(), renderer, Rect(250.0f, 400.0f, 50.0f, 50.0f)));
		addBall = false;

		input.AddListener(EventListener::Event::QUIT, this);
		input.AddListener(EventListener::Event::RIGHT, this);
		input.AddListener(EventListener::Event::LEFT, this);
		input.AddListener(EventListener::Event::POWERUP, this);
		input.AddListener(EventListener::Event::POWERDOWN, this);
		input.AddListener(EventListener::Event::SPACE, this);
	};

	~TestScene() {};

	virtual void Draw(Renderer& renderer)
	{
		Player->Render(renderer);

		particles->Render(renderer);

		if (addBall && ballcounter < 3)
		{
			AddCannonBall(renderer);
			ballcounter++;
		}

		for (int i = 0; i < Objects.size(); i++)
		{
			Objects.at(i)->Render(renderer);
		}
	}

	virtual void Update(unsigned int dt)
	{
		Player->Update(dt);

		particles->Update(dt);

		for (int i = 0; i < Objects.size(); i++)
		{
			Objects.at(i)->Update(dt);
		}

		BoxWorld.Update(Objects);
	};

	virtual void Event()
	{
		input.ProcessInput();
	}

	void onEvent(EventListener::Event evt)
	{
		switch (evt)
		{
		case EventListener::Event::QUIT:
			quit = true;
			break;
		case EventListener::Event::RIGHT:
			Player->RotateRight();
			break;
		case EventListener::Event::LEFT:
			Player->RotateLeft();
			break;
		case EventListener::Event::POWERUP:
			Player->IncreasePower();
			break;
		case EventListener::Event::POWERDOWN:
			Player->DecreasePower();
			break;
		case EventListener::Event::SPACE:
			particles->Init(BoxWorld.getWorld(), 500);
			addBall = true;
			break;
		}
	}

	void AddCannonBall(Renderer & r)
	{
		Objects.push_back(new Cannonball(BoxWorld.getWorld(), r, Player));
		addBall = false;
		
	}

	virtual bool GetQuit() 
	{ 
		return quit; 
	};
};
=======
//#pragma once
//#include "Scene.h"
//#include "GameData.h"
//#include "World.h"
//#include "Cannon.h"
//#include "Mixer.h"
//#include "Sounds.h"
//#include "Basic2DObjects.h"
//
//class TestScene : public Scene, public EventListener
//{
//private:
//	InputManager input;
//	World BoxWorld;
//	Cannon* Player;
//	vector<GameObject*> Objects;
//	bool addBall;
//	int ballcounter = 0;
//
//public:
//	TestScene() 
//	{
//		quit = false;
//
//		Player = new Cannon(BoxWorld.getWorld());
//
//		input.AddListener(EventListener::Event::QUIT, this);
//		input.AddListener(EventListener::Event::RIGHT, this);
//		input.AddListener(EventListener::Event::LEFT, this);
//		input.AddListener(EventListener::Event::POWERUP, this);
//		input.AddListener(EventListener::Event::POWERDOWN, this);
//		input.AddListener(EventListener::Event::SPACE, this);
//	};
//
//	void Init() {};
//
//	TestScene(Renderer& renderer)
//	{
//		quit = false;
//
//		Player = new Cannon(renderer);

//		Objects.push_back(new Ground(BoxWorld.getWorld(), renderer, Rect(0.0f, 550.0f, 125.0f, 50.0f)));
//		Objects.push_back(new Ground(BoxWorld.getWorld(), renderer, Rect(150.0f, 300.0f, 125.0f, 50.0f)));
//
//		addBall = false;
//
//		input.AddListener(EventListener::Event::QUIT, this);
//		input.AddListener(EventListener::Event::RIGHT, this);
//		input.AddListener(EventListener::Event::LEFT, this);
//		input.AddListener(EventListener::Event::POWERUP, this);
//		input.AddListener(EventListener::Event::POWERDOWN, this);
//		input.AddListener(EventListener::Event::SPACE, this);
//	};
//
//	~TestScene() {};
//
//	void Draw(Renderer& renderer)
//	{
//		Player->Render(renderer);
//		if (addBall && ballcounter < 3)
//		{
//			AddCannonBall(renderer);
//			ballcounter++;
//		}
//
//		for (int i = 0; i < Objects.size(); i++)
//		{
//			Objects.at(i)->Render(renderer);
//		}
//	};
//
//	void Update(unsigned int dt)
//	{
//		Player->Update(dt);
//
//		for (int i = 0; i < Objects.size(); i++)
//		{
//			Objects.at(i)->Update(dt);
//		}
//
//		BoxWorld.Update(Objects);
//	};
//
//	void Event()
//	{
//		input.ProcessInput();
//	};
//
//	void onEvent(EventListener::Event evt)
//	{
//		switch (evt)
//		{
//		case EventListener::Event::QUIT:
//			quit = true;
//			break;
//		case EventListener::Event::RIGHT:
//			Player->RotateRight();
//			break;
//		case EventListener::Event::LEFT:
//			Player->RotateLeft();
//			break;
//		case EventListener::Event::POWERUP:
//			Player->IncreasePower();
//			break;
//		case EventListener::Event::POWERDOWN:
//			Player->DecreasePower();
//			break;
//		case EventListener::Event::SPACE:
//			addBall = true;
//			break;
//		}
//	};
//
//	void AddCannonBall(Renderer & r)
//	{
//		Objects.push_back(new Cannonball(BoxWorld.getWorld(), r, Player));
//		addBall = false;
//		
//	};
//
//	virtual bool GetQuit() 
//	{ 
//		return quit; 
//	};
//};
>>>>>>> 76cf6dede36c88d0b9a698f9b7638c00449021db
