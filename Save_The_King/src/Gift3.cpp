#include "Gift3.h"

void Gift3::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Gift3::handleCollision(King& )
{
	m_collision = Collisions::GIFT3;
}
//-------------------------------------------------------------------------
void Gift3::handleCollision(Mage& )
{
	m_collision = Collisions::GIFT3;
}
//-------------------------------------------------------------------------
void Gift3::handleCollision(Warrior& )
{
	m_collision = Collisions::GIFT3;
}
//-------------------------------------------------------------------------
void Gift3::handleCollision(Thief& )
{
	m_collision = Collisions::GIFT3;
}
//-------------------------------------------------------------------------
void Gift3::handleCollision(Gnome& )
{
	m_collision = Collisions::NO_COLLISION;
}