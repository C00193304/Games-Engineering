#include "Level1.h"

Level1::Level1()
{
	//Quit
	quit = false;

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

//initialise player and all gameObjects
void Level1::init()
{
	cout << "initialising level" << endl;

	// Create Player
	player = new Player(Rect(400, 400, 20, 39));
	player->SetColour(Colour(255, 162, 76));

	GameObjects.clear();

	// Create obstacles
	Box* test = new Box(Rect(0, 540, 800, 60));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(-100, 0, 100, 600));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	test = new Box(Rect(800, 0, 100, 600));
	test->SetColour(Colour(0, 0, 0, 255));
	GameObjects.push_back(test);

	Gate* gate = new Gate(Rect(200, 500, 20, 40));

	GameObjects.push_back(gate);
}

//Scene draw
void Level1::Draw(Renderer& renderer)
{
	for (std::vector<GameObject*>::iterator i = GameObjects.begin(), e = GameObjects.end(); i != e; i++) 
	{
		(*i)->Render(renderer);
	}

	player->Render(renderer);

}

//Scene input
void Level1::Event()
{
	inputManager.ProcessInput();
}

//Scene update
void Level1::Update(unsigned int DeltaTime)
{
	Rect tempRect;
	player->Update(DeltaTime);
	//go through every gameobject in the scene
	for (std::vector<GameObject*>::iterator i = GameObjects.begin(), e = GameObjects.end(); i != e; i++)
	{
		tempRect = (*i)->getRect();
		player->CheckCollision(*i);
		//if play collides with gate reset this scene and go to the next scene
		if ((*i)->GetType() == "Gate")
		{
			if (CheckCenter(player->GetRect(), (*i)->getRect()))
			{
				init();
				SceneManager::ChangeStates(SceneManager::level2);
				//if something goes wrong break to stop iteration over a reset vector.
				break;
			}
		}
	}
}


void Level1::onEvent(EventListener::Event evt)
{
	switch (evt) 
	{
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
	case EventListener::Event::SPACE:
		player->SpacePressed();
		player->jumpReleased = false;
		break;
	case EventListener::Event::SPACER:
		player->jump = false;
		player->jumpReleased = true;
		break;
	case EventListener::Event::QUIT:
		quit = true;
		break;
	}
}

bool Level1::GetQuit()
{
	return quit;
}

//method use for checking player center collision with the gate or respawn region origin
bool Level1::CheckCenter(Rect player, Rect gate)
{
	Point2D center1;
	Point2D center2;
	Point2D length;
	//get scenter of player
	center2.x = player.pos.x + (player.size.w / 2);
	center2.y = player.pos.y + (player.size.h / 2);

	//get center of object
	center1.x = gate.pos.x + (gate.size.w / 2);
	center1.y = gate.pos.y + (gate.size.h / 2);

	//Get the distance between the two centers
	length.x = center2.x - center1.x;
	length.y = center2.y - center1.y;

	//if the length is less than half the width/height of the object(If the player center is inside the object
	if (abs(length.x) < (gate.size.w / 2) && abs(length.y) < (gate.size.h / 2))
	{
		return true;
	}
	return false;
}