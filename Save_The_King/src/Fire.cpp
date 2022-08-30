#include "Fire.h"

void Fire::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Fire::handleCollision(King&) 
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Fire::handleCollision(Mage&) 
{
	m_collision = Collisions::FIRE;
}
//-------------------------------------------------------------------------
void Fire::handleCollision(Warrior&) 
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Fire::handleCollision(Thief&) 
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Fire::handleCollision(Gnome&) 
{
	m_collision = Collisions::REGULAR_COLLISION;
}

