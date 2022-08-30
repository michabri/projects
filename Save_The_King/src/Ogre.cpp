#include "Ogre.h"

void Ogre::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
void Ogre::handleCollision(King&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Ogre::handleCollision(Mage&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Ogre::handleCollision(Warrior&)
{
	m_collision = Collisions::OGRE;
}
//-------------------------------------------------------------------------
void Ogre::handleCollision(Thief&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}
//-------------------------------------------------------------------------
void Ogre::handleCollision(Gnome&)
{
	m_collision = Collisions::REGULAR_COLLISION;
}