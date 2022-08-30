#include "Gift1.h"

void Gift1::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Gift1::handleCollision(King&)
{
	m_collision = Collisions::GIFT1;
}
//-------------------------------------------------------------------------
void Gift1::handleCollision(Mage&)
{
	m_collision = Collisions::GIFT1;
}
//-------------------------------------------------------------------------
void Gift1::handleCollision(Warrior&)
{
	m_collision = Collisions::GIFT1;
}
//-------------------------------------------------------------------------
void Gift1::handleCollision(Thief&)
{
	m_collision = Collisions::GIFT1;
}
//-------------------------------------------------------------------------
void Gift1::handleCollision(Gnome&)
{
	m_collision = Collisions::NO_COLLISION;
}