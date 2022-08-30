#include "Weapon.h"

//=======================================================================================
void Weapon::setActivate()
{
	m_isActive = true;
}
//=======================================================================================
bool Weapon::isActive() const
{
	return m_isActive;
}
//=======================================================================================
void Weapon::forceEnd()
{
	m_isActive = false;
	m_isWeaponPosSet = false;
	m_body->SetTransform(b2Vec2(-2 * STATIC_OBJECT_SIZE_PIXEL, 3 * WINDOW_HEIGHT), m_body->GetAngle());
}
//=======================================================================================
void Weapon::draw(sf::RenderWindow& window) const
{
	window.draw(m_obj);
}
//=======================================================================================
void Weapon::setCountDown(const float& cd)
{
	m_count_down = cd;
}