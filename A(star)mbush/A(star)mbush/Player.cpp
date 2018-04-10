#include "Player.h"

Player::Player(SDL_Point position, int width, int height, SDL_Color colour, EventListener * evtListener)
{
	m_position = position;
	m_rect.x = position.x;
	m_rect.y = position.y;
	m_rect.w = width;
	m_rect.h = height;
	m_colour = colour;
	m_eventListener = evtListener;
}

void Player::setSpeed(float x, float y)
{
	m_velocity.x = x;
	m_velocity.y = y;
}

void Player::update(float dTime)
{
	if (m_eventListener->up)
	{
		m_velocity.y = -100 * dTime;
	}
	if (m_eventListener->down)
	{
		m_velocity.y = 100 * dTime;
	}
	if (m_eventListener->left)
	{
		m_velocity.x = -100 * dTime;
	}
	if (m_eventListener->right)
	{
		m_velocity.x = 100 * dTime;
	}

	m_position.x = m_position.x + m_velocity.x;
	m_position.y = m_position.y + m_velocity.y;
	m_rect.x = m_position.x;
	m_rect.y = m_position.y;
}
