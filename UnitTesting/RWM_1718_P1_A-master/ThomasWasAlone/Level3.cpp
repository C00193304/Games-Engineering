#include "Level3.h"

Level3::Level3()
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
	inputManager.AddListener(EventListener::Event::QUIT, this);
}

void Level3::init()
{
	// Create Player
	player = new Player(Rect(100, 100, 20, 39));
	player->SetColour(Colour(255, 162, 76));

	// Portal
	Gate* gate = new Gate(Rect(700, 500, 20, 40));
	GameObjects.push_back(gate);

	// Create obstacles
	Box* test = new Box(Rect(0, 540, 800, 60)); // Ground
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(0, 140, 400, 40));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(0, 180, 450, 40));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(550, 180, 250, 100));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(400, 280, 400, 20));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(0, 220, 300, 80));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(0, 300, 200, 60));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(250, 360, 300, 40));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(200, 400, 350, 40));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(280, 440, 270, 40));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(0, 360, 100, 120));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(0, 480, 220, 60));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(650, 300, 150, 180));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(750, 480, 50, 60));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(-100, 0, 100, 600));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(800, 0, 100, 600));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	// Ground
	test = new Box(Rect(-10, -10, 20, 2));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);
}

void Level3::Draw(Renderer& renderer)
{
	for (std::vector<GameObject*>::iterator i = GameObjects.begin(), e = GameObjects.end(); i != e; i++) {
		(*i)->Render(renderer);
	}

	player->Render(renderer);
}

void Level3::Event()
{
	inputManager.ProcessInput();
}

void Level3::Update(unsigned int DeltaTime)
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
				SceneManager::ChangeStates(SceneManager::level4);
				//reset this scene.
				//go to next scene.
				break;
			}
		}
	}
}

void Level3::onEvent(EventListener::Event evt)
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
	case EventListener::Event::LEFTR:
		player->left = false;
		player->leftReleased = true;
		break;
	case EventListener::Event::QUIT:
		quit = true;
		break;
	}
}

bool Level3::GetQuit()
{
	return quit;
}

bool Level3::CheckCenter(Rect player, Rect gate)
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