#include "GameObject.h"

//-------------------------------------------------------------------------
GameObject::GameObject(const sf::Vector2f& loc, const sf::Texture* texture)
	:m_sprite(*texture)
{
	m_sprite.setPosition(loc);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
}
//-------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//-------------------------------------------------------------------------
bool GameObject::checkCollision(const GameObject& other)
{
	if (&other == this)
		return false;
	return (m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds()));
}
//-------------------------------------------------------------------------
void GameObject::setSpriteScale(const float& new_width_sclae, const float& new_height_sclae)
{
	m_sprite.setScale(new_width_sclae, new_height_sclae);
}
//-------------------------------------------------------------------------
const sf::Vector2f& GameObject::getLocation() const
{
	return m_sprite.getPosition();
}
//-------------------------------------------------------------------------
void GameObject::setLocation(const sf::Vector2f& location)
{
	m_sprite.setPosition(location);
}
//-------------------------------------------------------------------------
sf::FloatRect GameObject::getGlobalBoundsSprite() const
{
	return m_sprite.getGlobalBounds();
}
//-------------------------------------------------------------------------
sf::Vector2f GameObject::getScaleSprite() const
{
	return m_sprite.getScale();
}
//-------------------------------------------------------------------------
void GameObject::setTexture(const sf::Texture* texture)
{
	m_sprite.setTexture(*texture);
}