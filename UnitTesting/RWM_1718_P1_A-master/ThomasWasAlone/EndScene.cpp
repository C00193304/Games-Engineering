#include "EndScene.h"

EndScene::EndScene(Renderer& renderer)
{
	quit = false;

	if (!Image.Init("Assets/Screen/EndGame.png", renderer, Rect(0, 0, 1600, 1600), Rect(0, 0, 800, 600)))
	{
		cout << "Failed to load Sprite... " << endl;
	}

	TTF_Init();

	// Font set up and background/foreground colour
	Font = TTF_OpenFont("Assets/Fonts/INFROMAN.TTF", 100);
	SDL_Color bg = { 84, 132, 255 };
	SDL_Color fg = { 173, 173, 173 };

	// First Text
	TextSurface_01 = TTF_RenderText(Font, "Press 'q' to quit!", fg, bg);
	Text_01 = SDL_CreateTextureFromSurface(renderer.getRenderer(), TextSurface_01);

	Position_01.x = 300;
	Position_01.y = 220;
	Position_01.w = 200;
	Position_01.h = 80;

	// Second Text
	TextSurface_02 = TTF_RenderText(Font, "Press any other key to return to start!", fg, bg);
	Text_02 = SDL_CreateTextureFromSurface(renderer.getRenderer(), TextSurface_02);

	Position_02.x = 200;
	Position_02.y = 300;
	Position_02.w = 400;
	Position_02.h = 80;

	inputManager.AddListener(EventListener::Event::QUITEND, this);
	inputManager.AddListener(EventListener::Event::QUIT, this);
	inputManager.AddListener(EventListener::Event::AnyKey, this);

	KeyReleased = false;
	KeyPressed = false;

}

void EndScene::Draw(Renderer& renderer)
{
	Image.Render(renderer);
	SDL_RenderCopy(renderer.getRenderer(), Text_01, NULL, &Position_01);
	SDL_RenderCopy(renderer.getRenderer(), Text_02, NULL, &Position_02);
}

void EndScene::Event()
{
	inputManager.ProcessInput();
}

void EndScene::onEvent(EventListener::Event evt)
{
	if (!quit)
	{
		switch (evt) {
		case EventListener::Event::QUITEND:
			quit = true;
			break;
		case EventListener::Event::QUIT:
			quit = true;
			break;
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
		}
	}

	if (KeyReleased)
	{
		KeyReleased = false;
		KeyPressed = false;
		SceneManager::ChangeStates(SceneManager::start);
	}
}