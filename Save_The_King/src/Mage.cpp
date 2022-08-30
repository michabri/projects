#include "Mage.h"

//-------------------------------------------------------------------------
void Mage::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}