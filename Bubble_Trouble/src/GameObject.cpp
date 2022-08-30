#include "GameObject.h"

//=======================================================================================
void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//=======================================================================================
sf::Vector2f GameObject::getLocation() const
{
	return m_sprite.getPosition();
}
//=======================================================================================
void GameObject::setLocation(const sf::Vector2f& loc)
{
	m_sprite.setPosition(loc);
	m_body->SetTransform(b2Vec2(loc.x, loc.y), m_body->GetAngle());
}
//=======================================================================================
sf::Sprite GameObject::getSprite() const
{
	return m_sprite;
}
//=======================================================================================
b2Body& GameObject::getBody() const
{
	return *m_body;
}
//=======================================================================================
int GameObject::getId() const
{
	return m_fixture->GetFilterData().groupIndex;
}