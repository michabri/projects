#pragma once
#include "GameObject.h"

class MovingObject : public GameObject 
{
public:
	using GameObject::GameObject;
	void setDirection(const sf::Keyboard::Key& key);

protected:
	sf::Vector2f m_direction; 
	sf::Vector2f m_lastDirection; 
};