#include "Gate.h"

void Gate::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Gate::handleCollision(King&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Gate::handleCollision(Mage&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Gate::handleCollision(Warrior&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Gate::handleCollision(Thief& thief)
{
	if (thief.hasKey())
	{
		m_collision = Collisions::GATE;
		thief.setKey();
	}
	else
		m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Gate::handleCollision(Gnome&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}