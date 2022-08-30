#include "Gift2.h"

void Gift2::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Gift2::handleCollision(King& )
{
	m_collision = Collisions::GIFT2;
}
//-------------------------------------------------------------------------
void Gift2::handleCollision(Mage& )
{
	m_collision = Collisions::GIFT2;
}
//-------------------------------------------------------------------------
void Gift2::handleCollision(Warrior& )
{
	m_collision = Collisions::GIFT2;
}
//-------------------------------------------------------------------------
void Gift2::handleCollision(Thief& )
{
	m_collision = Collisions::GIFT2;
}
//-------------------------------------------------------------------------
void Gift2::handleCollision(Gnome& )
{
	m_collision = Collisions::NO_COLLISION;
}