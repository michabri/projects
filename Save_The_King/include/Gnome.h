#pragma once
#include "MovingObject.h"

class Gnome : public MovingObject
{
public:
	Gnome(sf::Vector2f loc, const sf::Texture* texture);
	virtual void setDirection(const sf::Keyboard::Key& key) override;
	virtual void handleCollision(const GameObject& character) override;
	
private:
};