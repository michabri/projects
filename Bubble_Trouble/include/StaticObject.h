#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual int getValue() const = 0;
	virtual bool updateObj();
	virtual void restartTimer() {}

protected:
	sf::RectangleShape m_obj;
};