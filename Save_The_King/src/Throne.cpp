#include "Throne.h"

void Throne::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Throne::handleCollision(King&)
{
	m_collision = Collisions::WON;
}
//-------------------------------------------------------------------------
void Throne::handleCollision(Mage&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Throne::handleCollision(Warrior&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Throne::handleCollision(Thief&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Throne::handleCollision(Gnome&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}