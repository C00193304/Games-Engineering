#include "UIText.h"


UIText::UIText(int x, int y, int w, int h, string word, Renderer &r)
{

	m_messageRect.x = x;
	m_messageRect.y = y;
	m_messageRect.w = w;
	m_messageRect.h = h;

	m_word = word;

	if (TTF_Init() == -1)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
	}
	m_font = TTF_OpenFont("Assets/Fonts/font.TTF", 24);
	if (!m_font)
	{
		cout << "Failed to load font" << endl;
	}
	m_colour = SDL_Color{ 255, 255, 255 };
	m_surfaceMessage = TTF_RenderText_Solid(m_font, m_word.c_str(), m_colour);
	m_message = SDL_CreateTextureFromSurface(r.getRenderer(), m_surfaceMessage);
}

void UIText::Render(Renderer & r)
{

	m_surfaceMessage = TTF_RenderText_Solid(m_font, m_word.c_str(), m_colour);
	m_message = SDL_CreateTextureFromSurface(r.getRenderer(), m_surfaceMessage);
	
	SDL_RenderCopy(r.getRenderer(), m_message, NULL, &m_messageRect);
}


void UIText::Update(unsigned int deltaTime)
{

}

void UIText::Update(string word)
{
	m_word = word;
}

bool UIText::CheckEvents()
{
	return false;
}
