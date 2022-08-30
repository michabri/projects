#include "Wall.h"

void Wall ::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Wall::handleCollision(King&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Wall::handleCollision(Mage&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Wall::handleCollision(Warrior&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Wall::handleCollision(Thief&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Wall::handleCollision(Gnome&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}