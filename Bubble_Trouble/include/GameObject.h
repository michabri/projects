#pragma once
#include "macros.h"
#include "ContactListener.h"

class GameObject 
{
public:
	GameObject() = default;
	virtual void setLocation(const sf::Vector2f& loc);
	virtual sf::Vector2f getLocation() const;
	sf::Sprite getSprite() const;
	virtual void draw(sf::RenderWindow& window) const;
	b2Body& getBody() const;
	int getId() const;
	virtual ~GameObject() = default;

protected:
	sf::Sprite m_sprite; 
	b2Body* m_body;
	b2Fixture* m_fixture;
};