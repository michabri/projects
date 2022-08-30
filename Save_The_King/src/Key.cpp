#include "Key.h"

void Key::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Key::handleCollision(King&)
{
	m_collision = Collisions::NO_COLLISION;
}
//-------------------------------------------------------------------------
void Key::handleCollision(Mage&)
{
	m_collision = Collisions::NO_COLLISION;
}
//-------------------------------------------------------------------------
void Key::handleCollision(Warrior&)
{
	m_collision = Collisions::NO_COLLISION;
}
//-------------------------------------------------------------------------
void Key::handleCollision(Thief& thief)
{
	if (!thief.hasKey())
	{
		m_collision = Collisions::KEY;
		thief.setKey();
	}
	else
		m_collision = Collisions::NO_COLLISION;
}
//-------------------------------------------------------------------------
void Key::handleCollision(Gnome&)
{
	m_collision = Collisions::NO_COLLISION;
}