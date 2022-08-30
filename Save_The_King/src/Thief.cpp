#include "Thief.h"

//-------------------------------------------------------------------------
void Thief::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}
//-------------------------------------------------------------------------
bool Thief::hasKey() const
{
	return m_key;
}
//-------------------------------------------------------------------------
void Thief::setKey()
{
	m_key = !m_key;
}