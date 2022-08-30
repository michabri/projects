#include "StaticObject.h"

//=======================================================================================
bool StaticObject::updateObj()
{
	auto position = m_body->GetPosition();
	m_obj.setPosition(position.x, position.y);
	return true;
}