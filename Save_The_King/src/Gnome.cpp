#include "Gnome.h"

//-------------------------------------------------------------------------
Gnome::Gnome(sf::Vector2f loc, const sf::Texture* texture)
	:MovingObject(loc, texture)
{
	m_speed_per_second = 200.f;
}
//-------------------------------------------------------------------------
void Gnome::setDirection(const sf::Keyboard::Key&)
{
	int direction = rand() % 4;
	switch (direction)
	{
	case 0://up
		m_direction = sf::Vector2f(0, -1); 
		break;
	case 1://left
	{
		m_direction = sf::Vector2f(-1, 0);
		if (m_right_pressed)
		{
			(*this).rotateSprite(-1, 1);
			m_right_pressed = false;
		}
		break;
	}
	case 2://down
		m_direction = sf::Vector2f(0, 1); 
		break;
	case 3://right
	{
		m_direction = sf::Vector2f(1, 0);
		if (!m_right_pressed)
		{
			(*this).rotateSprite(-1, 1);
			m_right_pressed = true;
		}
		break;
	}
	}
}
//-------------------------------------------------------------------------
void Gnome::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}