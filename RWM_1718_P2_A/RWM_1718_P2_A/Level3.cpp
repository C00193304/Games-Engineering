#include "Level3.h"

void HandleCollision(GameObject*, string);

Level3::Level3()
{
	Player = new Cannon(BoxWorld.getWorld());
	reset = false;
	input.AddListener(EventListener::Event::QUIT, this);
	input.AddListener(EventListener::Event::RIGHT, this);
	input.AddListener(EventListener::Event::LEFT, this);
	input.AddListener(EventListener::Event::POWERUP, this);
	input.AddListener(EventListener::Event::POWERDOWN, this);
	input.AddListener(EventListener::Event::SPACE, this);
	input.AddListener(EventListener::Event::RESET, this);
}

Level3::~Level3()
{

}

void Level3::Init(Renderer& r)
{
	if (Objects.size() > 0)
	{
		Objects.clear();
	}

	if (UIList.size() > 0)
	{
		UIList.clear();
	}
	UIList.push_back(new UIText(0, 0, 100, 26, "POWER: 0", r));
	UIList.push_back(new UIText(0, 40, 100, 26, "ANGLE: 0", r));

	BoxWorld.Init();
	reset = false;
	quit = false;
	complete = false;

	Player = new Cannon(r);
	ballcounter = 0;

	addBall = false;

	for (int i = 0; i < GameData::m_maxGameObjects; i++)
	{
		if (GameData::m_gameObjectVector.at(i).type == "Ground")
		{
			Objects.push_back(new Ground(BoxWorld.getWorld(), r,
				Rect(GameData::m_gameObjectVector.at(i).X, GameData::m_gameObjectVector.at(i).Y,
					GameData::m_gameObjectVector.at(i).Width, GameData::m_gameObjectVector.at(i).Height)));
		}
		if (GameData::m_gameObjectVector.at(i).type == "Wall")
		{
			Objects.push_back(new Wall(BoxWorld.getWorld(), r,
				Rect(GameData::m_gameObjectVector.at(i).X, GameData::m_gameObjectVector.at(i).Y,
					GameData::m_gameObjectVector.at(i).Width, GameData::m_gameObjectVector.at(i).Height)));
		}
		else if (GameData::m_gameObjectVector.at(i).type == "Rocket")
		{
			Rocket* temp = new Rocket(BoxWorld.getWorld(), r, b2Vec2(GameData::m_gameObjectVector.at(i).X, GameData::m_gameObjectVector.at(i).Y));
			temp->SetActive(true);
			Objects.push_back(temp);
		}
		else if (GameData::m_gameObjectVector.at(i).type == "Windmill")
		{
			Objects.push_back(new Windmill(BoxWorld.getWorld(), r,
				Rect(GameData::m_gameObjectVector.at(i).X, GameData::m_gameObjectVector.at(i).Y,
					GameData::m_gameObjectVector.at(i).Width, GameData::m_gameObjectVector.at(i).Height)));
		}
		else if (GameData::m_gameObjectVector.at(i).type == "Goal")
		{
			Objects.push_back(new Goal(BoxWorld.getWorld(), r,
				Rect(GameData::m_gameObjectVector.at(i).X, GameData::m_gameObjectVector.at(i).Y,
					GameData::m_gameObjectVector.at(i).Width, GameData::m_gameObjectVector.at(i).Height)));
		}
	}
}

void Level3::Draw(Renderer& r)
{
	Player->Render(r);

	if (addBall && ballcounter < 3)
	{
		AddCannonBall(r);
		ballcounter++;
		//particles->Render(r);
	}
	for (int i = 0; i < Objects.size(); i++)
	{
		Objects.at(i)->Render(r);
	}

	for (int i = 0; i < UIList.size(); i++)
	{
		UIList.at(i)->Render(r);
	}

	if (reset)
	{
		this->Init(r);
	}
}


void Level3::Update(unsigned int dt)
{

	for (int i = 0; i < Objects.size(); i++)
	{
		Objects.at(i)->Update(dt);
	}
	Player->Update(dt);

	BoxWorld.Update(Objects);
	UIList.at(0)->Update(string("POWER: " + to_string(Player->GetPower())));
	UIList.at(1)->Update(string("ANGLE: " + to_string(Player->GetAngle())));
	complete = BoxWorld.getLevelComplete();
}

void Level3::Event()
{
	input.ProcessInput();
}

void Level3::onEvent(EventListener::Event evt)
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
		addBall = true;
		break;
	case EventListener::Event::RESET:
		reset = true;
		break;
	}
}

void Level3::AddCannonBall(Renderer & r)
{
	Objects.push_back(new Particles(BoxWorld.getWorld(), Player, 100));
	Objects.push_back(new Cannonball(BoxWorld.getWorld(), r, Player));
	addBall = false;
}

bool Level3::GetQuit()
{
	return quit;
}

bool Level3::GetCompleted()
{
	return complete;
}