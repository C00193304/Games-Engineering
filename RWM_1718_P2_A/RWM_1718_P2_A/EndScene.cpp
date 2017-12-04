#include "EndScene.h"

EndScene::EndScene()
{
	input.AddListener(EventListener::Event::POWERDOWN, this);
	input.AddListener(EventListener::Event::POWERUP, this);
	input.AddListener(EventListener::Event::SPACE, this);
}

EndScene::~EndScene()
{

}

void EndScene::Init()
{
}

void EndScene::Init(Renderer &r)
{

	Size.pos.x = 0;
	Size.pos.y = 0;
	Size.size.h = 600;
	Size.size.w = 800;
	BackgroundSprite.Init("Assets/Images/BackgroundMenu.png", r, Rect(0, 0, 800, 600), Size);

	//add button to button list set start button as selected
	buttonList.push_back(new Button(350, 285, 100, 30, "Back To Menu", r));
	buttonList.push_back(new Button(350, 365, 100, 30, "Quit", r));
	ui = new UIText(350, 100, 100, 50, "YOU WIN!!!", r);


	maxButtons = buttonList.size();
}

void EndScene::Draw(Renderer &r)
{
	

	BackgroundSprite.Render(r);
	ui->Render(r);
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

void EndScene::Update(unsigned int dt)
{

}

void EndScene::Event()
{
	input.ProcessInput();
}

void EndScene::onEvent(EventListener::Event evt)
{
	switch (evt)
	{
	case EventListener::Event::QUIT:
		quit = true;
		break;
	case EventListener::Event::POWERDOWN:
		//change button selection
		currentbutton++;
		cout << "incrementing currenbutton: " << currentbutton << endl;
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

bool EndScene::GetQuit()
{
	return quit;
}

bool EndScene::GetCompleted()
{
	return complete;
}