#include "StartScene.h"

StartScene::StartScene()
{
	input.AddListener(EventListener::Event::POWERDOWN, this);
	input.AddListener(EventListener::Event::POWERUP, this);
	input.AddListener(EventListener::Event::SPACE, this);
}

StartScene::~StartScene()
{

}

void StartScene::Init()
{

}

void StartScene::Init(Renderer &r)
{

	Size.pos.x = 0;
	Size.pos.y = 0;
	Size.size.h = 600;
	Size.size.w = 800;
	BackgroundSprite.Init("Assets/Images/BackgroundMenu.png", r, Rect(0, 0, 800, 600), Size);

	//add button to button list set start button as selected
	buttonList.push_back(new Button(350, 285, 100, 30, "Start Game", r));
	buttonList.push_back(new Button(350, 365, 100, 30, "Quit", r));

	maxButtons = buttonList.size();
}

void StartScene::Draw(Renderer &r)
{
	BackgroundSprite.Render(r);
	//draw buttons change
	for (int i = 0; i < buttonList.size(); i++)
	{
		if (i == currentbutton)
		{
			buttonList.at(i)->Render(r, true);
		}
		else
		{
			buttonList.at(i)->Render(r, false);
		}
	}
}

void StartScene::Update(unsigned int dt)
{
	
}

void StartScene::Event()
{
	input.ProcessInput();
}

void StartScene::onEvent(EventListener::Event evt)
{
	switch (evt)
	{
	case EventListener::Event::QUIT:
		quit = true;
		break;
	case EventListener::Event::POWERDOWN:
		//change button selection
		currentbutton++;
		cout << "incrementing currenbutton: " <<currentbutton << endl;
		if (currentbutton >= maxButtons)
		{
			currentbutton = 0;
			cout << "wrapping button to 0" << endl;
		}
		break;
	case EventListener::Event::POWERUP:
		//change button selection
		currentbutton--;
		cout << "decrementing currenbutton: " << currentbutton << endl;
		if (currentbutton < 0)
		{
			cout << "wrapping button to " << maxButtons << endl;
			currentbutton = maxButtons - 1;
		}
		break;
	case EventListener::Event::SPACE:
		//if statement that changes scene to level or quits the game
		if (currentbutton == 0)
		{
			//go to level 1
			complete = true;
			cout << "Start Game pressed" << endl;
		}
		else if (currentbutton == 1)
		{
			quit = true;
			cout << "Quit pressed" << endl;
		}
		break;
	}
}

bool StartScene::GetQuit()
{
	return quit;
}

bool StartScene::GetCompleted()
{
	return complete;
}