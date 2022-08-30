#include "Teleport.h"

void Teleport::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Teleport::handleCollision(King& )
{
	m_collision = Collisions::TELEPORT;
}
//-------------------------------------------------------------------------
void Teleport::handleCollision(Mage& )
{
	m_collision = Collisions::NO_COLLISION;
}
//-------------------------------------------------------------------------
void Teleport::handleCollision(Warrior& )
{
	m_collision = Collisions::TELEPORT;
}
//-------------------------------------------------------------------------
void Teleport::handleCollision(Thief& )
{
	m_collision = Collisions::TELEPORT;
}
//-------------------------------------------------------------------------
void Teleport::handleCollision(Gnome& )
{
	m_collision = Collisions::TELEPORT;
}