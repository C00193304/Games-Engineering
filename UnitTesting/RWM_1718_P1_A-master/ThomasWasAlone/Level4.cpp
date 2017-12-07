#include "Level4.h"

Level4::Level4()
{
	//Quit
	quit = false;

	// Get aspect ratio of screen
	float aspect = WIDTH / HEIGHT;

	init();

	//input manager events
	inputManager.AddListener(EventListener::Event::LEFT, this);
	inputManager.AddListener(EventListener::Event::LEFTR, this);
	inputManager.AddListener(EventListener::Event::RIGHT, this);
	inputManager.AddListener(EventListener::Event::RIGHTR, this);
	inputManager.AddListener(EventListener::Event::SPACE, this);
	inputManager.AddListener(EventListener::Event::SPACER, this);
	inputManager.AddListener(EventListener::Event::QUIT, this);
}

void Level4::init()
{
	// Create Player
	player = new Player(Rect(100, 500, 20, 39));
	player->SetColour(Colour(255, 162, 76));

	GameObjects.clear();

	// Create obstacles
	Box* test = new Box(Rect(0, 540, 800, 60));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(250, 450, 100, 90));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(650, 345, 150, 105));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(550, 450, 250, 20));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(-100, 0, 100, 600));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(800, 0, 100, 600));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	Gate* gate = new Gate(Rect(750, 500, 20, 40));

	GameObjects.push_back(gate);
}

void Level4::Draw(Renderer& renderer)
{
	for (std::vector<GameObject*>::iterator i = GameObjects.begin(), e = GameObjects.end(); i != e; i++) {
		(*i)->Render(renderer);
	}

	player->Render(renderer);
}

void Level4::Event()
{
	inputManager.ProcessInput();
}

void Level4::Update(unsigned int DeltaTime)
{
	Rect tempRect;
	player->Update(DeltaTime);
	for (std::vector<GameObject*>::iterator i = GameObjects.begin(), e = GameObjects.end(); i != e; i++)
	{
		tempRect = (*i)->getRect();
		player->CheckCollision(*i);
		if ((*i)->GetType() == "Gate")
		{
			if (CheckCenter(player->GetRect(), (*i)->getRect()))
			{
				init();
				SceneManager::ChangeStates(SceneManager::level5);
				//reset this scene.
				//go to next scene.
				break;
			}
		}
	}
}

void Level4::onEvent(EventListener::Event evt)
{
	switch (evt) {
	case EventListener::Event::RIGHT:
		player->right = true;
		break;
	case EventListener::Event::LEFT:
		player->left = true;
		break;
	case EventListener::Event::RIGHTR:
		player->right = false;
		player->rightReleased = true;
		break;
	case EventListener::Event::SPACE:
		player->SpacePressed();
		player->jumpReleased = false;
		break;
	case EventListener::Event::SPACER:
		player->jump = false;
		player->jumpReleased = true;
		break;
	case EventListener::Event::LEFTR:
		player->left = false;
		player->leftReleased = true;
		break;
	case EventListener::Event::QUIT:
		quit = true;
		break;
	}
}

bool Level4::GetQuit()
{
	return quit;
}

bool Level4::CheckCenter(Rect player, Rect gate)
{
	Point2D center1, center2, length;

	center2.x = player.pos.x + (player.size.w / 2);
	center2.y = player.pos.y + (player.size.h / 2);

	center1.x = gate.pos.x + (gate.size.w / 2);
	center1.y = gate.pos.y + (gate.size.h / 2);

	length.x = center2.x - center1.x;
	length.y = center2.y - center1.y;

	if (abs(length.x) < (gate.size.w / 2) && abs(length.y) <(gate.size.h / 2))
	{
		return true;
	}
	return false;
}