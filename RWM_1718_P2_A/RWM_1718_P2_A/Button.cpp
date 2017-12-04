#include "Button.h"

Button::Button(int x, int y, int w, int h, string word, Renderer &r)
{
	

	m_boxRect = Rect(x, y, w, h);

	m_messageRect.x = m_boxRect.pos.x;
	m_messageRect.y = m_boxRect.pos.y;
	m_messageRect.w = m_boxRect.size.w;
	m_messageRect.h = m_boxRect.size.h;

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
	m_selectColour = SDL_Color{40, 105, 205};
	m_surfaceMessage =  TTF_RenderText_Solid(m_font, m_word.c_str(), m_colour);
	m_message = SDL_CreateTextureFromSurface(r.getRenderer(), m_surfaceMessage);
	if (!m_sprite.Init("Assets/Images/Button.png", r, Rect(0, 0, 255, 255), m_boxRect));
	{
		cout << "Failed to load button sprite" << endl;
	}
}

void Button::Render(Renderer & r)
{
	m_sprite.Render(r);
	SDL_RenderCopy(r.getRenderer(), m_message, NULL, &m_messageRect);
	
}
	
void Button::Render(Renderer & r, bool isSelected)
{
	if (isSelected)
	{
		m_surfaceMessage = TTF_RenderText_Solid(m_font, m_word.c_str(), m_selectColour);
		m_message = SDL_CreateTextureFromSurface(r.getRenderer(), m_surfaceMessage);
	}
	else
	{
		m_surfaceMessage = TTF_RenderText_Solid(m_font, m_word.c_str(), m_colour);
		m_message = SDL_CreateTextureFromSurface(r.getRenderer(), m_surfaceMessage);
	}
	m_sprite.Render(r);
	SDL_RenderCopy(r.getRenderer(), m_message, NULL, &m_messageRect);
}


void Button::Update(unsigned int deltaTime)
{

}

bool Button::CheckEvents()
{
	return false;
}
