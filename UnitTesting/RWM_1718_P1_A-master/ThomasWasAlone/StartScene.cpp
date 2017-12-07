#include "StartScene.h"

StartScene::StartScene(Renderer& renderer)
{
	if (!Image.Init("Assets/Screen/Start.png", renderer, Rect(0, 0, 1600, 1600), Rect(0, 0, 800, 600)))
	{
		cout << "Failed to load Sprite... " << endl;
	}

	TTF_Init();

	Font = TTF_OpenFont("Assets/Fonts/INFROMAN.TTF", 100);
	SDL_Color bg = { 255, 255, 255};
	SDL_Color fg = { 0,0,0 };
	TextSurface = TTF_RenderText(Font, "Press Any Button", fg, bg);
	Text = SDL_CreateTextureFromSurface(renderer.getRenderer(), TextSurface);

	Position.x = 250;
	Position.y = 520;
	Position.w = 300;
	Position.h = 80;

	init();

	KeyPressed = true;
	KeyReleased = false;

	inputManager.AddListener(EventListener::Event::AnyKey, this);
	inputManager.AddListener(EventListener::Event::QUIT, this);
}

void StartScene::init()
{
	quit = false;
}

void StartScene::Event()
{
	inputManager.ProcessInput();
}

void StartScene::Update(unsigned int DeltaTime)
{
}

void StartScene::Draw(Renderer& renderer)
{
	Image.Render(renderer);
	SDL_RenderCopy(renderer.getRenderer(), Text, NULL, &Position);
}

void StartScene::onEvent(EventListener::Event evt)
{
	switch (evt) 
	{
	case EventListener::Event::AnyKey:
		if (KeyPressed)
		{
			KeyReleased = true;
		}
		else
		{
			KeyPressed = true;
		}
		break;
	case EventListener::Event::QUIT:
		quit = true;
		break;
	}

	if (KeyReleased)
	{
		KeyPressed = true;
		KeyReleased = false;
		init();
		SceneManager::ChangeStates(SceneManager::level1);
	}
}